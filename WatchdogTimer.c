/** @ingroup WatchdogTimer
 * @{
 */
/*
  Copyright (c) 2014 Jan R�diger.  All right reserved.

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
*/
void WDT_init(uint8_t watchdogMode)
{
  /* Set watchdog to idle just in case it was in watchdog or timer mode before */
  WDCTL = WDT_MODE_IDLE;
  WDCTL |= (watchdogMode & WDT_INT_MASK) | WDT_MODE_WATCHDOGMODE;
}


/** @}*/