/*
 * xpt2046_touch.h
 *
 *  Created on: 5 апр. 2020 г.
 *      Author: dima
 */

#ifndef XPT2046_TOUCH_H_
#define XPT2046_TOUCH_H_

//#define TOUCH_SPI_PTR 		 &hspi1

#define TOUCH_CS_SELECT      gpio_bit_reset(TOUCH_CS_GPIO_Port, TOUCH_CS_Pin)
#define TOUCH_CS_UNSELECT    gpio_bit_set(TOUCH_CS_GPIO_Port, TOUCH_CS_Pin)

uint8_t ILI9341_TouchGetCoordinates(uint16_t *x, uint16_t *y);

#endif
