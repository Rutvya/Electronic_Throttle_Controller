/******************************************************************************
* File Name: GPIO.c
* Description:  This file contains API definitions for GPIO functionality
* Tool-Chain: AVR GCC
*
*  Modification History:
*  Created by:      Rutvij_20050502    V1.0      26/Feb/21
*  Description:     V1.0
******************************************************************************/

/******************************************************************************
*                      Includes
******************************************************************************/
#include "GPIO.h"

/******************************************************************************
*                      Public functions definitions
******************************************************************************/

/******************************************************************************
* Name: GPIOConfig (pin, mode)
* Description:  Configures the mode of the pin as INPUT/PULLUP or OUTPUT

* Arguments: pin and mode
* Returns: None
******************************************************************************/
void GPIOConfig(const char pin[3],uint8_t mode)
{
    uint8_t bit;
    bit=pin[2]-'0';
    if(mode==OUTPUT)
    {
        if(!strcmp(pin,"PC6")||!strcmp(pin,"PC5")||!strcmp(pin,"PC4")||!strcmp(pin,"PC3")||
           !strcmp(pin,"PC2")||!strcmp(pin,"PC1")||!strcmp(pin,"PC0"))
        {
            SET_BIT(DDRC,bit);
        }
        if(!strcmp(pin,"PB7")||!strcmp(pin,"PB6")||!strcmp(pin,"PB5")||!strcmp(pin,"PB4")||!strcmp(pin,"PB3")||
           !strcmp(pin,"PB2")||!strcmp(pin,"PB1")||!strcmp(pin,"PB0"))
        {
            SET_BIT(DDRB,bit);
        }
        if(!strcmp(pin,"PD7")||!strcmp(pin,"PD6")||!strcmp(pin,"PD5")||!strcmp(pin,"PD4")||!strcmp(pin,"PD3")||
           !strcmp(pin,"PD2")||!strcmp(pin,"PD1")||!strcmp(pin,"PD0"))
        {
            SET_BIT(DDRD,bit);
        }
    }
    else
    {
        if(!strcmp(pin,"PC6")||!strcmp(pin,"PC5")||!strcmp(pin,"PC4")||!strcmp(pin,"PC3")||
           !strcmp(pin,"PC2")||!strcmp(pin,"PC1")||!strcmp(pin,"PC0"))
        {
            CLR_BIT(DDRC,bit);
            SET_BIT(PORTC,bit);
        }
        if(!strcmp(pin,"PB7")||!strcmp(pin,"PB6")||!strcmp(pin,"PB5")||!strcmp(pin,"PB4")||!strcmp(pin,"PB3")||
           !strcmp(pin,"PB2")||!strcmp(pin,"PB1")||!strcmp(pin,"PB0"))
        {
            CLR_BIT(DDRB,bit);
            SET_BIT(PORTB,bit);
        }
        if(!strcmp(pin,"PD7")||!strcmp(pin,"PD6")||!strcmp(pin,"PD5")||!strcmp(pin,"PD4")||!strcmp(pin,"PD3")||
           !strcmp(pin,"PD2")||!strcmp(pin,"PD1")||!strcmp(pin,"PD0"))
        {
            CLR_BIT(DDRD,bit);
            SET_BIT(PORTD,bit);
        }
    }
}

/******************************************************************************
* Name: GPIOPinWrite(pin,state);
* Description:  Writes HIGH/LOW to pin

* Arguments: pin and state
* Returns: None
******************************************************************************/
void GPIOPinWrite(const char pin[3],uint8_t state)
{
    uint8_t bit;
    bit=pin[2]-'0';
    if(state==HIGH)
    {
        if(!strcmp(pin,"PC6")||!strcmp(pin,"PC5")||!strcmp(pin,"PC4")||!strcmp(pin,"PC3")||
           !strcmp(pin,"PC2")||!strcmp(pin,"PC1")||!strcmp(pin,"PC0"))
        {
            SET_BIT(PORTC,bit);
        }
        if(!strcmp(pin,"PB7")||!strcmp(pin,"PB6")||!strcmp(pin,"PB5")||!strcmp(pin,"PB4")||!strcmp(pin,"PB3")||
           !strcmp(pin,"PB2")||!strcmp(pin,"PB1")||!strcmp(pin,"PB0"))
        {
            SET_BIT(PORTB,bit);
        }
        if(!strcmp(pin,"PD7")||!strcmp(pin,"PD6")||!strcmp(pin,"PD5")||!strcmp(pin,"PD4")||!strcmp(pin,"PD3")||
           !strcmp(pin,"PD2")||!strcmp(pin,"PD1")||!strcmp(pin,"PD0"))
        {
            SET_BIT(PORTD,bit);
        }
    }
    else
    {
        if(!strcmp(pin,"PC6")||!strcmp(pin,"PC5")||!strcmp(pin,"PC4")||!strcmp(pin,"PC3")||
           !strcmp(pin,"PC2")||!strcmp(pin,"PC1")||!strcmp(pin,"PC0"))
        {
            CLR_BIT(PORTC,bit);
        }
        if(!strcmp(pin,"PB7")||!strcmp(pin,"PB6")||!strcmp(pin,"PB5")||!strcmp(pin,"PB4")||!strcmp(pin,"PB3")||
           !strcmp(pin,"PB2")||!strcmp(pin,"PB1")||!strcmp(pin,"PB0"))
        {
            CLR_BIT(PORTB,bit);
        }
        if(!strcmp(pin,"PD7")||!strcmp(pin,"PD6")||!strcmp(pin,"PD5")||!strcmp(pin,"PD4")||!strcmp(pin,"PD3")||
           !strcmp(pin,"PD2")||!strcmp(pin,"PD1")||!strcmp(pin,"PD0"))
        {
            CLR_BIT(PORTD,bit);
        }
    }
}

/******************************************************************************
* Name: GPIOPinRead(pin);
* Description:  Read pin data

* Arguments: pin
* Returns: state
******************************************************************************/
uint8_t GPIOPinRead(const char pin[3])
{
    uint8_t bit;
    uint8_t state=HIGH;
    bit=pin[2]-'0';
    if(!strcmp(pin,"PC6")||!strcmp(pin,"PC5")||!strcmp(pin,"PC4")||!strcmp(pin,"PC3")||
       !strcmp(pin,"PC2")||!strcmp(pin,"PC1")||!strcmp(pin,"PC0"))
    {
        if(PINC&(1<<bit))
        {
            state=HIGH;
        }
        else
        {
            state=LOW;
        }
    }
    if(!strcmp(pin,"PB7")||!strcmp(pin,"PB6")||!strcmp(pin,"PB5")||!strcmp(pin,"PB4")||!strcmp(pin,"PB3")||
       !strcmp(pin,"PB2")||!strcmp(pin,"PB1")||!strcmp(pin,"PB0"))
    {
        if(PINB&(1<<bit))
        {
            state=HIGH;
        }
        else
        {
            state=LOW;
        }
    }
    if(!strcmp(pin,"PD7")||!strcmp(pin,"PD6")||!strcmp(pin,"PD5")||!strcmp(pin,"PD4")||!strcmp(pin,"PD3")||
       !strcmp(pin,"PD2")||!strcmp(pin,"PD1")||!strcmp(pin,"PD0"))
    {
        if(PIND&(1<<bit))
        {
            state=HIGH;
        }
        else
        {
            state=LOW;
        }
    }
    return state;
}

/******************************************************************************
*                      End of File
******************************************************************************/
