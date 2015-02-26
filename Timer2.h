/** @ingroup Timer2
 * @{
 */
#ifndef TIMER2_H_
#define TIMER2_H_
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
  Parts of this code are inspired by Arduino hardware serial library.
*/
/*******************| Inclusions |*************************************/
#include <PlatformTypes.h>
#include <Config.h>
   
/*******************| Macros |*****************************************/
#define T2CTRL_RUN                      0x01
#define T2CTRL_SYNC_32MHz               0x00
#define T2CTRL_SYNC_32kHz               0x02
#define T2CTRL_STATE_MASK               0x04
#define T2CTRL_LATCHMODE_SEPARATE       0x00
#define T2CTRL_LATCHMODE_COMBINED       0x08

#define T2MSEL_T2MSEL_MASK              0x7
#define T2MSEL_T2MSEL_T2TIMER           0x0     /* timer count value */
#define T2MSEL_T2MSEL_T2_CAP            0x1     /* timer capture */
#define T2MSEL_T2MSEL_T2_PERIOD         0x2     /* timer period */
#define T2MSEL_T2MSEL_T2_COMP1          0x3     /* timer compare 1 */
#define T2MSEL_T2MSEL_T2_COMP2          0x04    /* timer compare 2 */

/*******************| Type definitions |*******************************/
/**
 * Structure to access T2Mx and T2MOVLx register. This will only work if
 * compiler is placing uint8_t on byte boundary. If not something like
 * #pragma pack must be used.
*/
typedef union
{
  uint16_t value;
  struct {
    uint8_t T2M0;
    uint8_t T2M1;
  } regs;
} Timer2_t;

/*******************| Type definitions |*******************************/

/*******************| Global variables |*******************************/

/*******************| Function prototypes |****************************/
void Timer2_init();
void Timer2_read(Timer2_t *timerPtr);

#endif
/** @}*/