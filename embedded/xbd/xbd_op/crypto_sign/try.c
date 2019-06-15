/*
 * crypto_sign/try.c version 20140429
 * D. J. Bernstein
 * Public domain.
 * Auto-generated by trygen.py; do not edit.
 */

#include "crypto_sign.h"
#include "XBD_operation.h"
#include "try.h"
#include "XBD_debug.h"

#define SMALL
#define TUNE_BYTES 1536
#ifdef SMALL
#define MAXTEST_BYTES 2048
#else
#define MAXTEST_BYTES 4096
#endif
#ifdef SMALL
#define LOOPS 8
#else
#define LOOPS 64
#endif

static unsigned char *p;
static unsigned char *s;
static unsigned char *m;
static unsigned char *c;
static unsigned char *t;
//static unsigned char *p2;
//static unsigned char *s2;
//static unsigned char *m2;
//static unsigned char *c2;
//static unsigned char *t2;
#define plen crypto_sign_PUBLICKEYBYTES
#define slen crypto_sign_SECRETKEYBYTES
static unsigned long long mlen;
static unsigned long long clen;
static unsigned long long tlen;

void preallocate(void)
{
}

void test_allocate(unsigned char *buf)
{
  p = buf+CANARY_SZ;
  s = p+plen+CANARY_SZ*2;
  m = s+slen+CANARY_SZ*2;
  c = m+MAX_MSG_BYTES+CANARY_SZ*2;
  t = c+MAX_MSG_BYTES+crypto_sign_BYTES+CANARY_SZ*2;
  //p2 = t+MAX_MSG_BYTES+CANARY_SZ*2;
  //s2 = p+crypto_sign_PUBLICKEYBYTES+CANARY_SZ*2;
  //m2 = s+crypto_sign_SECRETKEYBYTES+CANARY_SZ*2;
  //c2 = m+MAX_MSG_BYTES+CANARY_SZ*2;
  //t2 = c+crypto_sign_BYTES+CANARY_SZ*2;
  //Randomize contents
  for (size_t i = 0; i < MAX_TESTBUFFER_BYTES; i++){
      buf[i]=(unsigned char)(myrandom() & 0xFF);
  }
}

void predoit(void)
{
  crypto_sign_keypair(p,s);
  mlen = TUNE_BYTES;
  clen = 0;
  randombytes(m,mlen);
}

void doit(void)
{
  crypto_sign(c,&clen,m,mlen,s);
  crypto_sign_open(t,&tlen,c,clen,p);
}

int test(void)
{
  unsigned loop;
  
  if(!setjmp(test_fail_jmp)){
    for (loop = 0;loop < LOOPS;++loop) {
      XBD_DEBUG("Loop number: "); XBD_DEBUG_32B(loop); XBD_DEBUG_CHAR('\n');
      mlen = myrandom() % (MAXTEST_BYTES);
      
      //output_prepare(p2,p,plen);
      output_prepare(p,p,plen);
      //output_prepare(s2,s,slen);
      output_prepare(s,s,slen);
      if (crypto_sign_keypair(p,s) != 0) fail("crypto_sign_keypair returns nonzero");
      XBD_DEBUG("Exited crypto_sign_keypair\n");
      checksum(p,plen);
      XBD_DEBUG("Checksum p successful\n");
      checksum(s,slen);
      XBD_DEBUG("Checksum s successful\n");
      //output_compare(p2,p,plen,"crypto_sign_keypair");
      output_compare(p,p,plen,"crypto_sign_keypair");
      XBD_DEBUG("Output compare of p successful\n");
      //output_compare(s2,s,slen,"crypto_sign_keypair");
      output_compare(s,s,slen,"crypto_sign_keypair");
      XBD_DEBUG("Output compare of s successful\n");
      XBD_DEBUG("Keypair successful\n");
      
      clen = mlen + crypto_sign_BYTES;
      //output_prepare(c2,c,clen);
      output_prepare(c,c,clen);
      //input_prepare(m2,m,mlen);
      input_prepare(m,m,mlen);
      //memcpy(s2,s,slen);
      //double_canary(s2,s,slen);
      double_canary(s,s,slen);
      if (crypto_sign(c,&clen,m,mlen,s) != 0) fail("crypto_sign returns nonzero");
      if (clen < mlen) fail("crypto_sign returns smaller output than input");
      if (clen > mlen + crypto_sign_BYTES) fail("crypto_sign returns more than crypto_sign_BYTES extra bytes");
      checksum(c,clen);
      //output_compare(c2,c,clen,"crypto_sign");
      output_compare(c,c,clen,"crypto_sign");
      //input_compare(m2,m,mlen,"crypto_sign");
      input_compare(m,m,mlen,"crypto_sign");
      //input_compare(s2,s,slen,"crypto_sign");
      input_compare(s,s,slen,"crypto_sign");
      XBD_DEBUG("Signing successful\n");
      
#if 0
      double_canary(c2,c,clen);
      double_canary(m2,m,mlen);
      double_canary(s2,s,slen);
      if (crypto_sign(c2,&clen,m2,mlen,s2) != 0) fail("crypto_sign returns nonzero");
      if (memcmp(c2,c,clen) != 0) fail("crypto_sign is nondeterministic");

      double_canary(c2,c,clen);
      double_canary(m2,m,mlen);
      double_canary(s2,s,slen);
      if (crypto_sign(m2,&clen,m2,mlen,s) != 0) fail("crypto_sign with m=c overlap returns nonzero");
      if (memcmp(m2,c,clen) != 0) fail("crypto_sign does not handle m=c overlap");
      memcpy(m2,m,mlen);
      if (crypto_sign(s2,&clen,m,mlen,s2) != 0) fail("crypto_sign with s=c overlap returns nonzero");
      if (memcmp(s2,c,clen) != 0) fail("crypto_sign does not handle s=c overlap");
      memcpy(s2,s,slen);
#endif
      
      tlen = clen;
      //output_prepare(t2,t,tlen);
      output_prepare(t,t,tlen);
      //memcpy(c2,c,clen);
      //double_canary(c2,c,clen);
      double_canary(c,c,clen);
      //memcpy(p2,p,plen);
      //double_canary(p2,p,plen);
      double_canary(p,p,plen);
      if (crypto_sign_open(t,&tlen,c,clen,p) != 0) fail("crypto_sign_open returns nonzero");
      if (tlen != mlen) fail("crypto_sign_open does not match mlen");
      if (memcmp(t,m,mlen) != 0) fail("crypto_sign_open does not match m");
      checksum(t,tlen);
      //output_compare(t2,t,clen,"crypto_sign_open");
      output_compare(t,t,clen,"crypto_sign_open");
      //input_compare(c2,c,clen,"crypto_sign_open");
      input_compare(c,c,clen,"crypto_sign_open");
      //input_compare(p2,p,plen,"crypto_sign_open");
      input_compare(p,p,plen,"crypto_sign_open");
      XBD_DEBUG("Opening successful\n");

#if 0
      double_canary(t2,t,tlen);
      double_canary(c2,c,clen);
      double_canary(p2,p,plen);
      if (crypto_sign_open(t2,&tlen,c2,clen,p2) != 0) fail("crypto_sign_open returns nonzero");
      if (memcmp(t2,t,tlen) != 0) fail("crypto_sign_open is nondeterministic");
      
      double_canary(t2,t,tlen);
      double_canary(c2,c,clen);
      double_canary(p2,p,plen);
      if (crypto_sign_open(c2,&tlen,c2,clen,p) != 0) fail("crypto_sign_open with c=t overlap returns nonzero");
      if (memcmp(c2,t,tlen) != 0) fail("crypto_sign_open does not handle c=t overlap");
      memcpy(c2,c,clen);
      if (crypto_sign_open(p2,&tlen,c,clen,p2) != 0) fail("crypto_sign_open with p=t overlap returns nonzero");
      if (memcmp(p2,t,tlen) != 0) fail("crypto_sign_open does not handle p=t overlap");
      memcpy(p2,p,plen);
#endif
      
      c[myrandom() % clen] += 1 + (myrandom() % 255);
      if (crypto_sign_open(t,&tlen,c,clen,p) == 0)
        if ((tlen != mlen) || (memcmp(t,m,mlen) != 0))
          fail("crypto_sign_open allows trivial forgeries");
      c[myrandom() % clen] += 1 + (myrandom() % 255);
      if (crypto_sign_open(t,&tlen,c,clen,p) == 0)
        if ((tlen != mlen) || (memcmp(t,m,mlen) != 0))
          fail("crypto_sign_open allows trivial forgeries");
      c[myrandom() % clen] += 1 + (myrandom() % 255);
      if (crypto_sign_open(t,&tlen,c,clen,p) == 0)
        if ((tlen != mlen) || (memcmp(t,m,mlen) != 0))
          fail("crypto_sign_open allows trivial forgeries");
      XBD_DEBUG("Forgery test successful\n");
    }
    return 0;
  }else{
    return FAIL_CHECKSUM;
  }
}
