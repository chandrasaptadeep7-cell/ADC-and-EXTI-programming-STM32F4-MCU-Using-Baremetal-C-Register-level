/*
 * CCU6.h
 *
 *  Created on: Aug 23, 2026
 *  Author: Saptadeep
 */

//#ifndef CCU6_H_
//#define CCU6_H_


#ifndef CCU6_H
#define CCU6_H

/*
 * CCU6.h
 * STM32F401CCU6 register map
 *
 * Target: STM32F401xC, ARM Cortex-M4
 * Based on STMicroelectronics RM0368 (STM32F401xB/C and STM32F401xD/E)
 *
 * This is a register-definition header only. It does not initialize
 * peripherals or provide HAL-style functions.
 */

#include <stdint.h>

/* =========================================================================
 * Core / NVIC / SysTick / SCB
 * ========================================================================= */
#define SCS_BASE        0xE000E000UL
#define SysTick_BASE    (SCS_BASE + 0x0010UL)
#define NVIC_BASE       (SCS_BASE + 0x0100UL)
#define SCB_BASE        (SCS_BASE + 0x0D00UL)

#define SYST_CSR        (*(volatile uint32_t *)(SysTick_BASE + 0x000UL))
#define SYST_RVR        (*(volatile uint32_t *)(SysTick_BASE + 0x004UL))
#define SYST_CVR        (*(volatile uint32_t *)(SysTick_BASE + 0x008UL))
#define SYST_CALIB      (*(volatile uint32_t *)(SysTick_BASE + 0x00CUL))

#define NVIC_ISER0      (*(volatile uint32_t *)(NVIC_BASE + 0x000UL))
#define NVIC_ISER1      (*(volatile uint32_t *)(NVIC_BASE + 0x004UL))
#define NVIC_ICER0      (*(volatile uint32_t *)(NVIC_BASE + 0x080UL))
#define NVIC_ICER1      (*(volatile uint32_t *)(NVIC_BASE + 0x084UL))
#define NVIC_ISPR0      (*(volatile uint32_t *)(NVIC_BASE + 0x100UL))
#define NVIC_ISPR1      (*(volatile uint32_t *)(NVIC_BASE + 0x104UL))
#define NVIC_ICPR0      (*(volatile uint32_t *)(NVIC_BASE + 0x180UL))
#define NVIC_ICPR1      (*(volatile uint32_t *)(NVIC_BASE + 0x184UL))
#define NVIC_IABR0      (*(volatile uint32_t *)(NVIC_BASE + 0x200UL))
#define NVIC_IABR1      (*(volatile uint32_t *)(NVIC_BASE + 0x204UL))

#define NVIC_IPR_BASE   (NVIC_BASE + 0x300UL)
#define NVIC_IPR(n)     (*(volatile uint8_t *)(NVIC_IPR_BASE + (uint32_t)(n)))

#define SCB_CPUID       (*(volatile uint32_t *)(SCB_BASE + 0x000UL))
#define SCB_ICSR        (*(volatile uint32_t *)(SCB_BASE + 0x004UL))
#define SCB_VTOR        (*(volatile uint32_t *)(SCB_BASE + 0x008UL))
#define SCB_AIRCR       (*(volatile uint32_t *)(SCB_BASE + 0x00CUL))
#define SCB_SCR         (*(volatile uint32_t *)(SCB_BASE + 0x010UL))
#define SCB_CCR         (*(volatile uint32_t *)(SCB_BASE + 0x014UL))
#define SCB_SHPR1       (*(volatile uint32_t *)(SCB_BASE + 0x018UL))
#define SCB_SHPR2       (*(volatile uint32_t *)(SCB_BASE + 0x01CUL))
#define SCB_SHPR3       (*(volatile uint32_t *)(SCB_BASE + 0x020UL))
#define SCB_SHCSR       (*(volatile uint32_t *)(SCB_BASE + 0x024UL))

/* =========================================================================
 * Peripheral base addresses
 * ========================================================================= */
#define PERIPH_BASE     0x40000000UL
#define APB1_BASE       0x40000000UL
#define APB2_BASE       0x40010000UL
#define AHB1_BASE       0x40020000UL
#define AHB2_BASE       0x50000000UL

/* =========================================================================
 * GPIO
 * GPIOA 0x40020000
 * GPIOB 0x40020400
 * GPIOC 0x40020800
 * GPIOD 0x40020C00
 * GPIOE 0x40021000
 * GPIOH 0x40021C00
 * ========================================================================= */
#define GPIOA_BASE      (AHB1_BASE + 0x0000UL)
#define GPIOB_BASE      (AHB1_BASE + 0x0400UL)
#define GPIOC_BASE      (AHB1_BASE + 0x0800UL)
#define GPIOD_BASE      (AHB1_BASE + 0x0C00UL)
#define GPIOE_BASE      (AHB1_BASE + 0x1000UL)
#define GPIOH_BASE      (AHB1_BASE + 0x1C00UL)

#define GPIO_MODER      0x00UL
#define GPIO_OTYPER     0x04UL
#define GPIO_OSPEEDR    0x08UL
#define GPIO_PUPDR      0x0CUL
#define GPIO_IDR        0x10UL
#define GPIO_ODR        0x14UL
#define GPIO_BSRR       0x18UL
#define GPIO_LCKR       0x1CUL
#define GPIO_AFRL       0x20UL
#define GPIO_AFRH       0x24UL

#define GPIO_REG(base, off) (*(volatile uint32_t *)((base) + (off)))

#define GPIOA_MODER     GPIO_REG(GPIOA_BASE, GPIO_MODER)
#define GPIOA_OTYPER    GPIO_REG(GPIOA_BASE, GPIO_OTYPER)
#define GPIOA_OSPEEDR   GPIO_REG(GPIOA_BASE, GPIO_OSPEEDR)
#define GPIOA_PUPDR     GPIO_REG(GPIOA_BASE, GPIO_PUPDR)
#define GPIOA_IDR       GPIO_REG(GPIOA_BASE, GPIO_IDR)
#define GPIOA_ODR       GPIO_REG(GPIOA_BASE, GPIO_ODR)
#define GPIOA_BSRR      GPIO_REG(GPIOA_BASE, GPIO_BSRR)
#define GPIOA_LCKR      GPIO_REG(GPIOA_BASE, GPIO_LCKR)
#define GPIOA_AFRL      GPIO_REG(GPIOA_BASE, GPIO_AFRL)
#define GPIOA_AFRH      GPIO_REG(GPIOA_BASE, GPIO_AFRH)

#define GPIOB_MODER     GPIO_REG(GPIOB_BASE, GPIO_MODER)
#define GPIOB_OTYPER    GPIO_REG(GPIOB_BASE, GPIO_OTYPER)
#define GPIOB_OSPEEDR   GPIO_REG(GPIOB_BASE, GPIO_OSPEEDR)
#define GPIOB_PUPDR     GPIO_REG(GPIOB_BASE, GPIO_PUPDR)
#define GPIOB_IDR       GPIO_REG(GPIOB_BASE, GPIO_IDR)
#define GPIOB_ODR       GPIO_REG(GPIOB_BASE, GPIO_ODR)
#define GPIOB_BSRR      GPIO_REG(GPIOB_BASE, GPIO_BSRR)
#define GPIOB_LCKR      GPIO_REG(GPIOB_BASE, GPIO_LCKR)
#define GPIOB_AFRL      GPIO_REG(GPIOB_BASE, GPIO_AFRL)
#define GPIOB_AFRH      GPIO_REG(GPIOB_BASE, GPIO_AFRH)

#define GPIOC_MODER     GPIO_REG(GPIOC_BASE, GPIO_MODER)
#define GPIOC_OTYPER    GPIO_REG(GPIOC_BASE, GPIO_OTYPER)
#define GPIOC_OSPEEDR   GPIO_REG(GPIOC_BASE, GPIO_OSPEEDR)
#define GPIOC_PUPDR     GPIO_REG(GPIOC_BASE, GPIO_PUPDR)
#define GPIOC_IDR       GPIO_REG(GPIOC_BASE, GPIO_IDR)
#define GPIOC_ODR       GPIO_REG(GPIOC_BASE, GPIO_ODR)
#define GPIOC_BSRR      GPIO_REG(GPIOC_BASE, GPIO_BSRR)
#define GPIOC_LCKR      GPIO_REG(GPIOC_BASE, GPIO_LCKR)
#define GPIOC_AFRL      GPIO_REG(GPIOC_BASE, GPIO_AFRL)
#define GPIOC_AFRH      GPIO_REG(GPIOC_BASE, GPIO_AFRH)

#define GPIOD_MODER     GPIO_REG(GPIOD_BASE, GPIO_MODER)
#define GPIOD_OTYPER    GPIO_REG(GPIOD_BASE, GPIO_OTYPER)
#define GPIOD_OSPEEDR   GPIO_REG(GPIOD_BASE, GPIO_OSPEEDR)
#define GPIOD_PUPDR     GPIO_REG(GPIOD_BASE, GPIO_PUPDR)
#define GPIOD_IDR       GPIO_REG(GPIOD_BASE, GPIO_IDR)
#define GPIOD_ODR       GPIO_REG(GPIOD_BASE, GPIO_ODR)
#define GPIOD_BSRR      GPIO_REG(GPIOD_BASE, GPIO_BSRR)
#define GPIOD_LCKR      GPIO_REG(GPIOD_BASE, GPIO_LCKR)
#define GPIOD_AFRL      GPIO_REG(GPIOD_BASE, GPIO_AFRL)
#define GPIOD_AFRH      GPIO_REG(GPIOD_BASE, GPIO_AFRH)

#define GPIOE_MODER     GPIO_REG(GPIOE_BASE, GPIO_MODER)
#define GPIOE_OTYPER    GPIO_REG(GPIOE_BASE, GPIO_OTYPER)
#define GPIOE_OSPEEDR   GPIO_REG(GPIOE_BASE, GPIO_OSPEEDR)
#define GPIOE_PUPDR     GPIO_REG(GPIOE_BASE, GPIO_PUPDR)
#define GPIOE_IDR       GPIO_REG(GPIOE_BASE, GPIO_IDR)
#define GPIOE_ODR       GPIO_REG(GPIOE_BASE, GPIO_ODR)
#define GPIOE_BSRR      GPIO_REG(GPIOE_BASE, GPIO_BSRR)
#define GPIOE_LCKR      GPIO_REG(GPIOE_BASE, GPIO_LCKR)
#define GPIOE_AFRL      GPIO_REG(GPIOE_BASE, GPIO_AFRL)
#define GPIOE_AFRH      GPIO_REG(GPIOE_BASE, GPIO_AFRH)

#define GPIOH_MODER     GPIO_REG(GPIOH_BASE, GPIO_MODER)
#define GPIOH_OTYPER    GPIO_REG(GPIOH_BASE, GPIO_OTYPER)
#define GPIOH_OSPEEDR   GPIO_REG(GPIOH_BASE, GPIO_OSPEEDR)
#define GPIOH_PUPDR     GPIO_REG(GPIOH_BASE, GPIO_PUPDR)
#define GPIOH_IDR       GPIO_REG(GPIOH_BASE, GPIO_IDR)
#define GPIOH_ODR       GPIO_REG(GPIOH_BASE, GPIO_ODR)
#define GPIOH_BSRR      GPIO_REG(GPIOH_BASE, GPIO_BSRR)
#define GPIOH_LCKR      GPIO_REG(GPIOH_BASE, GPIO_LCKR)
#define GPIOH_AFRL      GPIO_REG(GPIOH_BASE, GPIO_AFRL)
#define GPIOH_AFRH      GPIO_REG(GPIOH_BASE, GPIO_AFRH)

/* =========================================================================
 * RCC
 * ========================================================================= */
#define RCC_BASE        (AHB1_BASE + 0x3800UL)

#define RCC_CR          GPIO_REG(RCC_BASE, 0x00UL)
#define RCC_PLLCFGR     GPIO_REG(RCC_BASE, 0x04UL)
#define RCC_CFGR        GPIO_REG(RCC_BASE, 0x08UL)
#define RCC_CIR         GPIO_REG(RCC_BASE, 0x0CUL)
#define RCC_AHB1RSTR    GPIO_REG(RCC_BASE, 0x10UL)
#define RCC_AHB2RSTR    GPIO_REG(RCC_BASE, 0x14UL)
#define RCC_APB1RSTR    GPIO_REG(RCC_BASE, 0x20UL)
#define RCC_APB2RSTR    GPIO_REG(RCC_BASE, 0x24UL)
#define RCC_AHB1ENR     GPIO_REG(RCC_BASE, 0x30UL)
#define RCC_AHB2ENR     GPIO_REG(RCC_BASE, 0x34UL)
#define RCC_APB1ENR     GPIO_REG(RCC_BASE, 0x40UL)
#define RCC_APB2ENR     GPIO_REG(RCC_BASE, 0x44UL)
#define RCC_AHB1LPENR   GPIO_REG(RCC_BASE, 0x50UL)
#define RCC_AHB2LPENR   GPIO_REG(RCC_BASE, 0x54UL)
#define RCC_APB1LPENR   GPIO_REG(RCC_BASE, 0x60UL)
#define RCC_APB2LPENR   GPIO_REG(RCC_BASE, 0x64UL)
#define RCC_BDCR        GPIO_REG(RCC_BASE, 0x70UL)
#define RCC_CSR         GPIO_REG(RCC_BASE, 0x74UL)
#define RCC_SSCGR       GPIO_REG(RCC_BASE, 0x80UL)
#define RCC_PLLI2SCFGR  GPIO_REG(RCC_BASE, 0x84UL)
#define RCC_DCKCFGR     GPIO_REG(RCC_BASE, 0x8CUL)

/* =========================================================================
 * TIMERS
 * TIM2 0x40000000, TIM3 0x40000400, TIM4 0x40000800, TIM5 0x40000C00
 * TIM9 0x40014000, TIM10 0x40014400, TIM11 0x40014800
 * ========================================================================= */
#define TIM2_BASE       (APB1_BASE + 0x0000UL)
#define TIM3_BASE       (APB1_BASE + 0x0400UL)
#define TIM4_BASE       (APB1_BASE + 0x0800UL)
#define TIM5_BASE       (APB1_BASE + 0x0C00UL)
#define TIM9_BASE       (APB2_BASE + 0x4000UL)
#define TIM10_BASE      (APB2_BASE + 0x4400UL)
#define TIM11_BASE      (APB2_BASE + 0x4800UL)

#define TIM_CR1         0x00UL
#define TIM_CR2         0x04UL
#define TIM_SMCR        0x08UL
#define TIM_DIER        0x0CUL
#define TIM_SR          0x10UL
#define TIM_EGR         0x14UL
#define TIM_CCMR1       0x18UL
#define TIM_CCMR2       0x1CUL
#define TIM_CCER        0x20UL
#define TIM_CNT         0x24UL
#define TIM_PSC         0x28UL
#define TIM_ARR         0x2CUL
#define TIM_RCR         0x30UL
#define TIM_CCR1        0x34UL
#define TIM_CCR2        0x38UL
#define TIM_CCR3        0x3CUL
#define TIM_CCR4        0x40UL
#define TIM_BDTR        0x44UL
#define TIM_DCR         0x48UL
#define TIM_DMAR        0x4CUL

#define TIM_REG(base, off) GPIO_REG((base), (off))

#define TIM2_CR1        TIM_REG(TIM2_BASE, TIM_CR1)
#define TIM2_CR2        TIM_REG(TIM2_BASE, TIM_CR2)
#define TIM2_SMCR       TIM_REG(TIM2_BASE, TIM_SMCR)
#define TIM2_DIER       TIM_REG(TIM2_BASE, TIM_DIER)
#define TIM2_SR         TIM_REG(TIM2_BASE, TIM_SR)
#define TIM2_EGR        TIM_REG(TIM2_BASE, TIM_EGR)
#define TIM2_CCMR1      TIM_REG(TIM2_BASE, TIM_CCMR1)
#define TIM2_CCMR2      TIM_REG(TIM2_BASE, TIM_CCMR2)
#define TIM2_CCER       TIM_REG(TIM2_BASE, TIM_CCER)
#define TIM2_CNT        TIM_REG(TIM2_BASE, TIM_CNT)
#define TIM2_PSC        TIM_REG(TIM2_BASE, TIM_PSC)
#define TIM2_ARR        TIM_REG(TIM2_BASE, TIM_ARR)
#define TIM2_CCR1       TIM_REG(TIM2_BASE, TIM_CCR1)
#define TIM2_CCR2       TIM_REG(TIM2_BASE, TIM_CCR2)
#define TIM2_CCR3       TIM_REG(TIM2_BASE, TIM_CCR3)
#define TIM2_CCR4       TIM_REG(TIM2_BASE, TIM_CCR4)
#define TIM2_DCR        TIM_REG(TIM2_BASE, TIM_DCR)
#define TIM2_DMAR       TIM_REG(TIM2_BASE, TIM_DMAR)

#define TIM3_CR1        TIM_REG(TIM3_BASE, TIM_CR1)
#define TIM3_CR2        TIM_REG(TIM3_BASE, TIM_CR2)
#define TIM3_SMCR       TIM_REG(TIM3_BASE, TIM_SMCR)
#define TIM3_DIER       TIM_REG(TIM3_BASE, TIM_DIER)
#define TIM3_SR         TIM_REG(TIM3_BASE, TIM_SR)
#define TIM3_EGR        TIM_REG(TIM3_BASE, TIM_EGR)
#define TIM3_CCMR1      TIM_REG(TIM3_BASE, TIM_CCMR1)
#define TIM3_CCMR2      TIM_REG(TIM3_BASE, TIM_CCMR2)
#define TIM3_CCER       TIM_REG(TIM3_BASE, TIM_CCER)
#define TIM3_CNT        TIM_REG(TIM3_BASE, TIM_CNT)
#define TIM3_PSC        TIM_REG(TIM3_BASE, TIM_PSC)
#define TIM3_ARR        TIM_REG(TIM3_BASE, TIM_ARR)
#define TIM3_CCR1       TIM_REG(TIM3_BASE, TIM_CCR1)
#define TIM3_CCR2       TIM_REG(TIM3_BASE, TIM_CCR2)
#define TIM3_CCR3       TIM_REG(TIM3_BASE, TIM_CCR3)
#define TIM3_CCR4       TIM_REG(TIM3_BASE, TIM_CCR4)
#define TIM3_DCR        TIM_REG(TIM3_BASE, TIM_DCR)
#define TIM3_DMAR       TIM_REG(TIM3_BASE, TIM_DMAR)

#define TIM4_CR1        TIM_REG(TIM4_BASE, TIM_CR1)
#define TIM4_CR2        TIM_REG(TIM4_BASE, TIM_CR2)
#define TIM4_SMCR       TIM_REG(TIM4_BASE, TIM_SMCR)
#define TIM4_DIER       TIM_REG(TIM4_BASE, TIM_DIER)
#define TIM4_SR         TIM_REG(TIM4_BASE, TIM_SR)
#define TIM4_EGR        TIM_REG(TIM4_BASE, TIM_EGR)
#define TIM4_CCMR1      TIM_REG(TIM4_BASE, TIM_CCMR1)
#define TIM4_CCMR2      TIM_REG(TIM4_BASE, TIM_CCMR2)
#define TIM4_CCER       TIM_REG(TIM4_BASE, TIM_CCER)
#define TIM4_CNT        TIM_REG(TIM4_BASE, TIM_CNT)
#define TIM4_PSC        TIM_REG(TIM4_BASE, TIM_PSC)
#define TIM4_ARR        TIM_REG(TIM4_BASE, TIM_ARR)
#define TIM4_CCR1       TIM_REG(TIM4_BASE, TIM_CCR1)
#define TIM4_CCR2       TIM_REG(TIM4_BASE, TIM_CCR2)
#define TIM4_CCR3       TIM_REG(TIM4_BASE, TIM_CCR3)
#define TIM4_CCR4       TIM_REG(TIM4_BASE, TIM_CCR4)
#define TIM4_DCR        TIM_REG(TIM4_BASE, TIM_DCR)
#define TIM4_DMAR       TIM_REG(TIM4_BASE, TIM_DMAR)

#define TIM5_CR1        TIM_REG(TIM5_BASE, TIM_CR1)
#define TIM5_CR2        TIM_REG(TIM5_BASE, TIM_CR2)
#define TIM5_SMCR       TIM_REG(TIM5_BASE, TIM_SMCR)
#define TIM5_DIER       TIM_REG(TIM5_BASE, TIM_DIER)
#define TIM5_SR         TIM_REG(TIM5_BASE, TIM_SR)
#define TIM5_EGR        TIM_REG(TIM5_BASE, TIM_EGR)
#define TIM5_CCMR1      TIM_REG(TIM5_BASE, TIM_CCMR1)
#define TIM5_CCMR2      TIM_REG(TIM5_BASE, TIM_CCMR2)
#define TIM5_CCER       TIM_REG(TIM5_BASE, TIM_CCER)
#define TIM5_CNT        TIM_REG(TIM5_BASE, TIM_CNT)
#define TIM5_PSC        TIM_REG(TIM5_BASE, TIM_PSC)
#define TIM5_ARR        TIM_REG(TIM5_BASE, TIM_ARR)
#define TIM5_CCR1       TIM_REG(TIM5_BASE, TIM_CCR1)
#define TIM5_CCR2       TIM_REG(TIM5_BASE, TIM_CCR2)
#define TIM5_CCR3       TIM_REG(TIM5_BASE, TIM_CCR3)
#define TIM5_CCR4       TIM_REG(TIM5_BASE, TIM_CCR4)
#define TIM5_DCR        TIM_REG(TIM5_BASE, TIM_DCR)
#define TIM5_DMAR       TIM_REG(TIM5_BASE, TIM_DMAR)

#define TIM9_CR1        TIM_REG(TIM9_BASE, TIM_CR1)
#define TIM9_SMCR       TIM_REG(TIM9_BASE, TIM_SMCR)
#define TIM9_DIER       TIM_REG(TIM9_BASE, TIM_DIER)
#define TIM9_SR         TIM_REG(TIM9_BASE, TIM_SR)
#define TIM9_EGR        TIM_REG(TIM9_BASE, TIM_EGR)
#define TIM9_CCMR1      TIM_REG(TIM9_BASE, TIM_CCMR1)
#define TIM9_CCER       TIM_REG(TIM9_BASE, TIM_CCER)
#define TIM9_CNT        TIM_REG(TIM9_BASE, TIM_CNT)
#define TIM9_PSC        TIM_REG(TIM9_BASE, TIM_PSC)
#define TIM9_ARR        TIM_REG(TIM9_BASE, TIM_ARR)
#define TIM9_CCR1       TIM_REG(TIM9_BASE, TIM_CCR1)
#define TIM9_CCR2       TIM_REG(TIM9_BASE, TIM_CCR2)

#define TIM10_CR1       TIM_REG(TIM10_BASE, TIM_CR1)
#define TIM10_DIER      TIM_REG(TIM10_BASE, TIM_DIER)
#define TIM10_SR        TIM_REG(TIM10_BASE, TIM_SR)
#define TIM10_EGR       TIM_REG(TIM10_BASE, TIM_EGR)
#define TIM10_CCMR1     TIM_REG(TIM10_BASE, TIM_CCMR1)
#define TIM10_CCER      TIM_REG(TIM10_BASE, TIM_CCER)
#define TIM10_CNT       TIM_REG(TIM10_BASE, TIM_CNT)
#define TIM10_PSC       TIM_REG(TIM10_BASE, TIM_PSC)
#define TIM10_ARR       TIM_REG(TIM10_BASE, TIM_ARR)
#define TIM10_CCR1      TIM_REG(TIM10_BASE, TIM_CCR1)

#define TIM11_CR1       TIM_REG(TIM11_BASE, TIM_CR1)
#define TIM11_DIER      TIM_REG(TIM11_BASE, TIM_DIER)
#define TIM11_SR        TIM_REG(TIM11_BASE, TIM_SR)
#define TIM11_EGR        TIM_REG(TIM11_BASE, TIM_EGR)
#define TIM11_CCMR1     TIM_REG(TIM11_BASE, TIM_CCMR1)
#define TIM11_CCER      TIM_REG(TIM11_BASE, TIM_CCER)
#define TIM11_CNT       TIM_REG(TIM11_BASE, TIM_CNT)
#define TIM11_PSC       TIM_REG(TIM11_BASE, TIM_PSC)
#define TIM11_ARR       TIM_REG(TIM11_BASE, TIM_ARR)
#define TIM11_CCR1      TIM_REG(TIM11_BASE, TIM_CCR1)

/* =========================================================================
 * USART / UART
 * USART1 0x40011000, USART2 0x40004400, USART6 0x40011400
 * ========================================================================= */
#define USART1_BASE     (APB2_BASE + 0x1000UL)
#define USART2_BASE     (APB1_BASE + 0x4400UL)
#define USART6_BASE     (APB2_BASE + 0x1400UL)

#define USART_SR        0x00UL
#define USART_DR        0x04UL
#define USART_BRR       0x08UL
#define USART_CR1       0x0CUL
#define USART_CR2       0x10UL
#define USART_CR3       0x14UL
#define USART_GTPR      0x18UL

#define USART_REG(base, off) GPIO_REG((base), (off))

#define USART1_SR       USART_REG(USART1_BASE, USART_SR)
#define USART1_DR       USART_REG(USART1_BASE, USART_DR)
#define USART1_BRR      USART_REG(USART1_BASE, USART_BRR)
#define USART1_CR1      USART_REG(USART1_BASE, USART_CR1)
#define USART1_CR2      USART_REG(USART1_BASE, USART_CR2)
#define USART1_CR3      USART_REG(USART1_BASE, USART_CR3)
#define USART1_GTPR     USART_REG(USART1_BASE, USART_GTPR)

#define USART2_SR       USART_REG(USART2_BASE, USART_SR)
#define USART2_DR       USART_REG(USART2_BASE, USART_DR)
#define USART2_BRR      USART_REG(USART2_BASE, USART_BRR)
#define USART2_CR1      USART_REG(USART2_BASE, USART_CR1)
#define USART2_CR2      USART_REG(USART2_BASE, USART_CR2)
#define USART2_CR3      USART_REG(USART2_BASE, USART_CR3)
#define USART2_GTPR     USART_REG(USART2_BASE, USART_GTPR)

#define USART6_SR       USART_REG(USART6_BASE, USART_SR)
#define USART6_DR       USART_REG(USART6_BASE, USART_DR)
#define USART6_BRR      USART_REG(USART6_BASE, USART_BRR)
#define USART6_CR1      USART_REG(USART6_BASE, USART_CR1)
#define USART6_CR2      USART_REG(USART6_BASE, USART_CR2)
#define USART6_CR3      USART_REG(USART6_BASE, USART_CR3)
#define USART6_GTPR     USART_REG(USART6_BASE, USART_GTPR)

/* =========================================================================
 * SPI
 * SPI1 0x40013000, SPI2 0x40003800, SPI3 0x40003C00
 * ========================================================================= */
#define SPI1_BASE       (APB2_BASE + 0x3000UL)
#define SPI2_BASE       (APB1_BASE + 0x3800UL)
#define SPI3_BASE       (APB1_BASE + 0x3C00UL)

#define SPI_CR1         0x00UL
#define SPI_CR2         0x04UL
#define SPI_SR          0x08UL
#define SPI_DR          0x0CUL
#define SPI_CRCPR       0x10UL
#define SPI_RXCRCR      0x14UL
#define SPI_TXCRCR      0x18UL
#define SPI_I2SCFGR     0x1CUL
#define SPI_I2SPR       0x20UL

#define SPI_REG(base, off) GPIO_REG((base), (off))

#define SPI1_CR1        SPI_REG(SPI1_BASE, SPI_CR1)
#define SPI1_CR2        SPI_REG(SPI1_BASE, SPI_CR2)
#define SPI1_SR         SPI_REG(SPI1_BASE, SPI_SR)
#define SPI1_DR         SPI_REG(SPI1_BASE, SPI_DR)
#define SPI1_CRCPR      SPI_REG(SPI1_BASE, SPI_CRCPR)
#define SPI1_RXCRCR     SPI_REG(SPI1_BASE, SPI_RXCRCR)
#define SPI1_TXCRCR     SPI_REG(SPI1_BASE, SPI_TXCRCR)
#define SPI1_I2SCFGR    SPI_REG(SPI1_BASE, SPI_I2SCFGR)
#define SPI1_I2SPR      SPI_REG(SPI1_BASE, SPI_I2SPR)

#define SPI2_CR1        SPI_REG(SPI2_BASE, SPI_CR1)
#define SPI2_CR2        SPI_REG(SPI2_BASE, SPI_CR2)
#define SPI2_SR         SPI_REG(SPI2_BASE, SPI_SR)
#define SPI2_DR         SPI_REG(SPI2_BASE, SPI_DR)
#define SPI2_CRCPR      SPI_REG(SPI2_BASE, SPI_CRCPR)
#define SPI2_RXCRCR     SPI_REG(SPI2_BASE, SPI_RXCRCR)
#define SPI2_TXCRCR     SPI_REG(SPI2_BASE, SPI_TXCRCR)
#define SPI2_I2SCFGR    SPI_REG(SPI2_BASE, SPI_I2SCFGR)
#define SPI2_I2SPR      SPI_REG(SPI2_BASE, SPI_I2SPR)

#define SPI3_CR1        SPI_REG(SPI3_BASE, SPI_CR1)
#define SPI3_CR2        SPI_REG(SPI3_BASE, SPI_CR2)
#define SPI3_SR         SPI_REG(SPI3_BASE, SPI_SR)
#define SPI3_DR         SPI_REG(SPI3_BASE, SPI_DR)
#define SPI3_CRCPR      SPI_REG(SPI3_BASE, SPI_CRCPR)
#define SPI3_RXCRCR     SPI_REG(SPI3_BASE, SPI_RXCRCR)
#define SPI3_TXCRCR     SPI_REG(SPI3_BASE, SPI_TXCRCR)
#define SPI3_I2SCFGR    SPI_REG(SPI3_BASE, SPI_I2SCFGR)
#define SPI3_I2SPR      SPI_REG(SPI3_BASE, SPI_I2SPR)

/* =========================================================================
 * I2C
 * I2C1 0x40005400, I2C2 0x40005800, I2C3 0x40005C00
 * ========================================================================= */
#define I2C1_BASE       (APB1_BASE + 0x5400UL)
#define I2C2_BASE       (APB1_BASE + 0x5800UL)
#define I2C3_BASE       (APB1_BASE + 0x5C00UL)

#define I2C_CR1         0x00UL
#define I2C_CR2         0x04UL
#define I2C_OAR1        0x08UL
#define I2C_OAR2        0x0CUL
#define I2C_DR          0x10UL
#define I2C_SR1         0x14UL
#define I2C_SR2         0x18UL
#define I2C_CCR         0x1CUL
#define I2C_TRISE       0x20UL
#define I2C_FLTR        0x24UL

#define I2C_REG(base, off) GPIO_REG((base), (off))

#define I2C1_CR1        I2C_REG(I2C1_BASE, I2C_CR1)
#define I2C1_CR2        I2C_REG(I2C1_BASE, I2C_CR2)
#define I2C1_OAR1       I2C_REG(I2C1_BASE, I2C_OAR1)
#define I2C1_OAR2       I2C_REG(I2C1_BASE, I2C_OAR2)
#define I2C1_DR         I2C_REG(I2C1_BASE, I2C_DR)
#define I2C1_SR1        I2C_REG(I2C1_BASE, I2C_SR1)
#define I2C1_SR2        I2C_REG(I2C1_BASE, I2C_SR2)
#define I2C1_CCR        I2C_REG(I2C1_BASE, I2C_CCR)
#define I2C1_TRISE      I2C_REG(I2C1_BASE, I2C_TRISE)
#define I2C1_FLTR       I2C_REG(I2C1_BASE, I2C_FLTR)

#define I2C2_CR1        I2C_REG(I2C2_BASE, I2C_CR1)
#define I2C2_CR2        I2C_REG(I2C2_BASE, I2C_CR2)
#define I2C2_OAR1       I2C_REG(I2C2_BASE, I2C_OAR1)
#define I2C2_OAR2       I2C_REG(I2C2_BASE, I2C_OAR2)
#define I2C2_DR         I2C_REG(I2C2_BASE, I2C_DR)
#define I2C2_SR1        I2C_REG(I2C2_BASE, I2C_SR1)
#define I2C2_SR2        I2C_REG(I2C2_BASE, I2C_SR2)
#define I2C2_CCR        I2C_REG(I2C2_BASE, I2C_CCR)
#define I2C2_TRISE      I2C_REG(I2C2_BASE, I2C_TRISE)
#define I2C2_FLTR       I2C_REG(I2C2_BASE, I2C_FLTR)

#define I2C3_CR1        I2C_REG(I2C3_BASE, I2C_CR1)
#define I2C3_CR2        I2C_REG(I2C3_BASE, I2C_CR2)
#define I2C3_OAR1       I2C_REG(I2C3_BASE, I2C_OAR1)
#define I2C3_OAR2       I2C_REG(I2C3_BASE, I2C_OAR2)
#define I2C3_DR         I2C_REG(I2C3_BASE, I2C_DR)
#define I2C3_SR1        I2C_REG(I2C3_BASE, I2C_SR1)
#define I2C3_SR2        I2C_REG(I2C3_BASE, I2C_SR2)
#define I2C3_CCR        I2C_REG(I2C3_BASE, I2C_CCR)
#define I2C3_TRISE      I2C_REG(I2C3_BASE, I2C_TRISE)
#define I2C3_FLTR       I2C_REG(I2C3_BASE, I2C_FLTR)

/* =========================================================================
 * ADC
 * ADC1 base 0x40012000
 * ========================================================================= */
#define ADC1_BASE       (APB2_BASE + 0x2000UL)

#define ADC_SR          0x00UL
#define ADC_CR1         0x04UL
#define ADC_CR2         0x08UL
#define ADC_SMPR1       0x0CUL
#define ADC_SMPR2       0x10UL
#define ADC_JOFR1       0x14UL
#define ADC_JOFR2       0x18UL
#define ADC_JOFR3       0x1CUL
#define ADC_JOFR4       0x20UL
#define ADC_HTR         0x24UL
#define ADC_LTR         0x28UL
#define ADC_SQR1        0x2CUL
#define ADC_SQR2        0x30UL
#define ADC_SQR3        0x34UL
#define ADC_JSQR        0x38UL
#define ADC_JDR1        0x3CUL
#define ADC_JDR2        0x40UL
#define ADC_JDR3        0x44UL
#define ADC_JDR4        0x48UL
#define ADC_DR          0x4CUL
#define ADC_CCR         0x304UL

#define ADC1_SR         GPIO_REG(ADC1_BASE, ADC_SR)
#define ADC1_CR1        GPIO_REG(ADC1_BASE, ADC_CR1)
#define ADC1_CR2        GPIO_REG(ADC1_BASE, ADC_CR2)
#define ADC1_SMPR1      GPIO_REG(ADC1_BASE, ADC_SMPR1)
#define ADC1_SMPR2      GPIO_REG(ADC1_BASE, ADC_SMPR2)
#define ADC1_JOFR1      GPIO_REG(ADC1_BASE, ADC_JOFR1)
#define ADC1_JOFR2      GPIO_REG(ADC1_BASE, ADC_JOFR2)
#define ADC1_JOFR3      GPIO_REG(ADC1_BASE, ADC_JOFR3)
#define ADC1_JOFR4      GPIO_REG(ADC1_BASE, ADC_JOFR4)
#define ADC1_HTR        GPIO_REG(ADC1_BASE, ADC_HTR)
#define ADC1_LTR        GPIO_REG(ADC1_BASE, ADC_LTR)
#define ADC1_SQR1       GPIO_REG(ADC1_BASE, ADC_SQR1)
#define ADC1_SQR2       GPIO_REG(ADC1_BASE, ADC_SQR2)
#define ADC1_SQR3       GPIO_REG(ADC1_BASE, ADC_SQR3)
#define ADC1_JSQR       GPIO_REG(ADC1_BASE, ADC_JSQR)
#define ADC1_JDR1       GPIO_REG(ADC1_BASE, ADC_JDR1)
#define ADC1_JDR2       GPIO_REG(ADC1_BASE, ADC_JDR2)
#define ADC1_JDR3       GPIO_REG(ADC1_BASE, ADC_JDR3)
#define ADC1_JDR4       GPIO_REG(ADC1_BASE, ADC_JDR4)
#define ADC1_DR         GPIO_REG(ADC1_BASE, ADC_DR)
#define ADC_CCR_REG     GPIO_REG(ADC1_BASE, ADC_CCR)

/* =========================================================================
 * EXTI / SYSCFG (external interrupts and GPIO interrupt routing)
 * ========================================================================= */
#define EXTI_BASE       0x40013C00UL
#define SYSCFG_BASE     (APB2_BASE + 0x3800UL)

#define EXTI_IMR        GPIO_REG(EXTI_BASE, 0x00UL)
#define EXTI_EMR        GPIO_REG(EXTI_BASE, 0x04UL)
#define EXTI_RTSR       GPIO_REG(EXTI_BASE, 0x08UL)
#define EXTI_FTSR       GPIO_REG(EXTI_BASE, 0x0CUL)
#define EXTI_SWIER      GPIO_REG(EXTI_BASE, 0x10UL)
#define EXTI_PR         GPIO_REG(EXTI_BASE, 0x14UL)

#define SYSCFG_MEMRMP   GPIO_REG(SYSCFG_BASE, 0x00UL)
#define SYSCFG_PMC      GPIO_REG(SYSCFG_BASE, 0x04UL)
#define SYSCFG_EXTICR1  GPIO_REG(SYSCFG_BASE, 0x08UL)
#define SYSCFG_EXTICR2  GPIO_REG(SYSCFG_BASE, 0x0CUL)
#define SYSCFG_EXTICR3  GPIO_REG(SYSCFG_BASE, 0x10UL)
#define SYSCFG_EXTICR4  GPIO_REG(SYSCFG_BASE, 0x14UL)

/* =========================================================================
 * DMA
 * DMA1 0x40026000, DMA2 0x40026400
 * ========================================================================= */
#define DMA1_BASE       0x40026000UL
#define DMA2_BASE       0x40026400UL

#define DMA_LISR        0x00UL
#define DMA_HISR        0x04UL
#define DMA_LIFCR       0x08UL
#define DMA_HIFCR       0x0CUL
#define DMA_SxCR(n)     (0x10UL + ((uint32_t)(n) * 0x18UL))
#define DMA_SxNDTR(n)   (0x14UL + ((uint32_t)(n) * 0x18UL))
#define DMA_SxPAR(n)    (0x18UL + ((uint32_t)(n) * 0x18UL))
#define DMA_SxM0AR(n)   (0x1CUL + ((uint32_t)(n) * 0x18UL))
#define DMA_SxM1AR(n)   (0x20UL + ((uint32_t)(n) * 0x18UL))
#define DMA_SxFCR(n)    (0x24UL + ((uint32_t)(n) * 0x18UL))

#define DMA1_LISR       GPIO_REG(DMA1_BASE, DMA_LISR)
#define DMA1_HISR       GPIO_REG(DMA1_BASE, DMA_HISR)
#define DMA1_LIFCR      GPIO_REG(DMA1_BASE, DMA_LIFCR)
#define DMA1_HIFCR      GPIO_REG(DMA1_BASE, DMA_HIFCR)

#define DMA2_LISR       GPIO_REG(DMA2_BASE, DMA_LISR)
#define DMA2_HISR       GPIO_REG(DMA2_BASE, DMA_HISR)
#define DMA2_LIFCR      GPIO_REG(DMA2_BASE, DMA_LIFCR)
#define DMA2_HIFCR      GPIO_REG(DMA2_BASE, DMA_HIFCR)

/* =========================================================================
 * Flash interface
 * ========================================================================= */
#define FLASH_BASE      0x40023C00UL
#define FLASH_ACR       GPIO_REG(FLASH_BASE, 0x00UL)
#define FLASH_KEYR      GPIO_REG(FLASH_BASE, 0x04UL)
#define FLASH_OPTKEYR   GPIO_REG(FLASH_BASE, 0x08UL)
#define FLASH_SR        GPIO_REG(FLASH_BASE, 0x0CUL)
#define FLASH_CR        GPIO_REG(FLASH_BASE, 0x10UL)
#define FLASH_OPTCR     GPIO_REG(FLASH_BASE, 0x14UL)

/* =========================================================================
 * PWR
 * ========================================================================= */
#define PWR_BASE        0x40007000UL
#define PWR_CR          GPIO_REG(PWR_BASE, 0x00UL)
#define PWR_CSR         GPIO_REG(PWR_BASE, 0x04UL)

/* =========================================================================
 * Independent Watchdog / Window Watchdog
 * ========================================================================= */
#define IWDG_BASE       0x40003000UL
#define IWDG_KR         GPIO_REG(IWDG_BASE, 0x00UL)
#define IWDG_PR         GPIO_REG(IWDG_BASE, 0x04UL)
#define IWDG_RLR        GPIO_REG(IWDG_BASE, 0x08UL)
#define IWDG_SR         GPIO_REG(IWDG_BASE, 0x0CUL)

#define WWDG_BASE       0x40002C00UL
#define WWDG_CR         GPIO_REG(WWDG_BASE, 0x00UL)
#define WWDG_CFR        GPIO_REG(WWDG_BASE, 0x04UL)
#define WWDG_SR         GPIO_REG(WWDG_BASE, 0x08UL)

/* =========================================================================
 * RTC / Backup
 * ========================================================================= */
#define RTC_BASE        0x40002800UL
#define RTC_TR          GPIO_REG(RTC_BASE, 0x00UL)
#define RTC_DR          GPIO_REG(RTC_BASE, 0x04UL)
#define RTC_CR          GPIO_REG(RTC_BASE, 0x08UL)
#define RTC_ISR         GPIO_REG(RTC_BASE, 0x0CUL)
#define RTC_PRER        GPIO_REG(RTC_BASE, 0x10UL)
#define RTC_WUTR        GPIO_REG(RTC_BASE, 0x14UL)
#define RTC_CALIBR      GPIO_REG(RTC_BASE, 0x18UL)
#define RTC_ALRMAR      GPIO_REG(RTC_BASE, 0x1CUL)
#define RTC_ALRMBR      GPIO_REG(RTC_BASE, 0x20UL)
#define RTC_WPR         GPIO_REG(RTC_BASE, 0x24UL)
#define RTC_SSR         GPIO_REG(RTC_BASE, 0x28UL)
#define RTC_SHIFTR      GPIO_REG(RTC_BASE, 0x2CUL)
#define RTC_TSTR        GPIO_REG(RTC_BASE, 0x30UL)
#define RTC_TSDR        GPIO_REG(RTC_BASE, 0x34UL)
#define RTC_TSSSR       GPIO_REG(RTC_BASE, 0x38UL)
#define RTC_CALR        GPIO_REG(RTC_BASE, 0x3CUL)
#define RTC_TAFCR       GPIO_REG(RTC_BASE, 0x40UL)
#define RTC_ALRMASSR    GPIO_REG(RTC_BASE, 0x44UL)
#define RTC_ALRMBSSR    GPIO_REG(RTC_BASE, 0x48UL)
#define RTC_BKP0R       GPIO_REG(RTC_BASE, 0x50UL)
#define RTC_BKP1R       GPIO_REG(RTC_BASE, 0x54UL)
#define RTC_BKP2R       GPIO_REG(RTC_BASE, 0x58UL)
#define RTC_BKP3R       GPIO_REG(RTC_BASE, 0x5CUL)
#define RTC_BKP4R       GPIO_REG(RTC_BASE, 0x60UL)

/* =========================================================================
 * Convenience bit masks for common register programming
 * ========================================================================= */
#define BIT(n)          (1UL << (n))
#define GPIO_MODE_INPUT 0UL
#define GPIO_MODE_OUTPUT 1UL
#define GPIO_MODE_AF    2UL
#define GPIO_MODE_ANALOG 3UL

#define GPIO_OTYPE_PP   0UL
#define GPIO_OTYPE_OD   1UL

#define GPIO_SPEED_LOW  0UL
#define GPIO_SPEED_MED  1UL
#define GPIO_SPEED_HIGH 2UL
#define GPIO_SPEED_VHIGH 3UL

#define GPIO_PUPD_NONE  0UL
#define GPIO_PUPD_UP    1UL
#define GPIO_PUPD_DOWN  2UL

//#endif /* CCU6_H */


#endif /* CCU6_H_ */
