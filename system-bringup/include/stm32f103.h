#ifndef STM32F103_H
#define STM32F103_H

#include <stdint.h>

typedef struct {
    volatile uint32_t ISER[3];
    uint32_t RESERVED0[29];
    volatile uint32_t ICER[3];
    uint32_t RESERVED1[29];
    volatile uint32_t ISPR[3];
    uint32_t RESERVED2[29];
    volatile uint32_t ICPR[3];
    uint32_t RESERVED3[29];
    volatile uint32_t IABR[3];
    uint32_t RESERVED4[61];
    volatile uint8_t IPR[84];
    uint32_t RESERVED5[683];
    volatile uint32_t STIR;
} NVIC_TypeDef;

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VAL;
    volatile uint32_t CALIB;
} STK_TypeDef;

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t APB1RSTR;
    volatile uint32_t AHBENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t APB1ENR;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
} RCC_TypeDef;

typedef struct {
    volatile uint32_t EVCR;
    volatile uint32_t MAPR;
    volatile uint32_t EXTICR[4];
    uint32_t RESERVED;
    volatile uint32_t MAPR2; 
} AFIO_TypeDef;

typedef struct {
    volatile uint32_t ACR;
} FLASH_TypeDef;

typedef struct {
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
} GPIO_TypeDef;

typedef struct {
    volatile uint32_t IMR;
    volatile uint32_t EMR;
    volatile uint32_t RTSR;
    volatile uint32_t FTSR;
    volatile uint32_t SWIER;
    volatile uint32_t PR;
} EXTI_TypeDef;

typedef enum {
    GPIO_INPUT_ADC,
    GPIO_INPUT_PULLUP,
    GPIO_INPUT_PULLDOWN,
    GPIO_OUTPUT
} gpio_mode_t;

typedef enum {
    AFIO_PORT_A,
    AFIO_PORT_B,
    AFIO_PORT_C,
    AFIO_PORT_D,
    AFIO_PORT_E,
    AFIO_PORT_F,
    AFIO_PORT_G
} afio_port_t;

typedef enum {
    RISING,
    FALLING
} exti_trigger_t;

#define NVIC ((NVIC_TypeDef *)0xE000E100u)

#define STK ((STK_TypeDef *)0xE000E010u)

#define RCC ((RCC_TypeDef *)0x40021000u)

#define AFIO ((AFIO_TypeDef *)0x40010000u)

#define FLASH ((FLASH_TypeDef *)0X40022000u)

#define GPIOA ((GPIO_TypeDef *)0x40010800u)
#define GPIOB ((GPIO_TypeDef *)0x40010C00u)
#define GPIOC ((GPIO_TypeDef *)0x40011000u)
#define GPIOD ((GPIO_TypeDef *)0x40011400u)
#define GPIOE ((GPIO_TypeDef *)0x40011800u)
#define GPIOF ((GPIO_TypeDef *)0x40011C00u)
#define GPIOG ((GPIO_TypeDef *)0X40012000u)

#define EXTI ((EXTI_TypeDef *)0x40010400u)

#endif