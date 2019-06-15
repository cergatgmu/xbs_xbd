/* This file is part of the libopencm3 project.
 *
 * It was generated by the irq2nvic_h script.
 *
 * This part needs to get included in the compilation unit where
 * blocking_handler gets defined due to the way #pragma works.
 */


/** @defgroup CM3_nvic_isrdecls_LM3S User interrupt service routines (ISR) defaults for LM3S series
    @ingroup CM3_nvic_isrdecls

    @{*/

void gpioq7_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioq6_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm1_3_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm1_2_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm1_1_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm1_0_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm1_fault_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer2b_isr(void) __attribute__((weak, alias("blocking_handler")));
void comp0_isr(void) __attribute__((weak, alias("blocking_handler")));
void comp1_isr(void) __attribute__((weak, alias("blocking_handler")));
void comp2_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer0b_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer1a_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer1b_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer2a_isr(void) __attribute__((weak, alias("blocking_handler")));
void sysctl_isr(void) __attribute__((weak, alias("blocking_handler")));
void flash_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioa_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioe_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c0_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiop4_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiop5_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiop6_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiop7_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioq0_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioq1_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioq2_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioq3_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioq4_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioq5_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart3_isr(void) __attribute__((weak, alias("blocking_handler")));
void ssi3_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiok_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioj_isr(void) __attribute__((weak, alias("blocking_handler")));
void ssi2_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiol_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc1ss3_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc1ss2_isr(void) __attribute__((weak, alias("blocking_handler")));
void epi0_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2s0_isr(void) __attribute__((weak, alias("blocking_handler")));
void fan0_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiop1_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiop0_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiom_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c5_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpion_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiop3_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiop2_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiod_isr(void) __attribute__((weak, alias("blocking_handler")));
void ssi0_isr(void) __attribute__((weak, alias("blocking_handler")));
void lpc0_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c4_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer4a_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer4b_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer3a_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer3b_isr(void) __attribute__((weak, alias("blocking_handler")));
void sysexc_isr(void) __attribute__((weak, alias("blocking_handler")));
void peci0_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer5a_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer5b_isr(void) __attribute__((weak, alias("blocking_handler")));
void can0_isr(void) __attribute__((weak, alias("blocking_handler")));
void qei1_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart2_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioh_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiog_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiof_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c1_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer3b_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer3a_isr(void) __attribute__((weak, alias("blocking_handler")));
void ssi1_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart4_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart5_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart6_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart7_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c2_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c3_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioc_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart1_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer2b_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer2a_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer5b_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer5a_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer0b_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer0a_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer1b_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer1a_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm0_1_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm0_0_isr(void) __attribute__((weak, alias("blocking_handler")));
void qei0_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm0_2_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc0ss1_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc0ss0_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc0ss3_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc0ss2_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer0a_isr(void) __attribute__((weak, alias("blocking_handler")));
void watchdog_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc1ss0_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc1ss1_isr(void) __attribute__((weak, alias("blocking_handler")));
void udma_isr(void) __attribute__((weak, alias("blocking_handler")));
void udmaerr_isr(void) __attribute__((weak, alias("blocking_handler")));
void usb0_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm0_3_isr(void) __attribute__((weak, alias("blocking_handler")));
void eth_isr(void) __attribute__((weak, alias("blocking_handler")));
void hibernate_isr(void) __attribute__((weak, alias("blocking_handler")));
void can1_isr(void) __attribute__((weak, alias("blocking_handler")));
void can2_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiob_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart0_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm0_fault_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer4b_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer4a_isr(void) __attribute__((weak, alias("blocking_handler")));

/**@}*/

/* Initialization template for the interrupt vector table. This definition is
 * used by the startup code generator (vector.c) to set the initial values for
 * the interrupt handling routines to the chip family specific _isr weak
 * symbols. */

#define IRQ_HANDLERS \
    [NVIC_GPIOQ7_IRQ] = gpioq7_isr, \
    [NVIC_GPIOQ6_IRQ] = gpioq6_isr, \
    [NVIC_PWM1_3_IRQ] = pwm1_3_isr, \
    [NVIC_PWM1_2_IRQ] = pwm1_2_isr, \
    [NVIC_PWM1_1_IRQ] = pwm1_1_isr, \
    [NVIC_PWM1_0_IRQ] = pwm1_0_isr, \
    [NVIC_PWM1_FAULT_IRQ] = pwm1_fault_isr, \
    [NVIC_TIMER2B_IRQ] = timer2b_isr, \
    [NVIC_COMP0_IRQ] = comp0_isr, \
    [NVIC_COMP1_IRQ] = comp1_isr, \
    [NVIC_COMP2_IRQ] = comp2_isr, \
    [NVIC_TIMER0B_IRQ] = timer0b_isr, \
    [NVIC_TIMER1A_IRQ] = timer1a_isr, \
    [NVIC_TIMER1B_IRQ] = timer1b_isr, \
    [NVIC_TIMER2A_IRQ] = timer2a_isr, \
    [NVIC_SYSCTL_IRQ] = sysctl_isr, \
    [NVIC_FLASH_IRQ] = flash_isr, \
    [NVIC_GPIOA_IRQ] = gpioa_isr, \
    [NVIC_GPIOE_IRQ] = gpioe_isr, \
    [NVIC_I2C0_IRQ] = i2c0_isr, \
    [NVIC_GPIOP4_IRQ] = gpiop4_isr, \
    [NVIC_GPIOP5_IRQ] = gpiop5_isr, \
    [NVIC_GPIOP6_IRQ] = gpiop6_isr, \
    [NVIC_GPIOP7_IRQ] = gpiop7_isr, \
    [NVIC_GPIOQ0_IRQ] = gpioq0_isr, \
    [NVIC_GPIOQ1_IRQ] = gpioq1_isr, \
    [NVIC_GPIOQ2_IRQ] = gpioq2_isr, \
    [NVIC_GPIOQ3_IRQ] = gpioq3_isr, \
    [NVIC_GPIOQ4_IRQ] = gpioq4_isr, \
    [NVIC_GPIOQ5_IRQ] = gpioq5_isr, \
    [NVIC_UART3_IRQ] = uart3_isr, \
    [NVIC_SSI3_IRQ] = ssi3_isr, \
    [NVIC_GPIOK_IRQ] = gpiok_isr, \
    [NVIC_GPIOJ_IRQ] = gpioj_isr, \
    [NVIC_SSI2_IRQ] = ssi2_isr, \
    [NVIC_GPIOL_IRQ] = gpiol_isr, \
    [NVIC_ADC1SS3_IRQ] = adc1ss3_isr, \
    [NVIC_ADC1SS2_IRQ] = adc1ss2_isr, \
    [NVIC_EPI0_IRQ] = epi0_isr, \
    [NVIC_I2S0_IRQ] = i2s0_isr, \
    [NVIC_FAN0_IRQ] = fan0_isr, \
    [NVIC_GPIOP1_IRQ] = gpiop1_isr, \
    [NVIC_GPIOP0_IRQ] = gpiop0_isr, \
    [NVIC_GPIOM_IRQ] = gpiom_isr, \
    [NVIC_I2C5_IRQ] = i2c5_isr, \
    [NVIC_GPION_IRQ] = gpion_isr, \
    [NVIC_GPIOP3_IRQ] = gpiop3_isr, \
    [NVIC_GPIOP2_IRQ] = gpiop2_isr, \
    [NVIC_GPIOD_IRQ] = gpiod_isr, \
    [NVIC_SSI0_IRQ] = ssi0_isr, \
    [NVIC_LPC0_IRQ] = lpc0_isr, \
    [NVIC_I2C4_IRQ] = i2c4_isr, \
    [NVIC_WTIMER4A_IRQ] = wtimer4a_isr, \
    [NVIC_WTIMER4B_IRQ] = wtimer4b_isr, \
    [NVIC_WTIMER3A_IRQ] = wtimer3a_isr, \
    [NVIC_WTIMER3B_IRQ] = wtimer3b_isr, \
    [NVIC_SYSEXC_IRQ] = sysexc_isr, \
    [NVIC_PECI0_IRQ] = peci0_isr, \
    [NVIC_WTIMER5A_IRQ] = wtimer5a_isr, \
    [NVIC_WTIMER5B_IRQ] = wtimer5b_isr, \
    [NVIC_CAN0_IRQ] = can0_isr, \
    [NVIC_QEI1_IRQ] = qei1_isr, \
    [NVIC_UART2_IRQ] = uart2_isr, \
    [NVIC_GPIOH_IRQ] = gpioh_isr, \
    [NVIC_GPIOG_IRQ] = gpiog_isr, \
    [NVIC_GPIOF_IRQ] = gpiof_isr, \
    [NVIC_I2C1_IRQ] = i2c1_isr, \
    [NVIC_TIMER3B_IRQ] = timer3b_isr, \
    [NVIC_TIMER3A_IRQ] = timer3a_isr, \
    [NVIC_SSI1_IRQ] = ssi1_isr, \
    [NVIC_UART4_IRQ] = uart4_isr, \
    [NVIC_UART5_IRQ] = uart5_isr, \
    [NVIC_UART6_IRQ] = uart6_isr, \
    [NVIC_UART7_IRQ] = uart7_isr, \
    [NVIC_I2C2_IRQ] = i2c2_isr, \
    [NVIC_I2C3_IRQ] = i2c3_isr, \
    [NVIC_GPIOC_IRQ] = gpioc_isr, \
    [NVIC_UART1_IRQ] = uart1_isr, \
    [NVIC_WTIMER2B_IRQ] = wtimer2b_isr, \
    [NVIC_WTIMER2A_IRQ] = wtimer2a_isr, \
    [NVIC_TIMER5B_IRQ] = timer5b_isr, \
    [NVIC_TIMER5A_IRQ] = timer5a_isr, \
    [NVIC_WTIMER0B_IRQ] = wtimer0b_isr, \
    [NVIC_WTIMER0A_IRQ] = wtimer0a_isr, \
    [NVIC_WTIMER1B_IRQ] = wtimer1b_isr, \
    [NVIC_WTIMER1A_IRQ] = wtimer1a_isr, \
    [NVIC_PWM0_1_IRQ] = pwm0_1_isr, \
    [NVIC_PWM0_0_IRQ] = pwm0_0_isr, \
    [NVIC_QEI0_IRQ] = qei0_isr, \
    [NVIC_PWM0_2_IRQ] = pwm0_2_isr, \
    [NVIC_ADC0SS1_IRQ] = adc0ss1_isr, \
    [NVIC_ADC0SS0_IRQ] = adc0ss0_isr, \
    [NVIC_ADC0SS3_IRQ] = adc0ss3_isr, \
    [NVIC_ADC0SS2_IRQ] = adc0ss2_isr, \
    [NVIC_TIMER0A_IRQ] = timer0a_isr, \
    [NVIC_WATCHDOG_IRQ] = watchdog_isr, \
    [NVIC_ADC1SS0_IRQ] = adc1ss0_isr, \
    [NVIC_ADC1SS1_IRQ] = adc1ss1_isr, \
    [NVIC_UDMA_IRQ] = udma_isr, \
    [NVIC_UDMAERR_IRQ] = udmaerr_isr, \
    [NVIC_USB0_IRQ] = usb0_isr, \
    [NVIC_PWM0_3_IRQ] = pwm0_3_isr, \
    [NVIC_ETH_IRQ] = eth_isr, \
    [NVIC_HIBERNATE_IRQ] = hibernate_isr, \
    [NVIC_CAN1_IRQ] = can1_isr, \
    [NVIC_CAN2_IRQ] = can2_isr, \
    [NVIC_GPIOB_IRQ] = gpiob_isr, \
    [NVIC_UART0_IRQ] = uart0_isr, \
    [NVIC_PWM0_FAULT_IRQ] = pwm0_fault_isr, \
    [NVIC_TIMER4B_IRQ] = timer4b_isr, \
    [NVIC_TIMER4A_IRQ] = timer4a_isr
