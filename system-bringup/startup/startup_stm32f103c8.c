#include <stdint.h>

extern uint32_t _estack;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

int main(void);

void Reset_Handler(void);
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVCall_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
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

    (uintptr_t)Default_Handler, // IRQ0: WWDG
    (uintptr_t)Default_Handler, // IRQ1: PVD
    (uintptr_t)Default_Handler, // IRQ2: TAMPER
    (uintptr_t)Default_Handler, // IRQ3: RTC
    (uintptr_t)Default_Handler, // IRQ4: FLASH
    (uintptr_t)Default_Handler, // IRQ5: RCC

    (uintptr_t)Default_Handler, // IRQ6: EXTI0
    (uintptr_t)Default_Handler, // IRQ7: EXTI1
    (uintptr_t)Default_Handler, // IRQ8: EXTI2
    (uintptr_t)Default_Handler, // IRQ9: EXTI3
    (uintptr_t)Default_Handler, // IRQ10: EXTI4

    (uintptr_t)Default_Handler, // IRQ11: DMA1_Channel1
    (uintptr_t)Default_Handler, // IRQ12: DMA1_Channel2
    (uintptr_t)Default_Handler, // IRQ13: DMA1_Channel3
    (uintptr_t)Default_Handler, // IRQ14: DMA1_Channel4
    (uintptr_t)Default_Handler, // IRQ15: DMA1_Channel5
    (uintptr_t)Default_Handler, // IRQ16: DMA1_Channel6
    (uintptr_t)Default_Handler, // IRQ17: DMA1_Channel7

    (uintptr_t)Default_Handler, // IRQ18: ADC1_2

    (uintptr_t)Default_Handler, // IRQ19: USB_HP_CAN_TX
    (uintptr_t)Default_Handler, // IRQ20: USB_LP_CAN_RX0
    (uintptr_t)Default_Handler, // IRQ21: CAN_RX1
    (uintptr_t)Default_Handler, // IRQ22: CAN_SCE

    (uintptr_t)Default_Handler, // IRQ23: EXTI9_5

    (uintptr_t)Default_Handler, // IRQ24: TIM1_BRK
    (uintptr_t)Default_Handler, // IRQ25: TIM1_UP
    (uintptr_t)Default_Handler, // IRQ26: TIM1_TRG_COM
    (uintptr_t)Default_Handler, // IRQ27: TIM1_CC

    (uintptr_t)Default_Handler, // IRQ28: TIM2
    (uintptr_t)Default_Handler, // IRQ29: TIM3
    (uintptr_t)Default_Handler, // IRQ30: TIM4

    (uintptr_t)Default_Handler, // IRQ31: I2C1_EV
    (uintptr_t)Default_Handler, // IRQ32: I2C1_ER
    (uintptr_t)Default_Handler, // IRQ33: I2C2_EV
    (uintptr_t)Default_Handler, // IRQ34: I2C2_ER

    (uintptr_t)Default_Handler, // IRQ35: SPI1
    (uintptr_t)Default_Handler, // IRQ36: SPI2

    (uintptr_t)Default_Handler, // IRQ37: USART1
    (uintptr_t)Default_Handler, // IRQ38: USART2
    (uintptr_t)Default_Handler, // IRQ39: USART3

    (uintptr_t)Default_Handler, // IRQ40: EXTI15_10
    (uintptr_t)Default_Handler, // IRQ41: RTCAlarm
    (uintptr_t)Default_Handler, // IRQ42: USBWakeup
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

void NMI_Handler(void) {
    for (;;) {}
}

void HardFault_Handler(void) {
    for (;;) {}
}

void MemManage_Handler(void) {
    for (;;) {}
}

void BusFault_Handler(void) {
    for (;;) {}
}

void UsageFault_Handler(void) {
    for (;;) {}
}

void SVCall_Handler(void) {
    for (;;) {}
}

void DebugMon_Handler(void) {
    for (;;) {}
}

void PendSV_Handler(void) {
    for (;;) {}
}

void SysTick_Handler(void) {
    for (;;) {}
}

void Default_Handler(void) {
    for (;;) {}
}