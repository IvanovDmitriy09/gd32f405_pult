/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------
#include "cortexm/exception-handlers.h"

// ----------------------------------------------------------------------------

void __attribute__((weak))
Default_Handler(void);

// Forward declaration of the specific IRQ handlers. These are aliased
// to the Default_Handler, which is a 'forever' loop. When the application
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions
//
void __attribute__ ((weak, alias ("Default_Handler")))
WWDGT_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
LVD_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
TAMPER_STAMP_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
RTC_WKUP_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
FMC_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
RCU_CTC_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
EXTI0_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
EXTI1_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
EXTI2_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
EXTI3_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
EXTI4_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
DMA0_Channel0_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
DMA0_Channel1_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
DMA0_Channel2_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
DMA0_Channel3_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
DMA0_Channel4_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
DMA0_Channel5_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
DMA0_Channel6_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
ADC_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
CAN0_TX_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
CAN0_RX0_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
CAN0_RX1_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
CAN0_EWMC_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
EXTI5_9_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
TIMER0_BRK_TIMER8_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
TIMER0_UP_TIMER9_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
TIMER0_TRG_CMT_TIMER10_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
TIMER0_Channel_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
TIMER1_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
TIMER2_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
TIMER3_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
I2C0_EV_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
I2C0_ER_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
I2C1_EV_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
I2C1_ER_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
SPI0_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
SPI1_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
USART0_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
USART1_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
USART2_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
EXTI10_15_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
RTC_Alarm_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
USBFS_WKUP_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
TIMER7_BRK_TIMER11_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
TIMER7_UP_TIMER12_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
TIMER7_TRG_CMT_TIMER13_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
TIMER7_Channel_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
DMA0_Channel7_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
SDIO_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
TIMER4_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
SPI2_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
UART3_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
UART4_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
TIMER5_DAC_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
TIMER6_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel0_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel1_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel2_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel3_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel4_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
CAN1_TX_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
CAN1_RX0_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
CAN1_RX1_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
CAN1_EWMC_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
USBFS_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel5_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel6_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel7_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
USART5_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
I2C2_EV_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
I2C2_ER_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
USBHS_EP1_Out_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
USBHS_EP1_In_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
USBHS_WKUP_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
USBHS_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
DCI_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
TRNG_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
FPU_IRQHandler(void);

// ----------------------------------------------------------------------------

extern unsigned int _estack;

typedef void
(*const pHandler)(void);

// ----------------------------------------------------------------------------

// The vector table.
// This relies on the linker script to place at correct location in memory.

__attribute__ ((section(".isr_vector"),used))
pHandler __isr_vectors[] = {								//
		(pHandler) &_estack,						// The initial stack pointer
				Reset_Handler,								// The reset handler

				NMI_Handler,								// The NMI handler
				HardFault_Handler,					// The hard fault handler

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
				MemManage_Handler,						// The MPU fault handler
				BusFault_Handler,						// The bus fault handler
				UsageFault_Handler,					// The usage fault handler
#else
	0, 0, 0,				  // Reserved
#endif
				0,											// Reserved
				0, 											// Reserved
				0,											// Reserved
				0,											// Reserved
				SVC_Handler,								// SVCall handler
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
				DebugMon_Handler,						// Debug monitor handler
#else
	0,					  // Reserved
#endif
				0,											// Reserved
				PendSV_Handler,							// The PendSV handler
				SysTick_Handler,						// The SysTick handler

				// ----------------------------------------------------------------------
				// gd32f4xx vectors
				WWDGT_IRQHandler,						//Window Watchdog Timer
				LVD_IRQHandler,					//LVD through EXTI Line detect
				TAMPER_STAMP_IRQHandler,//Tamper and TimeStamp through EXTI Line detect
				RTC_WKUP_IRQHandler,			//RTC Wakeup through EXTI Line
				FMC_IRQHandler,								//FMC
				RCU_CTC_IRQHandler,							//RCU and CTC
				EXTI0_IRQHandler,							//EXTI Line 0
				EXTI1_IRQHandler,							//EXTI Line 1
				EXTI2_IRQHandler,							//EXTI Line 2
				EXTI3_IRQHandler,							//EXTI Line 3
				EXTI4_IRQHandler,							//EXTI Line 4
				DMA0_Channel0_IRQHandler,					//DMA0 Channel0
				DMA0_Channel1_IRQHandler,					//DMA0 Channel1
				DMA0_Channel2_IRQHandler,					//DMA0 Channel2
				DMA0_Channel3_IRQHandler,					//DMA0 Channel3
				DMA0_Channel4_IRQHandler,					//DMA0 Channel4
				DMA0_Channel5_IRQHandler,					//DMA0 Channel5
				DMA0_Channel6_IRQHandler,					//DMA0 Channel6
				ADC_IRQHandler,								//ADC
				CAN0_TX_IRQHandler,							//CAN0 TX
				CAN0_RX0_IRQHandler,						//CAN0 RX0
				CAN0_RX1_IRQHandler,						//CAN0 RX1
				CAN0_EWMC_IRQHandler,						//CAN0 EWMC
				EXTI5_9_IRQHandler,							//EXTI5 to EXTI9
				TIMER0_BRK_TIMER8_IRQHandler,		//TIMER0 Break and TIMER8
				TIMER0_UP_TIMER9_IRQHandler,		//TIMER0 Update and TIMER9
				TIMER0_TRG_CMT_TIMER10_IRQHandler,//TIMER0 Trigger and Commutation and TIMER10
				TIMER0_Channel_IRQHandler,		//TIMER0 Channel Capture Compare
				TIMER1_IRQHandler,				   			//TIMER1
				TIMER2_IRQHandler,				   			//TIMER2
				TIMER3_IRQHandler,				   			//TIMER3
				I2C0_EV_IRQHandler,				   			//I2C0 Event
				I2C0_ER_IRQHandler,				   			//I2C0 Error
				I2C1_EV_IRQHandler,				   			//I2C1 Event
				I2C1_ER_IRQHandler,				   			//I2C1 Error
				SPI0_IRQHandler,				   			//SPI0
				SPI1_IRQHandler,							//SPI1
				USART0_IRQHandler,							//USART0
				USART1_IRQHandler,							//USART1
				USART2_IRQHandler,							//USART2
				EXTI10_15_IRQHandler,						//EXTI10 to EXTI15
				RTC_Alarm_IRQHandler,						//RTC Alarm
				USBFS_WKUP_IRQHandler,						//USBFS Wakeup
				TIMER7_BRK_TIMER11_IRQHandler,		//TIMER7 Break and TIMER11
				TIMER7_UP_TIMER12_IRQHandler,		//TIMER7 Update and TIMER12
				TIMER7_TRG_CMT_TIMER13_IRQHandler,//TIMER7 Trigger and Commutation and TIMER13
				TIMER7_Channel_IRQHandler,		//TIMER7 Channel Capture Compare
				DMA0_Channel7_IRQHandler,					//DMA0 Channel7
				0,											//Reserved
				SDIO_IRQHandler,							//SDIO
				TIMER4_IRQHandler,							//TIMER4
				SPI2_IRQHandler,							//SPI2
				UART3_IRQHandler,							//UART3
				UART4_IRQHandler,							//UART4
				TIMER5_DAC_IRQHandler,	//TIMER5 and DAC0 DAC1 Underrun error
				TIMER6_IRQHandler,							//TIMER6
				DMA1_Channel0_IRQHandler,					//DMA1 Channel0
				DMA1_Channel1_IRQHandler,					//DMA1 Channel1
				DMA1_Channel2_IRQHandler,					//DMA1 Channel2
				DMA1_Channel3_IRQHandler,					//DMA1 Channel3
				DMA1_Channel4_IRQHandler,					//DMA1 Channel4
				0,											//Reserved
				0,											//Reserved
				CAN1_TX_IRQHandler,							//CAN1 TX
				CAN1_RX0_IRQHandler,						//CAN1 RX0
				CAN1_RX1_IRQHandler,						//CAN1 RX1
				CAN1_EWMC_IRQHandler,						//CAN1 EWMC
				USBFS_IRQHandler,							//USBFS
				DMA1_Channel5_IRQHandler,					//DMA1 Channel5
				DMA1_Channel6_IRQHandler,					//DMA1 Channel6
				DMA1_Channel7_IRQHandler,					//DMA1 Channel7
				USART5_IRQHandler,							//USART5
				I2C2_EV_IRQHandler,							//I2C2 Event
				I2C2_ER_IRQHandler,							//I2C2 Error
				USBHS_EP1_Out_IRQHandler,				//USBHS Endpoint 1 Out
				USBHS_EP1_In_IRQHandler,				//USBHS Endpoint 1 in
				USBHS_WKUP_IRQHandler,			//USBHS Wakeup through EXTI Line
				USBHS_IRQHandler,							//USBHS
				DCI_IRQHandler,								//DCI
				0,											//Reserved
				TRNG_IRQHandler,							//TRNG
				FPU_IRQHandler,								//FPU
		};

// ----------------------------------------------------------------------------

// Processor ends up here if an unexpected interrupt occurs or a specific
// handler is not present in the application code.

void __attribute__ ((section(".after_vectors"))) Default_Handler(void) {
	while (1) {
		;
	}
}

// ----------------------------------------------------------------------------
