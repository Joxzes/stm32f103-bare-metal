#include <stdint.h>

extern uint32_t _estack;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

int main(void);

void Reset_Handler(void);
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__((weak, alias("Default_Handler"))); 
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVCall_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));

void WWDG_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void PVD_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TAMPER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RTC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void EXTI0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void DMA1_Channel1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel7_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void ADC1_2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void USB_HP_CAN1_TX_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USB_LP_CAN1_RX0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN1_RX1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN1_SCE_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void EXTI9_5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void TIM1_BRK_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void TIM2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void I2C1_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void SPI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void USART1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void EXTI15_10_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RTCAlarm_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USBWakeUp_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void Default_Handler(void);

__attribute__((section(".isr_vector"), used))
const uintptr_t vector_table[] = {
    (uintptr_t)&_estack,
    (uintptr_t)Reset_Handler,

    (uintptr_t)NMI_Handler,
    (uintptr_t)HardFault_Handler,
    (uintptr_t)MemManage_Handler,
    (uintptr_t)BusFault_Handler,
    (uintptr_t)UsageFault_Handler,

    0,
    0,
    0,
    0,

    (uintptr_t)SVCall_Handler,
    (uintptr_t)DebugMon_Handler,

    0,

    (uintptr_t)PendSV_Handler,
    (uintptr_t)SysTick_Handler,

    (uintptr_t)WWDG_IRQHandler,             // IRQ0:  Window Watchdog
    (uintptr_t)PVD_IRQHandler,              // IRQ1:  PVD through EXTI line
    (uintptr_t)TAMPER_IRQHandler,           // IRQ2:  Tamper
    (uintptr_t)RTC_IRQHandler,              // IRQ3:  RTC
    (uintptr_t)FLASH_IRQHandler,            // IRQ4:  Flash
    (uintptr_t)RCC_IRQHandler,              // IRQ5:  RCC

    (uintptr_t)EXTI0_IRQHandler,            // IRQ6:  EXTI line 0
    (uintptr_t)EXTI1_IRQHandler,            // IRQ7:  EXTI line 1
    (uintptr_t)EXTI2_IRQHandler,            // IRQ8:  EXTI line 2
    (uintptr_t)EXTI3_IRQHandler,            // IRQ9:  EXTI line 3
    (uintptr_t)EXTI4_IRQHandler,            // IRQ10: EXTI line 4

    (uintptr_t)DMA1_Channel1_IRQHandler,     // IRQ11: DMA1 channel 1
    (uintptr_t)DMA1_Channel2_IRQHandler,     // IRQ12: DMA1 channel 2
    (uintptr_t)DMA1_Channel3_IRQHandler,     // IRQ13: DMA1 channel 3
    (uintptr_t)DMA1_Channel4_IRQHandler,     // IRQ14: DMA1 channel 4
    (uintptr_t)DMA1_Channel5_IRQHandler,     // IRQ15: DMA1 channel 5
    (uintptr_t)DMA1_Channel6_IRQHandler,     // IRQ16: DMA1 channel 6
    (uintptr_t)DMA1_Channel7_IRQHandler,     // IRQ17: DMA1 channel 7

    (uintptr_t)ADC1_2_IRQHandler,            // IRQ18: ADC1 and ADC2

    (uintptr_t)USB_HP_CAN1_TX_IRQHandler,    // IRQ19: USB high priority / CAN1 TX
    (uintptr_t)USB_LP_CAN1_RX0_IRQHandler,   // IRQ20: USB low priority / CAN1 RX0
    (uintptr_t)CAN1_RX1_IRQHandler,          // IRQ21: CAN1 RX1
    (uintptr_t)CAN1_SCE_IRQHandler,          // IRQ22: CAN1 status change error

    (uintptr_t)EXTI9_5_IRQHandler,           // IRQ23: EXTI lines 5 through 9

    (uintptr_t)TIM1_BRK_IRQHandler,          // IRQ24: TIM1 break
    (uintptr_t)TIM1_UP_IRQHandler,           // IRQ25: TIM1 update
    (uintptr_t)TIM1_TRG_COM_IRQHandler,      // IRQ26: TIM1 trigger and commutation
    (uintptr_t)TIM1_CC_IRQHandler,           // IRQ27: TIM1 capture compare

    (uintptr_t)TIM2_IRQHandler,              // IRQ28: TIM2
    (uintptr_t)TIM3_IRQHandler,              // IRQ29: TIM3
    (uintptr_t)TIM4_IRQHandler,              // IRQ30: TIM4

    (uintptr_t)I2C1_EV_IRQHandler,           // IRQ31: I2C1 event
    (uintptr_t)I2C1_ER_IRQHandler,           // IRQ32: I2C1 error
    (uintptr_t)I2C2_EV_IRQHandler,           // IRQ33: I2C2 event
    (uintptr_t)I2C2_ER_IRQHandler,           // IRQ34: I2C2 error

    (uintptr_t)SPI1_IRQHandler,              // IRQ35: SPI1
    (uintptr_t)SPI2_IRQHandler,              // IRQ36: SPI2

    (uintptr_t)USART1_IRQHandler,            // IRQ37: USART1
    (uintptr_t)USART2_IRQHandler,            // IRQ38: USART2
    (uintptr_t)USART3_IRQHandler,            // IRQ39: USART3

    (uintptr_t)EXTI15_10_IRQHandler,         // IRQ40: EXTI lines 10 through 15
    (uintptr_t)RTCAlarm_IRQHandler,          // IRQ41: RTC alarm through EXTI line
    (uintptr_t)USBWakeUp_IRQHandler,         // IRQ42: USB wakeup through EXTI line
    };

void Reset_Handler(void) {
    uint32_t *source = &_sidata;
    uint32_t *destination = &_sdata;

    while (destination < &_edata) {
        *destination = *source;
        destination++;
        source++;
    }

    destination = &_sbss;

    while (destination < &_ebss) {
        *destination = 0;
        destination++;
    }

    main();
    
    for (;;) {}
}

void Default_Handler(void) {
    for (;;) {}
}