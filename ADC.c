/** @ingroup ADC
 * @{
 */
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
#include <ADC.h>
#include <ioCC2530.h>
   
/*******************| Macros |*****************************************/

/*******************| Type definitions |*******************************/

/*******************| Type definitions |*******************************/

/*******************| Global variables |*******************************/

/*******************| Function definition |****************************/

/**
 * Initializes the ADC module by configuring the pins given in adcPinMode
 * to ADC input
 * @param adcPinMode A logical one will configure the corresponding pin ad
 * adc input
*/
void ADC_init(uint8_t adcPinMode)
{
  APCFG = adcPinMode;
}

/**
 * Checks EOC bit of ADCCON1 for if conversion is complete
 * @return Returns 0 if conversion is still on-going, <> 0 if conversion is complete
*/
inline uint8_t ADC_isConversionComplete()
{
  return ADCCON1 & ADCCON1_EOC_CONVERSIONCOMPLETE;
}

/**
 * Starts ADC conversion sequence by setting ADCCON1 ST bit.
*/
inline uint8_t ADC_startConversionSequence()
{
  return ADCCON1 |= ADCCON1_ST_STARTCONVERSIONSEQUENCE;
}

/**
 * Sets sequence start event for ADC sequence conversion
 * @param sequenceStartEvent Event to start a new sequence. Only one of ADCCON1_STSEL_EXTERNALTRIGGER_P20,
 * ADCCON1_STSEL_FULLSPEED_NOTRIGGER, ADCCON1_STSEL_TIMER1COMPAREEVENT or ADCCON1_STSEL_ADCON1STEL
 * should be used as parameter.
*/
inline void ADC_setConversionSequenceStartEvent(uint8_t sequenceStartEvent)
{
  sequenceStartEvent &= ADCCON1_STSEL;
  ADCCON1 &= ~ADCCON1_STSEL;
  ADCCON1 |= sequenceStartEvent;
}

/**
 * Configures ADC sequence conversion by means of setting ADCCON2 register
 * From User Guide (swru191c.pdf):
 * The conversion sequence can be influenced with the APCFG register (see Section 7.6.6), in that the eight
 * analog inputs to the ADC come from I/O pins that are not necessarily programmed to be analog inputs. If
 * a channel should normally be part of a sequence, but the corresponding analog input is disabled in the
 * APCFG register, then that channel is skipped. When using differential inputs, both pins in a differential pair
 * must set as analog input pins in the APCFG register.
 * @para config Value for ADCCON2 register. Must from ADCCON2_ defines
*/
inline void ADC_setSequenceConversion(uint8_t config)
{
  ADCCON2 = config;
}

/**
 * Sets ADCCON3 register according to value provided and starts conversion
 * @param config Value to be passed to ADCCON3 register. only #defines prefixed 
 * ADCCON3_ should be used to call this function.

 * From User Guide (swru191c.pdf):
 * In addition to this sequence of conversions, the ADC can be programmed to perform a single conversion
 * from any channel. Such a conversion is triggered by writing to the ADCCON3 register. The conversion
 * starts immediately unless a conversion sequence is already ongoing, in which case the single conversion
 * is performed as soon as that sequence is finished.
*/
inline void ADC_startSingleConversion(uint8_t config)
{
  ADCCON3 = config;
}

/** @}*/