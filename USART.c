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
static USART_Buffer USART_TxBuffer[USART_SIZE_OF_USART_TX_BUFFER];
static USART_BufferIndex USART_TxBufferIndex = 0;
static USART_Buffer USART_RxBuffer[USART_SIZE_OF_USART_RX_BUFFER];
static USART_BufferIndex USART_RxBufferIndex = 0;

/*******************| Function definition |****************************/

/**
 * Baudrate set for USART module
 * @param: baudrate. Baudrate to be used for USART module. See swru191c.pdf 
 * Chapter 17.4 Baud-Rate Generation for a list of valid baudrate. Invalid 
 * baudrates settings will be ignored and default baudrate of 9600 will be
 * used instead.
 * SPI config in U0CGR will be reset to 0.
*/
void USART_setBaudrate(USART_Baudrate_t baudrate)
{
  /* baudrate register values are taken from swru191c.pdf Table 17-1. Commonly 
   * Used Baud-Rate Settings for 32 MHz System Clock */
  switch (baudrate)
  {
    case USART_Baudrate_1200:
      U0BAUD = 59;
      U0GCR = 5 & REGISTER_MASK_UxGCR_BAUD_E;
      break;
    case USART_Baudrate_2400:
      U0BAUD = 59;
      U0GCR = 6 & REGISTER_MASK_UxGCR_BAUD_E;
      break;
    case USART_Baudrate_4800:
      U0BAUD = 59;
      U0GCR = 7 & REGISTER_MASK_UxGCR_BAUD_E;
      break;
    case USART_Baudrate_19200:
      U0BAUD = 59;
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
    case USART_Baudrate_115200:
      U0BAUD = 216;
      U0GCR = 11 & REGISTER_MASK_UxGCR_BAUD_E;
      break;
    default:    /* defaults to 9600 or USART_BAUDRATE_DEFAULT */
      U0BAUD = 59;
      U0GCR = 8 & REGISTER_MASK_UxGCR_BAUD_E; 
  }
  /* Set U0CSR register to USART, receive enable */
  U0CSR = 0x00 | USART_U0CSR_MODE_UART | USART_U0CSR_RE_ENABLED;
  /* flush USART module */
  /* set transmission mode to default 8 bit + one stop bit, low level at start and stop, flush USART module 
   * USART_U0UCR_PARITY_DISABLE/USART_U0UCR_PARITY_ENABLE, USART_U0UCR_D9_ODD/USART_U0UCR_D9_EVEN will be set in USART_setParity */
  U0UCR |= USART_U0UCR_FLUSH | USART_U0UCR_BIT9_DISABLE | USART_U0UCR_SPB_1BIT | USART_U0UCR_STOP_LOW | USART_U0UCR_START_LOW;
}

/**
 * USART_setParity will set parity for USART module
 * @param parity Parity to be set
 * NOTE: only No parity, even parity and odd parity is implemented (i.e. possible). Every other value
 * will lead to default "No parity"
 */
void USART_setParity(USART_Parity_t parity)
{
  switch (parity)
  {
  case USART_Parity_8BitEvenParity:
    U0UCR |= USART_U0UCR_FLUSH | USART_U0UCR_PARITY_ENABLE | USART_U0UCR_D9_EVEN;
    break;
  case USART_Parity_8BitOddParity:
    U0UCR |= USART_U0UCR_FLUSH | USART_U0UCR_PARITY_ENABLE | USART_U0UCR_D9_ODD;
    break;
  default:
    U0UCR |= USART_U0UCR_FLUSH | USART_U0UCR_PARITY_DISABLE | USART_U0UCR_D9_EVEN;
  }
}

/* maximum of buffer_size can be sent, not more */

void USART_send(uint8_t dataPointer, uint8_t size)
{
  if (USART_TxBufferIndex == 0);
}
/** @}*/