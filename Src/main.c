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
#include <stdio.h>
#include <stdlib.h>

//#include "diag/trace.h"
#include "timer.h"

#include "main.h"
#include "img.h"
#include "fonts.h"

int main(int argc, char *argv[]);

void rcu_config(void);
void gpio_config(void);
void spi_config(void);
void timer_config(void);
void nvic_config(void);

void bat_level(uint8_t lvl, uint16_t x, uint16_t y);
void radio_level(uint8_t lvl, uint16_t x, uint16_t y);

extern uint8_t out_symbol;
extern FontDef Font_11x18;

uint8_t p;

// ----------------------------------------------------------------------------
//
// Print a greeting message on the trace device and enter a loop
// to count seconds.
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the DEBUG output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace-impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//
// ----------------------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

int main(int argc, char *argv[]) {

	//nvic_irq_enable(SPI0_IRQn, 0, 1);

	//systick_config();
	timer_start();
	/* enable peripheral clock */
	rcu_config();
	/* configure GPIO */
	gpio_config();

	/* configure SPI*/
	spi_config();
	nvic_config();
	timer_config();

	gpio_bit_set(GPIOB, GPIO_PIN_0);

	DISP_CS_UNSELECT;
	spi_enable(SPI0);

	ILI9341_Init();

	ILI9341_Set_Rotation(SCREEN_VERTICAL_1);

	ILI9341_Fill_Screen(ORANGE);

	ILI9341_Draw_Filled_Rectangle_Coord(0, 0, 320, 30, DARKGREY);

	uint32_t size_img = sizeof(img_logo);

//	gpio_bit_reset(GPIOB, GPIO_PIN_5);
//	gpio_bit_reset(GPIOB, GPIO_PIN_6);
//	gpio_bit_reset(GPIOB, GPIO_PIN_7);
	ILI9341_Draw_Image(img_logo, 0, 210, 71, 30, size_img);
	ILI9341_WriteString(14, 216, "LAST", Font_11x18, BLACK, TRANSPARENT);
	ILI9341_Draw_Image(img_logo, 124, 210, 71, 30, size_img);
	ILI9341_WriteString(138, 216, "MENU", Font_11x18, BLACK, TRANSPARENT);
	ILI9341_Draw_Image(img_logo, 249, 210, 71, 30, size_img);
	ILI9341_WriteString(263, 216, "NEXT", Font_11x18, BLACK, TRANSPARENT);

	while (1) {

		if (p != out_symbol) {
			switch (out_symbol) {
			case 11:
				ILI9341_Draw_Image(img_logo1, 0, 210, 71, 30, size_img);
				ILI9341_WriteString(14, 216, "LAST", Font_11x18, BLACK,
				TRANSPARENT);
				break;
			case 22:
				ILI9341_Draw_Image(img_logo1, 124, 210, 71, 30, size_img);
				ILI9341_WriteString(138, 216, "MENU", Font_11x18, BLACK,
				TRANSPARENT);
				break;
			case 33:
				ILI9341_Draw_Image(img_logo1, 249, 210, 71, 30, size_img);
				ILI9341_WriteString(263, 216, "NEXT", Font_11x18, BLACK,
				TRANSPARENT);
				break;
			case 1:
				ILI9341_Draw_Image(img_logo, 0, 210, 71, 30, size_img);
				ILI9341_WriteString(14, 216, "LAST", Font_11x18, BLACK,
				TRANSPARENT);
				break;
			case 2:
				//ILI9341_Fill_Screen(BLUE);
				break;
			case 3:
				//ILI9341_Fill_Screen(PINK);
				break;
			case 4:
				//ILI9341_Fill_Screen(ORANGE);
				break;
			case 5:
				ILI9341_Draw_Image(img_logo, 124, 210, 71, 30, size_img);
				ILI9341_WriteString(138, 216, "MENU", Font_11x18, BLACK,
				TRANSPARENT);
				break;
				//ILI9341_Fill_Screen(GREEN);
				break;
			case 6:
				//ILI9341_Fill_Screen(YELLOW);
				break;
			case 7:
				ILI9341_Draw_Image(img_logo, 249, 210, 71, 30, size_img);
				ILI9341_WriteString(263, 216, "NEXT", Font_11x18, BLACK,
				TRANSPARENT);
				break;
			case 8:
				//ILI9341_Fill_Screen(NAVY);
				break;
			case 9:
				//ILI9341_Fill_Screen(MAGENTA);
				break;
			}
			p = out_symbol;
		}
		for (uint8_t i = 100; i > 0; i--) {
			bat_level(i, 42, 7);
			radio_level(i, 1, 5);
			timer_sleep(100);
		}

//		ILI9341_Draw_Image(img_logo, 0, 210, 71, 30, size_img);
//		ILI9341_Draw_Image(img_logo, 249, 210, 71, 30, size_img);
//		timer_sleep(3000);
//		ILI9341_Draw_Image(img_logo1, 0, 210, 71, 30, size_img);
//		ILI9341_Draw_Image(img_logo1, 249, 210, 71, 30, size_img);
//		timer_sleep(3000);

// Infinite loop, never return.
	}
}

void nvic_config(void) {
	nvic_priority_group_set(NVIC_PRIGROUP_PRE1_SUB3);
	nvic_irq_enable(TIMER7_UP_TIMER12_IRQn, 0, 1);
}

void rcu_config(void) {
	rcu_periph_clock_enable(RCU_GPIOA);
	rcu_periph_clock_enable(RCU_GPIOB);
	rcu_periph_clock_enable(RCU_GPIOC);
	rcu_periph_clock_enable(RCU_GPIOD);
	rcu_periph_clock_enable(RCU_SPI0);
	rcu_periph_clock_enable(RCU_SYSCFG);
	rcu_periph_clock_enable(RCU_TIMER7);
}

void gpio_config(void) {
	/* configure SPI1 GPIO */
	gpio_af_set(GPIOA, GPIO_AF_5, GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);
	gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE,
	GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);
	gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,
	GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);

	/*DISP_CS*/
	gpio_mode_set(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_4);
	gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,
	GPIO_PIN_4);
	/*DISP_LED*/
	gpio_mode_set(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,
	GPIO_PIN_0 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);
	gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,
	GPIO_PIN_0 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);
	/*DISP_DC  DISP_RST*/
	gpio_mode_set(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,
	GPIO_PIN_4 | GPIO_PIN_5);
	gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,
	GPIO_PIN_4 | GPIO_PIN_5);

	gpio_mode_set(GPIOB, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP,
	GPIO_PIN_3 | GPIO_PIN_4);
	gpio_mode_set(GPIOD, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP,
	GPIO_PIN_2);

}

void spi_config(void) {
	spi_parameter_struct spi_init_struct;

	/* configure SPI1 parameter */
	spi_init_struct.trans_mode = SPI_TRANSMODE_FULLDUPLEX;
	spi_init_struct.device_mode = SPI_MASTER;

	spi_init_struct.frame_size = SPI_FRAMESIZE_8BIT;

	spi_init_struct.clock_polarity_phase = SPI_CK_PL_LOW_PH_1EDGE;
	spi_init_struct.nss = SPI_NSS_SOFT;
	spi_init_struct.prescale = SPI_PSC_2;
	spi_init_struct.endian = SPI_ENDIAN_MSB;

	spi_init(SPI0, &spi_init_struct);

#if SPI_CRC_ENABLE
    /* configure SPI CRC function */
    spi_crc_polynomial_set(SPI1, 7);
    spi_crc_polynomial_set(SPI3, 7);
    spi_crc_on(SPI1);
    spi_crc_on(SPI3);
#endif /* enable CRC function */
}

void timer_config(void) {

	timer_parameter_struct timer_initpara;

	rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4);

	timer_deinit(TIMER7);
	/* TIMER1 configuration */
	timer_initpara.prescaler = 10000;
	timer_initpara.alignedmode = TIMER_COUNTER_EDGE;
	timer_initpara.counterdirection = TIMER_COUNTER_UP;
	timer_initpara.period = 100;
	timer_initpara.clockdivision = TIMER_CKDIV_DIV1;
	timer_initpara.repetitioncounter = 0;
	timer_init(TIMER6, &timer_initpara);
	timer_init(TIMER7, &timer_initpara);

	timer_interrupt_enable(TIMER7, TIMER_INT_UP);
	/* auto-reload preload enable */

	timer_auto_reload_shadow_enable(TIMER7);
	/* auto-reload preload enable */

	timer_enable(TIMER7);
}

void bat_level(uint8_t lvl, uint16_t x, uint16_t y) {

	ILI9341_Draw_Vertical_Line(x, y+1, 14, BLACK);
	ILI9341_Draw_Horizontal_Line(x+1, y, 24, BLACK);
	ILI9341_Draw_Vertical_Line(x+25, y+1, 14, BLACK);
	ILI9341_Draw_Horizontal_Line(x+1, y+15, 24, BLACK);

	ILI9341_Draw_Vertical_Line(x+5, y+1, 14, BLACK);
	ILI9341_Draw_Vertical_Line(x+10, y+1, 14, BLACK);
	ILI9341_Draw_Vertical_Line(x+15, y+1, 14, BLACK);
	ILI9341_Draw_Vertical_Line(x+20, y+1, 14, BLACK);

	ILI9341_Draw_Horizontal_Line(x+26, y+5, 2, BLACK);
	ILI9341_Draw_Vertical_Line(x+26, y+6, 4, DARKGREY);
	ILI9341_Draw_Vertical_Line(x+27, y+6, 4, BLACK);
	ILI9341_Draw_Horizontal_Line(x+26, y+10, 2, BLACK);

	if (lvl < 20) {
		ILI9341_Draw_Rectangle(x+1, y+1, 4, 14, RED);
		ILI9341_Draw_Rectangle(x+6, y+1, 4, 14, LIGHTGREY);
		ILI9341_Draw_Rectangle(x+11, y+1, 4, 14, LIGHTGREY);
		ILI9341_Draw_Rectangle(x+16, y+1, 4, 14, LIGHTGREY);
		ILI9341_Draw_Rectangle(x+21, y+1, 4, 14, LIGHTGREY);
	} else if (lvl > 20 && lvl < 40) {
		ILI9341_Draw_Rectangle(x+1, y+1, 4, 14, ORANGE);
		ILI9341_Draw_Rectangle(x+6, y+1, 4, 14, ORANGE);
		ILI9341_Draw_Rectangle(x+11, y+1, 4, 14, LIGHTGREY);
		ILI9341_Draw_Rectangle(x+16, y+1, 4, 14, LIGHTGREY);
		ILI9341_Draw_Rectangle(x+21, y+1, 4, 14, LIGHTGREY);
	} else if (lvl > 40 && lvl < 60) {
		ILI9341_Draw_Rectangle(x+1, y+1, 4, 14, ORANGE);
		ILI9341_Draw_Rectangle(x+6, y+1, 4, 14, ORANGE);
		ILI9341_Draw_Rectangle(x+11, y+1, 4, 14, ORANGE);
		ILI9341_Draw_Rectangle(x+16, y+1, 4, 14, LIGHTGREY);
		ILI9341_Draw_Rectangle(x+21, y+1, 4, 14, LIGHTGREY);
	} else if (lvl > 60 && lvl < 80) {
		ILI9341_Draw_Rectangle(x+1, y+1, 4, 14, DARKGREEN);
		ILI9341_Draw_Rectangle(x+6, y+1, 4, 14, DARKGREEN);
		ILI9341_Draw_Rectangle(x+11, y+1, 4, 14, DARKGREEN);
		ILI9341_Draw_Rectangle(x+16, y+1, 4, 14, DARKGREEN);
		ILI9341_Draw_Rectangle(x+21, y+1, 4, 14, LIGHTGREY);
	} else if (lvl > 80 && lvl <= 100) {
		ILI9341_Draw_Rectangle(x+1, y+1, 4, 14, DARKGREEN);
		ILI9341_Draw_Rectangle(x+6, y+1, 4, 14, DARKGREEN);
		ILI9341_Draw_Rectangle(x+11, y+1, 4, 14, DARKGREEN);
		ILI9341_Draw_Rectangle(x+16, y+1, 4, 14, DARKGREEN);
		ILI9341_Draw_Rectangle(x+21, y+1, 4, 14, DARKGREEN);
	}

}

void radio_level(uint8_t lvl, uint16_t x, uint16_t y) {

	ILI9341_Draw_Horizontal_Line(x, y, 16, BLACK);
	ILI9341_Draw_Horizontal_Line(x, y+1, 16, BLACK);
	ILI9341_Draw_Vertical_Line(x+7, y+2, 18, BLACK);
	ILI9341_Draw_Vertical_Line(x+8, y+2, 18, BLACK);
	ILI9341_Random_line(x+1, y+2, x+6, y+7, BLACK);
	ILI9341_Random_line(x+14, y+2, x+9, y+7, BLACK);

	if (lvl < 25) {
		ILI9341_Draw_Rectangle(x+13, y+15, 3, 5, BLACK);
		ILI9341_Draw_Rectangle(x+18, y+10, 3, 10, LIGHTGREY);
		ILI9341_Draw_Rectangle(x+23, y+5, 3, 15, LIGHTGREY);
		ILI9341_Draw_Rectangle(x+28, y, 3, 20, LIGHTGREY);
	} else if (lvl > 25 && lvl < 50) {
		ILI9341_Draw_Rectangle(x+13, y+15, 3, 5, BLACK);
		ILI9341_Draw_Rectangle(x+18, y+10, 3, 10, BLACK);
		ILI9341_Draw_Rectangle(x+23, y+5, 3, 15, LIGHTGREY);
		ILI9341_Draw_Rectangle(x+28, y, 3, 20, LIGHTGREY);
	} else if (lvl > 50 && lvl < 75) {
		ILI9341_Draw_Rectangle(x+13, y+15, 3, 5, BLACK);
		ILI9341_Draw_Rectangle(x+18, y+10, 3, 10, BLACK);
		ILI9341_Draw_Rectangle(x+23, y+5, 3, 15, BLACK);
		ILI9341_Draw_Rectangle(x+28, y, 3, 20, LIGHTGREY);
	} else if (lvl > 75 && lvl < 100) {
		ILI9341_Draw_Rectangle(x+13, y+15, 3, 5, BLACK);
		ILI9341_Draw_Rectangle(x+18, y+10, 3, 10, BLACK);
		ILI9341_Draw_Rectangle(x+23, y+5, 3, 15, BLACK);
		ILI9341_Draw_Rectangle(x+28, y, 3, 20, BLACK);
	}
}

//#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
