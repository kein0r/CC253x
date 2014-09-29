/** @ingroup USART
 * @{
 */
#ifndef USART_H_
#define USART_H_
   
/*******************| Inclusions |*************************************/
#include <PlatformTypes.h>
   
/*******************| Macros |*****************************************/
#define USART_BAUDRATE_DEFAULT  (uint16_t)9600

/*******************| Type definitions |*******************************/

/*******************| Global variables |*******************************/

/*******************| Function prototypes |****************************/
void USART_init(uint16_t baudrate);

#endif
/** @}*/