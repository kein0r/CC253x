/** @ingroup USART
 * @{
 */
#ifndef USART_H_
#define USART_H_
   
/*******************| Inclusions |*************************************/
#include <Config.h>
#include <PlatformTypes.h>
   
/*******************| Macros |*****************************************/
/** Do not change these values! It will be used internally. Default baudrate
 * will always be 9600 baud. Equally of the value set here */
#define USART_BAUDRATE_DEFAULT  USART_Baudrate_9600
#define USART_PARITY_DEFAULT  USART_Parity_8BitNoParity

/**
 * interrupt flag bits 
*/
#define IEN0_URX0IE                     0x04
#define IEN2_UTX0IE                     0x04
   
#define USART_U0CSR_MODE_SPI            0x00
#define USART_U0CSR_MODE_UART           0x80
#define USART_U0CSR_RE_ENABLED          0x40
#define USART_U0CSR_RE_DISABLED         0x00
#define USART_U0CSR_SLAVE_SPI_MASTER    0x00
#define USART_U0CSR_SLAVE_SPI_SLAVE     0x20
#define USART_U0CSR_RX_BYTE             0x04
#define USART_U0CSR_TX_BYTE             0x02
#define USART_U0CSR_ACTIVE              0x01
   
#define USART_U0UCR_FLUSH               0x80
#define USART_U0UCR_FLOW_DISABLE        0x00
#define USART_U0UCR_FLOW_ENABLE         0x40
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

#define REGISTER_MASK_UxGCR_BAUD_E      0x1f
#define USART_flush()                   U0UCR |= USART_U0UCR_FLUSH

#define USART_incrementIndex(a)         a = (a + 1) % USART_RING_BUFFER_SIZE

/*******************| Type definitions |*******************************/
typedef enum {
  USART_Baudrate_1200 = 0,
  USART_Baudrate_2400,
  USART_Baudrate_4800,
  USART_Baudrate_9600,
  USART_Baudrate_19200,
  USART_Baudrate_38400,
  USART_Baudrate_57600,
  USART_Baudrate_115200
} USART_Baudrate_t;

typedef enum {
  USART_Parity_8BitNoParity = 0,
  USART_Parity_8BitEvenParity,
  USART_Parity_8BitOddParity
} USART_Parity_t;

typedef uint8_t USART_BufferIndex_t;

/**
 * \brief Data struct for ring buffer.
 * Index pointer for head and tail will always point to element which is next to be read/written.
 */
typedef struct
{
  unsigned char buffer[USART_RING_BUFFER_SIZE]; /*!< Content of ring buffer */
  volatile USART_BufferIndex_t head;        /*!< Index for writing to the ring buffer. Index is increased after writing (i.e. producing) an element */
  volatile USART_BufferIndex_t tail;        /*!< Index for reading from ring buffer. Index is increased after reading (i.e consuming) an element. */
} USART_RingBuffer_t;

/*******************| Global variables |*******************************/

/*******************| Function prototypes |****************************/
void UART_init();
void USART_setBaudrate(USART_Baudrate_t baudrate);
void USART_setParity(USART_Parity_t parity);
uint8_t USART_available();
uint8_t USART_read(char *dataPointer, uint8_t numBytes);
void USART_write(char const *dataPointer, uint8_t numBytes);
void USART_writeline(char const *dataPointer);
void USART_getc(char *dataPointer);
void USART_putc(const char data);
#endif
/** @}*/
