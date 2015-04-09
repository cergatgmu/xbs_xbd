/**
 * @file
 * crypto_hash/try.c version 20140423
 * D. J. Bernstein
 * Public domain.
 * Auto-generated by trygen.py; do not edit.
 * Modified for XBX by John Pham from SUPERCOP as of 20150222
 *
 * Modifications: Split up a static buffer instead of using dynamic memory in
 * allocate function, which is renamed to test_allocate to prevent collisions.
 * restrict test to -DSMALL, remove functions from unused. Removed preallocate and
 * doit functions
 */

#include "crypto_aead.h"
#include "XBD_operation.h"
#include "try.h"
const char *primitiveimplementation = crypto_aead_IMPLEMENTATION;

/*
 * Only check checksumsmall, as checksumbig is too large for available memory
 * Thus, MAXTEST_BYTES = 128 and LOOPS=64
 */
//#define TUNE_BYTES 1536
//#ifdef SMALL
#define MAXTEST_BYTES 128
//#else
//#define MAXTEST_BYTES 4096
//#endif
//#ifdef SMALL
#define LOOPS 64
//#else
//#define LOOPS 512
//#endif


static unsigned char *k; //Key
static unsigned char *s; //Secret number
static unsigned char *p; //Public number
static unsigned char *a; //Assoc data
static unsigned char *m; //plaintext Message
static unsigned char *c; //Ciphertext
static unsigned char *t; //decrypted plainText
static unsigned char *r; //decrypted secRet number
static unsigned char *k2;
static unsigned char *s2;
static unsigned char *p2;
static unsigned char *a2;
static unsigned char *m2;
static unsigned char *c2;
static unsigned char *t2;
static unsigned char *r2;
#define klen crypto_aead_KEYBYTES
#define slen crypto_aead_NSECBYTES
#define plen crypto_aead_NPUBBYTES
static unsigned long long alen;
static unsigned long long mlen;
static unsigned long long clen;
static unsigned long long tlen;
#define rlen crypto_aead_NSECBYTES



/**
 * Chop up buffer into buffers for test
 * @param buf Buffer to use as scratch space for tests
 */
void test_allocate(unsigned char *buf) {
    k  = buf + CANARY_SZ;
    s  = k   + CANARY_SZ + MAX_KEYBYTES       + CANARY_SZ;
    p  = s   + CANARY_SZ + MAX_NSECBYTES      + CANARY_SZ;
    a  = p   + CANARY_SZ + MAX_NPUBBYTES      + CANARY_SZ;
    m  = a   + CANARY_SZ + MAX_TEST_AD_BYTES  + CANARY_SZ;
    c  = m   + CANARY_SZ + MAX_TEST_MSG_BYTES + CANARY_SZ;
    t  = c   + CANARY_SZ + MAX_TEST_MSG_BYTES + MAX_ABYTES + CANARY_SZ;
    r  = t   + CANARY_SZ + MAX_TEST_MSG_BYTES + CANARY_SZ;
    k2 = r   + CANARY_SZ + MAX_NSECBYTES      + CANARY_SZ;
    s2 = k2  + CANARY_SZ + MAX_KEYBYTES       + CANARY_SZ;
    p2 = s2  + CANARY_SZ + MAX_NSECBYTES      + CANARY_SZ;
    a2 = p2  + CANARY_SZ + MAX_NPUBBYTES      + CANARY_SZ;
    m2 = a2  + CANARY_SZ + MAX_TEST_AD_BYTES  + CANARY_SZ;
    c2 = m2  + CANARY_SZ + MAX_TEST_MSG_BYTES + CANARY_SZ;
    t2 = c2  + CANARY_SZ + MAX_TEST_MSG_BYTES + MAX_ABYTES + CANARY_SZ;
    r2 = t2  + CANARY_SZ + MAX_TEST_MSG_BYTES + CANARY_SZ;
         
    //Randomize contents
    for (size_t i = 0; i < MAX_TESTBUFFER_SIZE; i++){
        buf[i]=(unsigned char)(myrandom() & 0xFF);
    }
}


int test(void) {
    // Changed from long long; no need for 64 bit on a uC
    unsigned loop;

    if(!setjmp(test_fail_jmp)){
        for (loop = 0;loop < LOOPS;++loop) {
            mlen = myrandom() % (MAXTEST_BYTES + 1);
            alen = myrandom() % (MAXTEST_BYTES + 1);

            clen = mlen + crypto_aead_ABYTES;
            output_prepare(c2,c,clen);
            input_prepare(m2,m,mlen);
            input_prepare(a2,a,alen);
            input_prepare(s2,s,slen);
            input_prepare(p2,p,plen);
            input_prepare(k2,k,klen);
            if (crypto_aead_encrypt(c,&clen,m,mlen,a,alen,s,p,k) != 0) fail("crypto_aead_encrypt returns nonzero");
            if (clen < mlen) fail("crypto_aead_encrypt returns smaller output than input");
            if (clen > mlen + crypto_aead_ABYTES) fail("crypto_aead_encrypt returns more than crypto_aead_ABYTES extra bytes");
            checksum(c,clen);
            output_compare(c2,c,clen,"crypto_aead_encrypt");
            input_compare(m2,m,mlen,"crypto_aead_encrypt");
            input_compare(a2,a,alen,"crypto_aead_encrypt");
            input_compare(s2,s,slen,"crypto_aead_encrypt");
            input_compare(p2,p,plen,"crypto_aead_encrypt");
            input_compare(k2,k,klen,"crypto_aead_encrypt");

            double_canary(c2,c,clen);
            double_canary(m2,m,mlen);
            double_canary(a2,a,alen);
            double_canary(s2,s,slen);
            double_canary(p2,p,plen);
            double_canary(k2,k,klen);
            if (crypto_aead_encrypt(c2,&clen,m2,mlen,a2,alen,s2,p2,k2) != 0) fail("crypto_aead_encrypt returns nonzero");
            if (memcmp(c2,c,clen) != 0) fail("crypto_aead_encrypt is nondeterministic");

#if crypto_aead_NOOVERLAP == 1
#else
            double_canary(c2,c,clen);
            double_canary(m2,m,mlen);
            double_canary(a2,a,alen);
            double_canary(s2,s,slen);
            double_canary(p2,p,plen);
            double_canary(k2,k,klen);
            if (crypto_aead_encrypt(m2,&clen,m2,mlen,a,alen,s,p,k) != 0) fail("crypto_aead_encrypt with m=c overlap returns nonzero");
            if (memcmp(m2,c,clen) != 0) fail("crypto_aead_encrypt does not handle m=c overlap");
            memcpy(m2,m,mlen);
            if (crypto_aead_encrypt(a2,&clen,m,mlen,a2,alen,s,p,k) != 0) fail("crypto_aead_encrypt with a=c overlap returns nonzero");
            if (memcmp(a2,c,clen) != 0) fail("crypto_aead_encrypt does not handle a=c overlap");
            memcpy(a2,a,alen);
            if (crypto_aead_encrypt(s2,&clen,m,mlen,a,alen,s2,p,k) != 0) fail("crypto_aead_encrypt with s=c overlap returns nonzero");
            if (memcmp(s2,c,clen) != 0) fail("crypto_aead_encrypt does not handle s=c overlap");
            memcpy(s2,s,slen);
            if (crypto_aead_encrypt(p2,&clen,m,mlen,a,alen,s,p2,k) != 0) fail("crypto_aead_encrypt with p=c overlap returns nonzero");
            if (memcmp(p2,c,clen) != 0) fail("crypto_aead_encrypt does not handle p=c overlap");
            memcpy(p2,p,plen);
            if (crypto_aead_encrypt(k2,&clen,m,mlen,a,alen,s,p,k2) != 0) fail("crypto_aead_encrypt with k=c overlap returns nonzero");
            if (memcmp(k2,c,clen) != 0) fail("crypto_aead_encrypt does not handle k=c overlap");
            memcpy(k2,k,klen);
#endif

            tlen = clen;
            output_prepare(t2,t,tlen);
            output_prepare(r2,r,rlen);
            memcpy(c2,c,clen);
            double_canary(c2,c,clen);
            memcpy(a2,a,alen);
            double_canary(a2,a,alen);
            memcpy(p2,p,plen);
            double_canary(p2,p,plen);
            memcpy(k2,k,klen);
            double_canary(k2,k,klen);
            if (crypto_aead_decrypt(t,&tlen,r,c,clen,a,alen,p,k) != 0) fail("crypto_aead_decrypt returns nonzero");
            if (tlen != mlen) fail("crypto_aead_decrypt does not match mlen");
            if (memcmp(t,m,mlen) != 0) fail("crypto_aead_decrypt does not match m");
            if (memcmp(r,s,slen) != 0) fail("crypto_aead_decrypt does not match s");
            checksum(t,tlen);
            checksum(r,rlen);
            output_compare(t2,t,clen,"crypto_aead_decrypt");
            output_compare(r2,r,rlen,"crypto_aead_decrypt");
            input_compare(c2,c,clen,"crypto_aead_decrypt");
            input_compare(a2,a,alen,"crypto_aead_decrypt");
            input_compare(p2,p,plen,"crypto_aead_decrypt");
            input_compare(k2,k,klen,"crypto_aead_decrypt");

            double_canary(t2,t,tlen);
            double_canary(r2,r,rlen);
            double_canary(c2,c,clen);
            double_canary(a2,a,alen);
            double_canary(p2,p,plen);
            double_canary(k2,k,klen);
            if (crypto_aead_decrypt(t2,&tlen,r2,c2,clen,a2,alen,p2,k2) != 0) fail("crypto_aead_decrypt returns nonzero");
            if (memcmp(t2,t,tlen) != 0) fail("crypto_aead_decrypt is nondeterministic");
            if (memcmp(r2,r,rlen) != 0) fail("crypto_aead_decrypt is nondeterministic");

#if crypto_aead_NOOVERLAP == 1
#else
            double_canary(t2,t,tlen);
            double_canary(r2,r,rlen);
            double_canary(c2,c,clen);
            double_canary(a2,a,alen);
            double_canary(p2,p,plen);
            double_canary(k2,k,klen);
            if (crypto_aead_decrypt(c2,&tlen,r,c2,clen,a,alen,p,k) != 0) fail("crypto_aead_decrypt with c=t overlap returns nonzero");
            if (memcmp(c2,t,tlen) != 0) fail("crypto_aead_decrypt does not handle c=t overlap");
            memcpy(c2,c,clen);
            if (crypto_aead_decrypt(a2,&tlen,r,c,clen,a2,alen,p,k) != 0) fail("crypto_aead_decrypt with a=t overlap returns nonzero");
            if (memcmp(a2,t,tlen) != 0) fail("crypto_aead_decrypt does not handle a=t overlap");
            memcpy(a2,a,alen);
            if (crypto_aead_decrypt(p2,&tlen,r,c,clen,a,alen,p2,k) != 0) fail("crypto_aead_decrypt with p=t overlap returns nonzero");
            if (memcmp(p2,t,tlen) != 0) fail("crypto_aead_decrypt does not handle p=t overlap");
            memcpy(p2,p,plen);
            if (crypto_aead_decrypt(k2,&tlen,r,c,clen,a,alen,p,k2) != 0) fail("crypto_aead_decrypt with k=t overlap returns nonzero");
            if (memcmp(k2,t,tlen) != 0) fail("crypto_aead_decrypt does not handle k=t overlap");
            memcpy(k2,k,klen);
#endif

#if crypto_aead_NOOVERLAP == 1
#else
            double_canary(t2,t,tlen);
            double_canary(r2,r,rlen);
            double_canary(c2,c,clen);
            double_canary(a2,a,alen);
            double_canary(p2,p,plen);
            double_canary(k2,k,klen);
            if (crypto_aead_decrypt(t,&tlen,c2,c2,clen,a,alen,p,k) != 0) fail("crypto_aead_decrypt with c=r overlap returns nonzero");
            if (memcmp(c2,r,rlen) != 0) fail("crypto_aead_decrypt does not handle c=r overlap");
            memcpy(c2,c,clen);
            if (crypto_aead_decrypt(t,&tlen,a2,c,clen,a2,alen,p,k) != 0) fail("crypto_aead_decrypt with a=r overlap returns nonzero");
            if (memcmp(a2,r,rlen) != 0) fail("crypto_aead_decrypt does not handle a=r overlap");
            memcpy(a2,a,alen);
            if (crypto_aead_decrypt(t,&tlen,p2,c,clen,a,alen,p2,k) != 0) fail("crypto_aead_decrypt with p=r overlap returns nonzero");
            if (memcmp(p2,r,rlen) != 0) fail("crypto_aead_decrypt does not handle p=r overlap");
            memcpy(p2,p,plen);
            if (crypto_aead_decrypt(t,&tlen,k2,c,clen,a,alen,p,k2) != 0) fail("crypto_aead_decrypt with k=r overlap returns nonzero");
            if (memcmp(k2,r,rlen) != 0) fail("crypto_aead_decrypt does not handle k=r overlap");
            memcpy(k2,k,klen);
#endif

            c[myrandom() % clen] += 1 + (myrandom() % 255);
            if (crypto_aead_decrypt(t,&tlen,r,c,clen,a,alen,p,k) == 0)
                if ((tlen != mlen) || (memcmp(t,m,mlen) != 0) || (memcmp(r,s,slen) != 0))
                    fail("crypto_aead_decrypt allows trivial forgeries");
            c[myrandom() % clen] += 1 + (myrandom() % 255);
            if (crypto_aead_decrypt(t,&tlen,r,c,clen,a,alen,p,k) == 0)
                if ((tlen != mlen) || (memcmp(t,m,mlen) != 0) || (memcmp(r,s,slen) != 0))
                    fail("crypto_aead_decrypt allows trivial forgeries");
            c[myrandom() % clen] += 1 + (myrandom() % 255);
            if (crypto_aead_decrypt(t,&tlen,r,c,clen,a,alen,p,k) == 0)
                if ((tlen != mlen) || (memcmp(t,m,mlen) != 0) || (memcmp(r,s,slen) != 0))
                    fail("crypto_aead_decrypt allows trivial forgeries");
        }
    }else{
        return FAIL_CHECKSUM;
    }
}
