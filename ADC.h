/** @ingroup ADC
 * @{
 */
#ifndef ADC_H_
#define ADC_H_
/*
  Copyright (c) 2015 Jan Rüdiger.  All right reserved.

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
#include <Config.h>
   
/*******************| Macros |*****************************************/
#define APCFG_ADCINPUT0                                 0x01
#define APCFG_ADCINPUT1                                 0x02
#define APCFG_ADCINPUT2                                 0x04
#define APCFG_ADCINPUT3                                 0x08
#define APCFG_ADCINPUT4                                 0x10
#define APCFG_ADCINPUT5                                 0x20
#define APCFG_ADCINPUT6                                 0x40
#define APCFG_ADCINPUT7                                 0x80

#define ADCCON1_EOC                                     0x80
#define ADCCON1_EOC_CONVERSIONCOMPLETE                  0x80
#define ADCCON1_EOC_CONVERSIONNOTCOMPLETE               0x00
#define ADCCON1_ST                                      0x40
#define ADCCON1_ST_STARTCONVERSIONSEQUENCE              0x40
#define ADCCON1_ST_NOCONVERSIONINPROGRESS               0x00
#define ADCCON1_STSEL                                   0x30
#define ADCCON1_STSEL_EXTERNALTRIGGER_P20               0x00
#define ADCCON1_STSEL_FULLSPEED_NOTRIGGER               0x10
#define ADCCON1_STSEL_TIMER1COMPAREEVENT                0x20
#define ADCCON1_STSEL_ADCON1STEL                        0x30

#define ADCCON2_SREF                                    0xc0
#define ADCCON2_SREF_INTERNAL                           0x00
#define ADCCON2_SREF_EXTERNAL_AIN7                      0x40
#define ADCCON2_SREF_EXTERNAL_AVDD5                     0x80
#define ADCCON2_SREF_EXTERNAL_DIFFERENTIAL_AIN6AIN7     0xc0
#define ADCCON2_SDIV                                    0x30
#define ADCCON2_SDIV_7BITS_ENOB                         0x00
#define ADCCON2_SDIV_9BITS_ENOB                         0x10
#define ADCCON2_SDIV_10BITS_ENOB                        0x20
#define ADCCON2_SDIV_12BITS_ENOB                        0x30
#define ADCCON2_SCH                                     0x0f
#define ADCCON2_SCH_AIN0                                0x00
#define ADCCON2_SCH_AIN1                                0x01
#define ADCCON2_SCH_AIN2                                0x02
#define ADCCON2_SCH_AIN3                                0x03
#define ADCCON2_SCH_AIN4                                0x04
#define ADCCON2_SCH_AIN5                                0x05
#define ADCCON2_SCH_AIN6                                0x06
#define ADCCON2_SCH_AIN7                                0x07
#define ADCCON2_SCH_AIN0AIN1                            0x08
#define ADCCON2_SCH_AIN2AIN3                            0x09
#define ADCCON2_SCH_AIN4AIN5                            0x0a
#define ADCCON2_SCH_AIN6AIN7                            0x0b
#define ADCCON2_SCH_GND                                 0x0c
#define ADCCON2_SCH_RESERVED                            0x0d
#define ADCCON2_SCH_TEMPERATURESENSOR                   0x0e
#define ADCCON2_SCH_VDD3                                0x0f

#define ADCCON3_EREF                                    0xc0
#define ADCCON3_EREF_INTERNAL                           0x00
#define ADCCON3_EREF_EXTERNAL_AIN7                      0x40
#define ADCCON3_EREF_EXTERNAL_AVDD5                     0x80
#define ADCCON3_EREF_EXTERNAL_DIFFERENTIAL_AIN6AIN7     0xc0
#define ADCCON3_SDIV                                    0x30
#define ADCCON3_SDIV_7BITS_ENOB                         0x00
#define ADCCON3_SDIV_9BITS_ENOB                         0x10
#define ADCCON3_SDIV_10BITS_ENOB                        0x20
#define ADCCON3_SDIV_12BITS_ENOB                        0x30
#define ADCCON3_SCH                                     0x0f
#define ADCCON3_SCH_AIN0                                0x00
#define ADCCON3_SCH_AIN1                                0x01
#define ADCCON3_SCH_AIN2                                0x02
#define ADCCON3_SCH_AIN3                                0x03
#define ADCCON3_SCH_AIN4                                0x04
#define ADCCON3_SCH_AIN5                                0x05
#define ADCCON3_SCH_AIN6                                0x06
#define ADCCON3_SCH_AIN7                                0x07
#define ADCCON3_SCH_AIN0AIN1                            0x08
#define ADCCON3_SCH_AIN2AIN3                            0x09
#define ADCCON3_SCH_AIN4AIN5                            0x0a
#define ADCCON3_SCH_AIN6AIN7                            0x0b
#define ADCCON3_SCH_GND                                 0x0c
#define ADCCON3_SCH_RESERVED                            0x0d
#define ADCCON3_SCH_TEMPERATURESENSOR                   0x0e
#define ADCCON3_SCH_VDD3                                0x0f
    
#define TR0_ADCTM_CONNECTTEMPERATURESENSOR              0x01

/*******************| Type definitions |*******************************/

/*******************| Type definitions |*******************************/

/*******************| Global variables |*******************************/

/*******************| Function prototypes |****************************/

void ADC_init(uint8_t adcPinMode, uint8_t stsel);
uint8_t ADC_isConversionComplete();
uint8_t ADC_startConversionSequence();
void ADC_setConversionSequenceStartEvent(uint8_t sequenceStartEvent);
void ADC_setSequenceConversion(uint8_t config);
void ADC_startSingleConversion(uint8_t config);
void ADC_connectTemperaturSensorToADC();
uint16_t ADC_readSingleConversionValue();

#endif
/** @}*/