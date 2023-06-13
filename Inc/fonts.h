/*
 * fonts.h
 *
 *  Created on: 1 апр. 2020 г.
 *      Author: dima
 */

#ifndef FONTS_H_
#define FONTS_H_

#include "main.h"
#include "ILI9341_GFX.h"

typedef struct {
	const uint8_t width;
	uint8_t height;
	const uint16_t *data;
} FontDef;

#endif /* FONTS_H_ */
