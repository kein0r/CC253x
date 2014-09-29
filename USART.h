/** @ingroup USART
 * @{
 */
#ifndef USART_H_
#define USART_H_
   
/*******************| Inclusions |*************************************/
#include <PlatformTypes.h>
   
/*******************| Macros |*****************************************/
/** Do not change this value! It will be used internally. Default baudrate
 * will always be 9600 baud. Equally of the value set here */
#define USART_BAUDRATE_DEFAULT  USART_Baudrate_9600
   
#define REGISTER_MASK_UxGCR_BAUD_E      0x1f
   
#define USART_U0UCR_FLUSH               0x80
#define USART_U0UCR_ENABLE_FLOW_DISABLE 0x40
#define USART_U0UCR_ENABLE_FLOW_ENABLE  0x40
#define USART_U0UCR_D9_ODD              0x00
#define USART_U0UCR_D9_EVEN             0x20
#define USART_U0UCR_BIT9_DISABLE        0x00
#define USART_U0UCR_BIT9_ENABLE         0x10
#define USART_U0UCR_PARITY_DISABLE      0x00
#define USART_U0UCR_PARITY_ENABLE       0x08
#define USART_U0UCR_SPB_1BIT            0x00
#define USART_U0UCR_SPB_2BIT            0x04
#define USART_U0UCR_STOP_LOW            0x00
#define USART_U0UCR_STOP_HIGH           0x02
#define USART_U0UCR_START_LOW           0x00
#define USART_U0UCR_START_HIGH          0x01

/*******************| Type definitions |*******************************/
typedef enum {
  USART_Baudrate_9600,
  USART_Baudrate_14400,
  USART_Baudrate_19200,
  USART_Baudrate_28800,
  USART_Baudrate_38400,
  USART_Baudrate_57600,
  USART_Baudrate_76800,
  USART_Baudrate_115200,
  USART_Baudrate_230400
} USART_Baudrate_t;

/*******************| Global variables |*******************************/

/*******************| Function prototypes |****************************/
void USART_init(USART_Baudrate_t baudrate);

#endif
/** @}*/