/******************************************************************************
* File Name: ADC.c
* Description:  This file contains API definitions for ADC functionality
* Tool-Chain: AVR GCC
*
*  Modification History:
*  Created by:      Rutvij_20050502    V1.0      22/Mar/21
*  Description:     V1.0
******************************************************************************/

/******************************************************************************
*                      Includes
******************************************************************************/
#include"ADC.h"

/******************************************************************************
*                      Public functions definitions
******************************************************************************/

/******************************************************************************
* Name: ADC_init ()
* Description:  Initialize the ADC module

* Arguments: None
* Returns: None
******************************************************************************/
void ADC_init()
{
    DDRC=0x00;
    ADMUX=0x00;
    ADMUX|=(1<<REFS0);
    ADCSRA=0x00;
    ADCSRA|=(1<<ADEN);
}

/******************************************************************************
* Name: ADC_enable ()
* Description:  Enables the ADC module

* Arguments: None
* Returns: None
******************************************************************************/
void ADC_enable()
{
    ADCSRA|=(1<<ADEN);
}

/******************************************************************************
* Name: ADC_disbable ()
* Description:  Disables the ADC module

* Arguments: None
* Returns: None
******************************************************************************/
void ADC_disable()
{
    ADCSRA&=~(1<<ADEN);
}

/******************************************************************************
* Name: ADC_Read ()
* Description:

* Arguments: channel
* Returns: ADC value
******************************************************************************/
int ADC_Read(char channel)
{
    int Ain,AinLow;
    ADMUX=0x00;
    ADMUX|=(1<<REFS0);
    ADMUX=ADMUX|(channel & 0x0f);
    ADCSRA |= (1<<ADSC);
    while((ADCSRA&(1<<ADSC))==0);
    _delay_us(100);
    AinLow = (int)ADCL;
    Ain = (int)ADCH*256;
    Ain = Ain + AinLow;
    return Ain;
}

/******************************************************************************
*                      End of File
******************************************************************************/

