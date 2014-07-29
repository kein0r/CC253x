/** @ingroup CC253x
 * @{
 */
#ifndef CC253x_CFG_H_
#define CC253x_CFG_H_

/*******************| Inclusions |*************************************/
#include <ioCC2530.h>
#include <PlatformTypes.h>
   
/*******************| Macros |*****************************************/
#define nop()  asm("NOP") 
   
/**
 * For easier reading of clock settings
*/
#define CLKCONCMD_OSC32K_XOSC                           0x00
#define CLKCONCMD_OSC32K_RCOSC                          0x80
#define CLKCONCMD_OSC_XOSC                              0x00
#define CLKCONCMD_OSC_RCOSC                             0x40
#define CLKCONCMD_TICKSPD_32MHZ                         0x00
#define CLKCONCMD_TICKSPD_16MHZ                         0x08
#define CLKCONCMD_TICKSPD_8MHZ                          0x10
#define CLKCONCMD_TICKSPD_4MHZ                          0x18
#define CLKCONCMD_TICKSPD_2MHZ                          0x20
#define CLKCONCMD_TICKSPD_1MHZ                          0x28
#define CLKCONCMD_TICKSPD_500KHZ                        0x30
#define CLKCONCMD_TICKSPD_250KHZ                        0x38
#define CLKCONCMD_CLKSPD_32MHz                          0x00
#define CLKCONCMD_CLKSPD_16MHz                          0x01
#define CLKCONCMD_CLKSPD_8MHz                           0x02
#define CLKCONCMD_CLKSPD_4MHz                           0x03
#define CLKCONCMD_CLKSPD_2MHz                           0x04
#define CLKCONCMD_CLKSPD_1MHz                           0x05
#define CLKCONCMD_CLKSPD_500KHZ                         0x06
#define CLKCONCMD_CLKSPD_250KHZ                         0x07

/**
 * For easier reading of power  modes
*/
#define PCON_IDLE_SET                                   0x01
#define SLEEPCMD_MODE_PM3                               0x03
#define SLEEPCMD_MODE_PM2                               0x02
#define SLEEPCMD_MODE_PM1                               0x01
#define SLEEPCMD_MODE_ACTIVE_IDLE                       0x00
#define SLEEPCMD_MODE_MASK                              0x03
   
/*******************| Type definitions |*******************************/
typedef union {
  uint32 value;
  struct {
    uint8 ST2;
    uint8 ST1;
    uint8 ST0;
  } ;
} sleepTimer_t;

/*******************| Global variables |*******************************/

/*******************| Function prototypes |****************************/

void CC253x_Init( uint8 clkSource, uint8 tickSpeed, uint8 clkSpeed );
void CC253x_ActivatePowerMode(uint8 mode);
void CC253x_IncrementSleepTimer(sleepTimer_t newSleepTimerValue);

#endif
/** @}*/
