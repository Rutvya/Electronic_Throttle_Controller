/******************************************************************************
* File Name: ETC.h
* Description:  This file contains function Prototypes of ETC.c
* Tool-Chain: AVR GCC
*
* Modification History:
*  Created by:      Rutvij_2005502   V1.0      24/Mar/21
*  Description:     V1.0
*
******************************************************************************/
#ifndef ETC_H_INCLUDED
#define ETC_H_INCLUDED

/******************************************************************************
*                      Includes
******************************************************************************/
#include"ADC.h"
#include"GPIO.h"
#include"PWM.h"

/******************************************************************************
*                      Data types
******************************************************************************/
struct FLAGS
{
    volatile uint8_t APS1_fail;
    volatile uint8_t APS2_fail;
    volatile uint8_t TPS_fail;
    volatile uint8_t engineStatus;
};

/******************************************************************************
*                      Public function prototypes
******************************************************************************/
void ETC_init();
void ETC_Limp();
void ETC_APS1();
void ETC_APS2();
void ETC_off();
void Read_FLAGS();

#endif // ETC_H_INCLUDED
/******************************************************************************
*                      End of File
******************************************************************************/

