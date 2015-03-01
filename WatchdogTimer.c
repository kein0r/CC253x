/** @ingroup WatchdogTimer
 * @{
 */
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
#include <WatchdogTimer.h>
#include <ioCC2530.h>
   
/*******************| Macros |*****************************************/

/*******************| Type definitions |*******************************/

/*******************| Type definitions |*******************************/

/*******************| Global variables |*******************************/

/*******************| Function definition |****************************/

/** 
 * Initializes watchdog timer (WDT) module
 * @param watchdogMode Value for WDCTL.MODE. One of #WDT_MODE_IDLE, #WDT_MODE_TIMERMODE or
 * #WDT_MODE_WATCHDOGMODE
*/
void WDT_init(uint8_t watchdogMode)
{
  /* Set watchdog to idle just in case it was in watchdog or timer mode before */
  WDCTL = WDT_MODE_IDLE;
  WDCTL |= (watchdogMode & WDT_INT_MASK) | WDT_MODE_WATCHDOGMODE;
}

/**
 * Triggers watchdog by writing 0xa and 0x5 in in WDCTL.CLR
 */
inline void WDT_trigger()
{
  WDCTL = WDT_TRIGGER_SEQUENCE1;
  WDCTL = WDT_TRIGGER_SEQUENCE2;
}

/** @}*/