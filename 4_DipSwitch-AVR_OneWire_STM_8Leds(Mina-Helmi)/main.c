/*
 * main.c
 *
 *  Created on: Jan 4, 2020
 *      Author: moham
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include <util/delay.h>
#include"DIO_interface.h"
#include"PORT_interface.h"

#define PORT_OUT 'C'
#define PIN_OUT 1

#define PORT_DIP_SW 'D'

/* amount of time to waste as a new frame indicator */
#define FRAME_START_PAUSE_TIME_US (u16)3000
/* amount of time to hold data without any change */
#define DATA_HOLD_TIME_US         (u16)1000
/* amount of time to purposefully skip to make sure the receiver detected the new level/change */
#define EDGE_TIMEOUT_US           (u16)500

void createFrameStart(void);
void createHighLevel(void);
void createLowLevel(void);
void createRisingEdge(void);
void createFallingEdge(void);

void main(void)
{
	portInitialize();

	/* initially pause the receiver */
	createLowLevel();

	/* turn pull-up resistors for port of DIP SW
	for (u8 i = 0; i < 8; i++)
	{
		setPinValue(PORT_DIP_SW, i, 1);
	}*/

	u8 value = 0;

	_delay_ms(3000);

	while (1)
	{
		/* get DIP SW bits */
		value = 0;

		for (u8 i = 0; i < 8; i++)
		{
			value |= getPinValue(PORT_DIP_SW, i) << i;
		}

		/* invert value bits because switches are pulled-up
		 * by default (when not pressed) */
		value = ~value;

		/* start the frame by creating a rising edge */
		createFrameStart();

		/* send frame data (8-bits) */
		for (u8 i = 8; i > 0; i--)
		{
			/* if data bit is high create a falling edge because the first level (high) represents the bit */
			if (GET_BIT(value, i - 1) == 1)
			{
				createFallingEdge();
			}
			else /* if data bit is low create a rising edge because the first level (low) represents the bit */
			{
				createRisingEdge();
			}
		}

		/* create a low level to pause the receiver */
		createLowLevel();
	}
}

void createFrameStart(void)
{
	/* send a low level to pause the receiver */
	createLowLevel();

	_delay_us(FRAME_START_PAUSE_TIME_US);

	/* create a rising edge (start signal) */
	createRisingEdge();
}

void createHighLevel(void)
{
	setPinValue(PORT_OUT, PIN_OUT, 1);
}

void createLowLevel(void)
{
	setPinValue(PORT_OUT, PIN_OUT, 0);
}

void createRisingEdge(void)
{
	createLowLevel();
	_delay_us(DATA_HOLD_TIME_US);
	createHighLevel();
	_delay_us(EDGE_TIMEOUT_US);
}

void createFallingEdge(void)
{
	createHighLevel();
	_delay_us(DATA_HOLD_TIME_US);
	createLowLevel();
	_delay_us(EDGE_TIMEOUT_US);
}
