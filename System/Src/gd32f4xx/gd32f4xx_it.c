/*!
 \file    gd32f4xx_it.c
 \brief   interrupt service routines

 \version 2016-08-15, V1.0.0, firmware for GD32F4xx
 \version 2018-12-12, V2.0.0, firmware for GD32F4xx
 \version 2020-09-30, V2.1.0, firmware for GD32F4xx
 \version 2022-03-09, V3.0.0, firmware for GD32F4xx
 */

/*
 Copyright (c) 2022, GigaDevice Semiconductor Inc.

 Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 3. Neither the name of the copyright holder nor the names of its contributors
 may be used to endorse or promote products derived from this software without
 specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 OF SUCH DAMAGE.
 */

#include "gd32f4xx_it.h"
#include "systick.h"

__IO uint32_t step = 1;

uint8_t a = 0, b = 0, c = 0, out_symbol, out_state;
/*!
 \brief      this function handles NMI exception
 \param[in]  none
 \param[out] none
 \retval     none
 */
void NMI_Handler(void) {
}

/*!
 \brief      this function handles HardFault exception
 \param[in]  none
 \param[out] none
 \retval     none
 */
void HardFault_Handler(void) {
	/* if Hard Fault exception occurs, go to infinite loop */
	while (1)
		;
}

/*!
 \brief      this function handles MemManage exception
 \param[in]  none
 \param[out] none
 \retval     none
 */
void MemManage_Handler(void) {
	/* if Memory Manage exception occurs, go to infinite loop */
	while (1)
		;
}

/*!
 \brief      this function handles BusFault exception
 \param[in]  none
 \param[out] none
 \retval     none
 */
void BusFault_Handler(void) {
	/* if Bus Fault exception occurs, go to infinite loop */
	while (1)
		;
}

/*!
 \brief      this function handles UsageFault exception
 \param[in]  none
 \param[out] none
 \retval     none
 */
void UsageFault_Handler(void) {
	/* if Usage Fault exception occurs, go to infinite loop */
	while (1)
		;
}

/*!
 \brief      this function handles SVC exception
 \param[in]  none
 \param[out] none
 \retval     none
 */
void SVC_Handler(void) {
}

/*!
 \brief      this function handles DebugMon exception
 \param[in]  none
 \param[out] none
 \retval     none
 */
void DebugMon_Handler(void) {
}

/*!
 \brief      this function handles PendSV exception
 \param[in]  none
 \param[out] none
 \retval     none
 */
void PendSV_Handler(void) {
}

/*!
 \brief      this function handles SysTick exception
 \param[in]  none
 \param[out] none
 \retval     none
 */
//void SysTick_Handler(void)
//{
//    timer_event_software_generate(TIMER0,TIMER_EVENT_SRC_CMTG);
//}
/*!
 \brief      this function handles TIMER0 interrupt request
 \param[in]  none
 \param[out] none
 \retval     none
 */
void TIMER7_UP_TIMER12_IRQHandler(void) {
	/* clear TIMER interrupt flag */
	timer_interrupt_flag_clear(TIMER7, TIMER_INT_UP);

	out_state++;

	turn_on_line(out_state);
	if (out_state == 3) {
		out_state = 0;
	}
}

void turn_on_line(uint8_t out) {
	switch (out) {
	case 1:
		gpio_bit_set(GPIOB, GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);
		gpio_bit_reset(GPIOB, GPIO_PIN_5);
		if (RESET == gpio_input_bit_get(GPIOD, GPIO_PIN_2)) {
			out_symbol = 1;
		} else if (RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_3)) {
			out_symbol = 2;
		} else if (RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_4)) {
			out_symbol = 3;
		}
		break;
	case 2:
		gpio_bit_set(GPIOB, GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);
		gpio_bit_reset(GPIOB, GPIO_PIN_6);
		if (RESET == gpio_input_bit_get(GPIOD, GPIO_PIN_2)) {
			out_symbol = 4;
		} else if (RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_3)) {
			out_symbol = 5;
		} else if (RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_4)) {
			out_symbol = 6;
		}
		break;
	case 3:
		gpio_bit_set(GPIOB, GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);
		gpio_bit_reset(GPIOB, GPIO_PIN_7);
		if (RESET == gpio_input_bit_get(GPIOD, GPIO_PIN_2)) {
			out_symbol = 7;
		} else if (RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_3)) {
			out_symbol = 8;
		} else if (RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_4)) {
			out_symbol = 9;
		}
		break;
	}

}
