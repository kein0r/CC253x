/** @ingroup Watchdog
 * @{
 */
#ifndef WATCHDOGTIMER_H_
#define WATCHDOGTIMER_H_
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
#include <Config.h>
   
/*******************| Macros |*****************************************/
/**
 Defines to set watchdog mode bits in WDCTL.MODE
*/
#define WDT_MODE_IDLE                           (uint8_t)0x00
#define WDT_MODE_RESERVED                       (uint8_t)0x04
#define WDT_MODE_WATCHDOGMODE                   (uint8_t)0x08
#define WDT_MODE_TIMERMODE                      (uint8_t)0x0c
#define WDT_MODE_MASK                           (uint8_t)0x0c

/**
 Defines to set watchdog interval bits in WDCTL.INT
*/
#define WDT_INT_CLOCKTIMES32768                 (uint8_t)0x00   /* Clock period × 32,768 (~1 s) when running the 32-kHz XOSC */
#define WDT_INT_CLOCKTIMES8192                  (uint8_t)0x01   /* Clock period × 8192 (~0.25 s) */
#define WDT_INT_CLOCKTIMES512                   (uint8_t)0x02   /* Clock period × 512 (~15.625 ms) */
#define WDT_INT_CLOCKTIMES64                    (uint8_t)0x03   /* Clock period × 64 (~1.9 ms) */
#define WDT_INT_MASK                            (uint8_t)0x03

/*******************| Type definitions |*******************************/

/*******************| Type definitions |*******************************/

/*******************| Global variables |*******************************/

/*******************| Function prototypes |****************************/

void WDT_init(uint8_t watchDogMode);

#endif
/** @}*/