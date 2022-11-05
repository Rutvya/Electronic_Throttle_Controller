/******************************************************************************
* File Name: GPIO.h
* Description:  This file contains function Prototypes of GPIO.c
* Tool-Chain: AVR GCC
*
* Modification History:
*  Created by:      Rutvij_2005502   V1.0      26/Feb/21
*  Description:     V1.0
*
******************************************************************************/
#ifndef GPIO_H
#define GPIO_H

/******************************************************************************
*                      Includes
******************************************************************************/
#include<stdint.h>
#include<string.h>
#include<avr/io.h>
#include<avr/interrupt.h>

/******************************************************************************
*                      Defines and data types
******************************************************************************/
#define SET_BIT(PORT, BIT) PORT |= (1 << BIT)
#define CLR_BIT(PORT, BIT) PORT &= ~(1 << BIT)
#define INPUT 0
#define OUTPUT 1
#define HIGH 1
#define LOW 0

/******************************************************************************
*                      Public function prototypes
******************************************************************************/
void GPIOConfig(const char pin[3],uint8_t mode);
void GPIOPinWrite(const char pin[3],uint8_t state);
uint8_t GPIOPinRead(const char pin[3]);

#endif
/******************************************************************************
*                      End of File
******************************************************************************/
