#include "7seg.h"
int segTable[4];
GPIO_TypeDef * segPorts[4];
int segPins[4];
int segMulti = 0;
GPIO_TypeDef * ae_pins;
void init7seg(GPIO_TypeDef * ae_port, GPIO_TypeDef * first_port, int first_pin, GPIO_TypeDef * second_port, int second_pin,
		GPIO_TypeDef * third_port, int third_pin, GPIO_TypeDef * fourth_port, int fourth_pin)
{
	ae_pins = ae_port;
	if(INVERT) ae_pins->BSRR = 0xFF;
	else ae_pins->BSRR = 0xFF << 16U;

	segPorts[0] = first_port;
	segPins[0] = first_pin;
	segPorts[1] = second_port;
	segPins[1] = second_pin;
	segPorts[2] = third_port;
	segPins[2] = third_pin;
	segPorts[3] = fourth_port;
	segPins[3] = fourth_pin;
	HAL_GPIO_WritePin(segPorts[0], segPins[0], INVERT);
	HAL_GPIO_WritePin(segPorts[1], segPins[1], INVERT);
	HAL_GPIO_WritePin(segPorts[2], segPins[2], INVERT);
	HAL_GPIO_WritePin(segPorts[3], segPins[3], INVERT);
}
void multiplex7seg()
{
	HAL_GPIO_WritePin(segPorts[segMulti], segPins[segMulti], INVERT);
	segMulti++;
	if (segMulti == 4) segMulti = 0;
	if(INVERT) {
		ae_pins->BSRR = 0xFF;
		ae_pins->BSRR = segTable[segMulti] << 16U;
	}else{
		ae_pins->BSRR = 0xFF << 16U;
		ae_pins->BSRR = segTable[segMulti];
	}

	HAL_GPIO_WritePin(segPorts[segMulti], segPins[segMulti], !INVERT);
}
void displayNum(int num)
{
	int j = 0;
	for(j = 0; j < 4; j++)
	{
		segTable[j] = get7SegCipher(num % 10);
		num /= 10;
	}
}
int get7SegCipher(int i)
{
	switch(i)
	{
	case 0:
		return SEG7_0;
		break;
	case 1:
		return SEG7_1;
		break;
	case 2:
		return SEG7_2;
		break;
	case 3:
		return SEG7_3;
		break;
	case 4:
		return SEG7_4;
		break;
	case 5:
		return SEG7_5;
		break;
	case 6:
		return SEG7_6;
		break;
	case 7:
		return SEG7_7;
		break;
	case 8:
		return SEG7_8;
		break;
	case 9:
		return SEG7_9;
		break;
	default:
		return SEG7_0;
		break;
	}
	return SEG7_0;
}
