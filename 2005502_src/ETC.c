/******************************************************************************
* File Name: ETC.c
* Description:  This file contains API definitions for electronic throttle control(ETC)
* Tool-Chain: AVR GCC
*
*  Modification History:
*  Created by:      Rutvij_20050502    V1.0      24/Mar/21
*  Description:     V1.0
******************************************************************************/

/******************************************************************************
*                      Includes
******************************************************************************/
#include "ETC.h"

/******************************************************************************
*                      Global variables
******************************************************************************/
struct FLAGS FLAG;

/******************************************************************************
*                      Public functions definitions
******************************************************************************/
/******************************************************************************
* Name: ETC_init ()
* Description:  Initialize the ETC module

* Arguments: None
* Returns: None
******************************************************************************/
void ETC_init()
{
    GPIOConfig("PD6",OUTPUT);
    GPIOConfig("PB1",OUTPUT);
    GPIOConfig("PD0",INPUT);
    GPIOConfig("PD2",INPUT);
    GPIOConfig("PD3",INPUT);
    GPIOConfig("PD4",INPUT);
    GPIOPinWrite("PB1",LOW);
    PWM_init();
    DDRC=0x00;
    PWM_enable();
    ADC_init();
    ADC_enable();
}

/******************************************************************************
* Name: ETC_off ()
* Description:  Turn off the throttle when engine off

* Arguments: None
* Returns: None
******************************************************************************/
void ETC_off()
{
    PWM_disable();
    GPIOPinWrite("PB1",LOW);
    OCR0A=0;
}

/******************************************************************************
* Name: ETC_Limp ()
* Description:  Limp mode operation

* Arguments: None
* Returns: None
******************************************************************************/
void ETC_Limp()
{
    PWM_enable();
    GPIOPinWrite("PB1",HIGH);
    OCR0A=25;
}

/******************************************************************************
* Name: ETC_APS1 ()
* Description:  Operation of ETC in APS1 mode

* Arguments: None
* Returns: None
******************************************************************************/
void ETC_APS1()
{
    PWM_enable();
    GPIOPinWrite("PB1",LOW);
    OCR0A=25+(ADC_Read(0)/4.6);
}

/******************************************************************************
* Name: ETC_APS2 ()
* Description:  Operation of ETC in APS2 mode

* Arguments: None
* Returns: None
******************************************************************************/
void ETC_APS2()
{
    PWM_enable();
    GPIOPinWrite("PB1",LOW);
    OCR0A=25+(ADC_Read(1)/4.6);
}

/******************************************************************************
* Name: Read_FLAGS ()
* Description:  Read inputs from switches and save it in flags

* Arguments: None
* Returns: None
******************************************************************************/
void Read_FLAGS()
{
    FLAG.engineStatus=GPIOPinRead("PD0");
    FLAG.APS1_fail=GPIOPinRead("PD2");
    FLAG.APS2_fail=GPIOPinRead("PD3");
    FLAG.TPS_fail=GPIOPinRead("PD4");
}

/******************************************************************************
*                      End of File
******************************************************************************/
