#include "CC253x.h"
#include <ioCC2530.h>
/** TODO: Find a way to include correct file depending on processor type in use */

/**
 * Initializes MCU especially oscilator
 * @param: clkSource select if 16MHz rc oscilator or 32Mhz external crystal is to be used. One of CLKCONCMD_OSC_16MHZ_ or RCOSC CLKCONCMD_OSC_32MHZ_XOSC
   @param: Timer ticks output setting. Cannot be higher than system clock setting given by OSC bit setting
   @param: clkSpeed Clock speed. Cannot be higher than system clock setting given by the OSC bit setting. Indicates current system-clock frequency
**/
void CC253x_Init( uint8 clkCmd )
{
  /* external 32kHz clock source is never selected, default value is used */
  CLKCONCMD = clkCmd;
 /* wait until both clocks has stabilized */
  while (CLKCONSTA != CLKCONCMD) nop();
}

/**
 * Sets and activates sleep mode defined by mode
 * @param mode desired sleep mode. One of SLEEPCMD_MODE_ACTIVE_IDLE or SLEEPCMD_MODE_PM1 to SLEEPCMD_MODE_PM3
 *
 * NOTE: If additional wake-up code is to be called interrupts must be disable
 * after PCON access (see swru191c.pdf Chapter 4. Power Modes and Clocks)
 * 
 * TODO: According to swru191c.pdf Chapter 4. Power Modes and Clocks "The 
 * instruction that sets the PCON.IDLE bit must be aligned in a certain way for 
 * correct operation. The first byte of the assembly instruction immediately 
 * following this instruction must not be placed on a 4-byte boundary. ... 
 * "MOV PCON,#1 instruction is placed on a 2-byte boundary. It is a 3-byte 
 * instruction, so the following instruction is not placed on a 4-byte boundary, 
 * as required."
**/
void CC253x_ActivatePowerMode(uint8 mode)
{
  /* set desired mode */
  SLEEPCMD = mode & SLEEPCMD_MODE_MASK;
  /* activate mode */
  /* TODO: Align following code on 2-byte boundary */
  PCON = PCON_IDLE_ENTERSLEEPMODE;
  nop();
  /* wait until clock is set back to 32MHz external oscilator, i.e. 16MHz Rc
   * oscilator is disabled, in order to use radio again. */
  while (CLKCONSTA != CLKCONCMD) nop();
  /* while ((CLKCONSTA & CLKCONCMD_OSC_RCOSC) != 0 ) nop(); */
}

/**
 * Increments sleeptime by newSleepTimerValue
 * @param newSleepTimerValue value to increment sleep timer
*/
void CC253x_IncrementSleepTimer(sleepTimer_t newSleepTimerValue)
{
  sleepTimer_t actualSleepTimerValue;
  /* get actual timer value. Read of ST0 will latch ST1 and ST2 */
  actualSleepTimerValue.ST0 = ST0;
  actualSleepTimerValue.ST1 = ST1;
  actualSleepTimerValue.ST2 = ST2;
  /* add desired sleep timer */
  actualSleepTimerValue.value += newSleepTimerValue.value;
  /* wait until a new values is allowed to be written to the counter */
  while (!STLOAD & STLOAD_LDRDY) nop();
  /* write value back. Write to ST0 will write complete time value */
  ST2 = actualSleepTimerValue.ST2;
  ST1 = actualSleepTimerValue.ST1;
  ST0 = actualSleepTimerValue.ST0;
  /* TODO: Check if IEN0.STIE needs to be enabled */
  SleepTimerInterruptEnable();
}