/*
 * 7seg.h
 *
 *  Created on: 28 lut 2017
 *      Author: Mieszko
 *       Usage: Initiate display before main loop
 *       		Put multiplex7seg function in interrupt callback
 *       		Use displayNum whenever you want to change displayed number
 *       		Operates on 4 digit displays
 */

#ifndef SEG_H
#define SEG_H

#define INVERT 1 // inverts outputs, use if LOW enables diode/transistor

#include "stm32f4xx_hal.h"

enum SegNums {SEG7_0 = 0xEB, SEG7_1 = 0x88, SEG7_2 = 0xD3, SEG7_3 = 0xDA,
	SEG7_4 = 0xB8, SEG7_5 = 0x7A, SEG7_6 = 0x7B, SEG7_7 = 0xC8,
	SEG7_8 = 0xFB, SEG7_9 = 0xFA};

/**
 * function has to be called inside interrupt
 */
void multiplex7seg();

/**
 * Displays number on display
 * @param num
 */
void displayNum(int num);

/**
 * Gets pinout from enum, private function
 * @param i
 * @return
 */
int get7SegCipher(int i);

/**
 * Initializes display, call before main loop
 * @param ae_port
 * Port of led pins
 * @param first_port
 * @param first_pin
 * Port and pin of first block
 * @param second_port
 * @param second_pin
 * Port and pin of second block
 * @param third_port
 * @param third_pin
 * Port and pin of third block
 * @param fourth_port
 * @param fourth_pin
 * Port and pin of fourth block
 */
void init7seg(GPIO_TypeDef * ae_port, GPIO_TypeDef * first_port, int first_pin, GPIO_TypeDef * second_port, int second_pin,
		GPIO_TypeDef * third_port, int third_pin, GPIO_TypeDef * fourth_port, int fourth_pin);

#endif /* 7SEG_H_ */
