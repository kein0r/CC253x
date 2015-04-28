/** @ingroup Timer1
 * @{
 */
#ifndef TIMER1_H_
#define TIMER1_H_
/*
  Copyright (c) 2014 Jan Rüdiger.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Credits:
*/
/*******************| Inclusions |*************************************/
#include <PlatformTypes.h>
   
/*******************| Macros |*****************************************/
#define T1CTL_DIV                               0x0c
#define T1CTL_DIV_DIV1                          0x00
#define T1CTL_DIV_DIV8                          0x04
#define T1CTL_DIV_DIV32                         0x08
#define T1CTL_DIV_DIV128                        0x0c
#define T1CTL_MODE                              0x03
#define T1CTL_MODE_OPERATIONSUSPENDED           0x00
#define T1CTL_MODE_FREERUNNING                  0x01
#define T1CTL_MODE_MODULO                       0x02
#define T1CTL_MODE_UPDOWN                       0x03
#define T1CTL_MASK                              (T1CTL_DIV | T1CTL_MODE)
    
#define T1STAT_OVFIF                            0x20
#define T1STAT_CH4IF                            0x10
#define T1STAT_CH3IF                            0x08
#define T1STAT_CH2IF                            0x04
#define T1STAT_CH1IF                            0x02
#define T1STAT_CH0IF                            0x01

#define T1CCTL0_RFIRQ_ENABLE                    0x80
#define T1CCTL0_RFIRQ_DISABLE                   0x00
#define T1CCTL0_IM                              0x40
#define T1CCTL0_CMP                             0x38
#define T1CCTL0_CMP_SETOUTPUTONCOMPARE          0x00
#define T1CCTL0_CMP_CLEAROUTPUTONCOMPARE        0x08
#define T1CCTL0_CMP_TOGGLEOUTPUTONCOMPARE       0x20
#define T1CCTL0_CMP_SETOUTPUTONCOMPARECLEARON0  0x18
#define T1CCTL0_CMP_CLEAROUTPUTONCOMPARESETON0  0x20
#define T1CCTL0_CMP_RESERVED                    0x28
#define T1CCTL0_CMP_RESERVED2                   0x30
#define T1CCTL0_CMP_INITIALIZEOUTPUTPIN         0x38
#define T1CCTL0_MODE_CAPTUREMODE                0x00
#define T1CCTL0_MODE_COMPAREMODE                0x04
#define T1CCTL0_

/*******************| Type definitions |*******************************/
/**
 * Structure to access T1CNTx register. This will only work if
 * compiler is placing uint8_t on byte boundary. If not something like
 * #pragma pack must be used.
*/
typedef union
{
  uint16_t value;
  struct {
    uint8_t T1CNTL;
    uint8_t T1CNTH;
  } regs;
} Timer1_t;

/*******************| Type definitions |*******************************/

/*******************| Global variables |*******************************/

/*******************| Function prototypes |****************************/
void Timer1_startSynchronous(uint8_t mode, uint16_t overflowValue);
void Timer1_read(Timer1_t *timerPtr);

#endif
/** @}*/