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
/**
 * interrupt flag bits 
*/
#define TIMIF_OVFIM                             0x20    /** Timer 1 overflow interrupt mask */
#define IEN1_T1IE                               0x02    /** Timer 1 interrupt enable */

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
#define T1CCTL0_CMP_TOGGLEOUTPUTONCOMPARE       0x10
#define T1CCTL0_CMP_SETOUTPUTONCOMPARECLEARON0  0x18
#define T1CCTL0_CMP_CLEAROUTPUTONCOMPARESETON0  0x20
#define T1CCTL0_CMP_RESERVED                    0x28
#define T1CCTL0_CMP_RESERVED2                   0x30
#define T1CCTL0_CMP_INITIALIZEOUTPUTPIN         0x38
#define T1CCTL0_MODE_CAPTUREMODE                0x00
#define T1CCTL0_MODE_COMPAREMODE                0x04
#define T1CCTL0_CAP_NOCOMPARE                   0x00
#define T1CCTL0_CAP                             0x03
#define T1CCTL0_CAP_CAPTUREONRISING             0x01
#define T1CCTL0_CAP_CAPTUREONFALLING            0x02
#define T1CCTL0_CAP_CAPTUREONALL                0x03

#define T1CCTL1_RFIRQ_ENABLE                    0x80
#define T1CCTL1_RFIRQ_DISABLE                   0x00
#define T1CCTL1_IM                              0x40
#define T1CCTL1_CMP                             0x38
#define T1CCTL1_CMP_SETOUTPUTONCOMPARE          0x00
#define T1CCTL1_CMP_CLEAROUTPUTONCOMPARE        0x08
#define T1CCTL1_CMP_TOGGLEOUTPUTONCOMPARE       0x10
#define T1CCTL1_CMP_SETOUTPUTONCOMPARECLEARON0  0x18
#define T1CCTL1_CMP_CLEAROUTPUTONCOMPARESETON0  0x20
#define T1CCTL1_CMP_CLEARWHENEQUALT1CC0         0x28
#define T1CCTL1_CMP_SETWHENEQUALT1CC0           0x30
#define T1CCTL1_CMP_INITIALIZEOUTPUTPIN         0x38
#define T1CCTL1_MODE_CAPTUREMODE                0x00
#define T1CCTL1_MODE_COMPAREMODE                0x04
#define T1CCTL1_CAP_NOCOMPARE                   0x00
#define T1CCTL1_CAP                             0x03
#define T1CCTL1_CAP_CAPTUREONRISING             0x01
#define T1CCTL1_CAP_CAPTUREONFALLING            0x02
#define T1CCTL1_CAP_CAPTUREONALL                0x03

#define T1CCTL2_RFIRQ_ENABLE                    0x80
#define T1CCTL2_RFIRQ_DISABLE                   0x00
#define T1CCTL2_IM                              0x40
#define T1CCTL2_CMP                             0x38
#define T1CCTL2_CMP_SETOUTPUTONCOMPARE          0x00
#define T1CCTL2_CMP_CLEAROUTPUTONCOMPARE        0x08
#define T1CCTL2_CMP_TOGGLEOUTPUTONCOMPARE       0x10
#define T1CCTL2_CMP_SETOUTPUTONCOMPARECLEARON0  0x18
#define T1CCTL2_CMP_CLEAROUTPUTONCOMPARESETON0  0x20
#define T1CCTL2_CMP_CLEARWHENEQUALT1CC0         0x28
#define T1CCTL2_CMP_SETWHENEQUALT1CC0           0x30
#define T1CCTL2_CMP_INITIALIZEOUTPUTPIN         0x38
#define T1CCTL2_MODE_CAPTUREMODE                0x00
#define T1CCTL2_MODE_COMPAREMODE                0x04
#define T1CCTL2_CAP_NOCOMPARE                   0x00
#define T1CCTL2_CAP                             0x03
#define T1CCTL2_CAP_CAPTUREONRISING             0x01
#define T1CCTL2_CAP_CAPTUREONFALLING            0x02
#define T1CCTL2_CAP_CAPTUREONALL                0x03

#define T1CCTL3_RFIRQ_ENABLE                    0x80
#define T1CCTL3_RFIRQ_DISABLE                   0x00
#define T1CCTL3_IM                              0x40
#define T1CCTL3_CMP                             0x38
#define T1CCTL3_CMP_SETOUTPUTONCOMPARE          0x00
#define T1CCTL3_CMP_CLEAROUTPUTONCOMPARE        0x08
#define T1CCTL3_CMP_TOGGLEOUTPUTONCOMPARE       0x10
#define T1CCTL3_CMP_SETOUTPUTONCOMPARECLEARON0  0x18
#define T1CCTL3_CMP_CLEAROUTPUTONCOMPARESETON0  0x20
#define T1CCTL3_CMP_CLEARWHENEQUALT1CC0         0x28
#define T1CCTL3_CMP_SETWHENEQUALT1CC0           0x30
#define T1CCTL3_CMP_INITIALIZEOUTPUTPIN         0x38
#define T1CCTL3_MODE_CAPTUREMODE                0x00
#define T1CCTL3_MODE_COMPAREMODE                0x04
#define T1CCTL3_CAP_NOCOMPARE                   0x00
#define T1CCTL3_CAP                             0x03
#define T1CCTL3_CAP_CAPTUREONRISING             0x01
#define T1CCTL3_CAP_CAPTUREONFALLING            0x02
#define T1CCTL3_CAP_CAPTUREONALL                0x03

#define T1CCTL4_RFIRQ_ENABLE                    0x80
#define T1CCTL4_RFIRQ_DISABLE                   0x00
#define T1CCTL4_IM                              0x40
#define T1CCTL4_CMP                             0x38
#define T1CCTL4_CMP_SETOUTPUTONCOMPARE          0x00
#define T1CCTL4_CMP_CLEAROUTPUTONCOMPARE        0x08
#define T1CCTL4_CMP_TOGGLEOUTPUTONCOMPARE       0x10
#define T1CCTL4_CMP_SETOUTPUTONCOMPARECLEARON0  0x18
#define T1CCTL4_CMP_CLEAROUTPUTONCOMPARESETON0  0x20
#define T1CCTL4_CMP_CLEARWHENEQUALT1CC0         0x28
#define T1CCTL4_CMP_SETWHENEQUALT1CC0           0x30
#define T1CCTL4_CMP_INITIALIZEOUTPUTPIN         0x38
#define T1CCTL4_MODE_CAPTUREMODE                0x00
#define T1CCTL4_MODE_COMPAREMODE                0x04
#define T1CCTL4_CAP_NOCOMPARE                   0x00
#define T1CCTL4_CAP                             0x03
#define T1CCTL4_CAP_CAPTUREONRISING             0x01
#define T1CCTL4_CAP_CAPTUREONFALLING            0x02
#define T1CCTL4_CAP_CAPTUREONALL                0x03

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
void Timer1_captureCompareChannel0(uint8_t mode);
void Timer1_readCaptureCompareChannel0(Timer1_t *timerPtr);
void Timer1_captureCompareChannel1(uint8_t mode);
void Timer1_readCaptureCompareChannel1(Timer1_t *timerPtr);
void Timer1_captureCompareChannel2(uint8_t mode);
void Timer1_readCaptureCompareChannel2(Timer1_t *timerPtr);
void Timer1_captureCompareChannel3(uint8_t mode);
void Timer1_readCaptureCompareChannel3(Timer1_t *timerPtr);
void Timer1_captureCompareChannel4(uint8_t mode);
void Timer1_readCaptureCompareChannel4(Timer1_t *timerPtr);

void Timer1_read(Timer1_t *timerPtr);

#endif
/** @}*/