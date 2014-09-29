/** @ingroup USART
 * @{
 */
#include <USART.h>
#include <board.h>

/*******************| Inclusions |*************************************/

/*******************| Macros |*****************************************/
#if BOARD_CPUFREQUENCY != 32000000
#error Board frequemcy must be set to 32MHz for UART to work properly
#endif


/*******************| Type definitions |*******************************/

/*******************| Global variables |*******************************/

/*******************| Function definition |****************************/

/**
 * Init for USART module
 * @param: baudrate. Baudrate to be used for USART module. See swru191c.pdf 
 * Chapter 17.4 Baud-Rate Generation for a list of valid baudrate. Invalid 
 * baudrates settings will be ignored and default baudrate of 9600 will be
 * used instead.
*/
void USART_init(USART_Baudrate_t baudrate)
{
  /* baudrate register values are taken from swru191c.pdf Table 17-1. Commonly 
   * Used Baud-Rate Settings for 32 MHz System Clock */
  switch (baudrate)
  {
    case USART_Baudrate_14400:
      U0BAUD = 216;
      U0GCR = 8 & REGISTER_MASK_UxGCR_BAUD_E;
      break;
    case USART_Baudrate_19200:
      U0BAUD = 59;
      U0GCR = 9 & REGISTER_MASK_UxGCR_BAUD_E;
      break;
    case USART_Baudrate_28800:
      U0BAUD = 216;
      U0GCR = 9 & REGISTER_MASK_UxGCR_BAUD_E;
      break;
    case USART_Baudrate_38400:
      U0BAUD = 59;
      U0GCR = 10 & REGISTER_MASK_UxGCR_BAUD_E;
      break;
    case USART_Baudrate_57600:
      U0BAUD = 216;
      U0GCR = 10 & REGISTER_MASK_UxGCR_BAUD_E;
      break;
    case USART_Baudrate_76800:
      U0BAUD = 59;
      U0GCR = 11 & REGISTER_MASK_UxGCR_BAUD_E;
      break;
    case USART_Baudrate_115200:
      U0BAUD = 216;
      U0GCR = 11 & REGISTER_MASK_UxGCR_BAUD_E;
      break;
    case USART_Baudrate_230400:
      U0BAUD = 216;
      U0GCR = 12 & REGISTER_MASK_UxGCR_BAUD_E;
      break;
    default:    /* defaults to 9600 or USART_BAUDRATE_DEFAULT */
      U0BAUD = 59;
      U0GCR = 8 & REGISTER_MASK_UxGCR_BAUD_E; 
  }
  /* Set U0CSR register to USART, receive enable */
  U0CSR = 0x00;
  /* set transmission mode to 8N1, low level at start and stop, flush USART module */
  U0UCR = USART_U0UCR_FLUSH | USART_U0UCR_D9_ODD | USART_U0UCR_BIT9_DISABLE | USART_U0UCR_PARITY_DISABLE | USART_U0UCR_SPB_1BIT | USART_U0UCR_STOP_LOW | USART_U0UCR_START_LOW;
}

/** @}*/