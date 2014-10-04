/** @ingroup USART
 * @{
 */

/*
  USART.c - Hardware serial for CC2530
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

#include <USART.h>
#include <board.h>

/*******************| Inclusions |*************************************/

/*******************| Macros |*****************************************/
#if BOARD_CPUFREQUENCY != 32000000
#error Board frequemcy must be set to 32MHz for UART to work properly
#endif

#ifndef USART_RING_BUFFER_SIZE
#error USART_RING_BUFFER_SIZE must be defined in USART_cfg.h
#endif

/*******************| Type definitions |*******************************/

/*******************| Global variables |*******************************/
static USART_RingBuffer_t USART_TxRingBuffer = { { 0 }, 0, 0};
static USART_RingBuffer_t USART_RxRingBuffer = { { 0 }, 0, 0};

/*******************| Function definition |****************************/

void UART_init()
{
  /* Configure UART0 for Alternative 1 => Port P0 (PERCFG.U0CFG = 0) */
  PERCFG &= ~0x01;
  /* Configure relevant Port P0 pins for peripheral function:
   * P0SEL.SELP0_2/3/4/5 = 1 => RX = P0_2, TX = P0_3, CT = P0_4, RT = P0_5 */
  P0SEL |= 0x3C;
  
  /* enable Rx and Tx interrupt */
  enableInterrupt(IEN2, IEN2_UTX0IE);
  enableInterrupt(IEN0, IEN0_URX0IE);
}

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
  /* Disable module while configuring it */
  U0CSR &= ~USART_U0CSR_RE_ENABLED;
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
  /* Set U0CSR register to USART, receive enable and flush it*/
  /* If parity was not yet conifigured this sets transmission mode to default 
   * 8N1: 8 bit + one stop bit, low level at start, high on stop */
  U0CSR |= USART_U0UCR_FLUSH | USART_U0CSR_MODE_UART | USART_U0CSR_RE_ENABLED;
}

/**
 * USART_setParity will set parity for USART module
 * @param parity Parity to be set
 * NOTE: only No parity, even parity and odd parity is implemented (i.e. possible). Every other value
 * will lead to default "No parity"
 */
void USART_setParity(USART_Parity_t parity)
{
  /* Disable module while configuring it */
  U0CSR &= ~USART_U0CSR_RE_ENABLED;
  switch (parity)
  {
  case USART_Parity_8BitEvenParity:
    U0UCR = USART_U0UCR_FLOW_ENABLE | USART_U0UCR_PARITY_ENABLE | USART_U0UCR_D9_EVEN | USART_U0UCR_BIT9_ENABLE | USART_U0UCR_SPB_1BIT | USART_U0UCR_START_LOW | USART_U0UCR_STOP_HIGH;
    break;
  case USART_Parity_8BitOddParity:
    U0UCR = USART_U0UCR_FLOW_ENABLE | USART_U0UCR_PARITY_ENABLE | USART_U0UCR_D9_ODD | USART_U0UCR_BIT9_ENABLE | USART_U0UCR_SPB_1BIT | USART_U0UCR_START_LOW | USART_U0UCR_STOP_HIGH;
    break;
  default:
    U0UCR = USART_U0UCR_FLOW_ENABLE | USART_U0UCR_PARITY_DISABLE | USART_U0UCR_D9_ODD | USART_U0UCR_BIT9_DISABLE | USART_U0UCR_SPB_1BIT | USART_U0UCR_START_LOW | USART_U0UCR_STOP_HIGH;
  }
  /* enable modul again and flush it */
  U0CSR |= USART_U0CSR_MODE_UART | USART_U0CSR_RE_ENABLED;
}

uint8_t USART_available()
{
  return (uint8_t) (USART_TxRingBuffer.head - USART_TxRingBuffer.tail);
}

/* Adds string in dataPointer to Tx ringbuffer and activated TXIF to transmit
 * data.
 * @param: dataPointer: Zero-terminated string.
 */
void USART_write(char const *dataPointer)
{
  while (*dataPointer)
  {
    USART_incrementIndex(USART_TxRingBuffer.head);
    USART_TxRingBuffer.buffer[USART_TxRingBuffer.head] = *dataPointer;
    dataPointer++;
  }
  /* Tell uart that there is something to be sent (if not alread on it) */
  UTX0IF = 1;
}

/* reads from USART Rx ringbuffer until either numBytes are read or string 
 * delimiter (0) is found.
 * This function is blocking! It will only return if a zero terminated string
 * is found.
 * @param: dataPointer: Zero-terminated string read from USAT
 */
void USART_read(char *dataPointer, uint16_t numBytes)
{
  while (*dataPointer && numBytes)
  {
    /* check if data is available */
    if (USART_RxRingBuffer.head != USART_RxRingBuffer.tail)
    {
      USART_incrementIndex(USART_RxRingBuffer.tail);
      *dataPointer = USART_RxRingBuffer.buffer[USART_RxRingBuffer.head];
      dataPointer++;
      numBytes--;
    }
    else 
    {
      /* we just wait until enough data is received */
    }
  }
}

/* Reads one byte from USART Rx ringbuffer if available
 * This function is blocking! It will only return at least one byte was received
 * @param: dataPointer: pinter were to put that byte
 */
void USART_getc(char *dataPointer)
{
  /* if no data available yet, wait! */
  while(USART_RxRingBuffer.head == USART_RxRingBuffer.tail) ;
  USART_incrementIndex(USART_RxRingBuffer.tail);
  *dataPointer = USART_RxRingBuffer.buffer[USART_RxRingBuffer.head];
}

/**
 * USART Tx-finished ISR
*/
#pragma vector = UTX0_VECTOR
__near_func __interrupt void USART_TxComplete(void)
{
  UTX0IF = 0;
  if (USART_TxRingBuffer.tail != USART_TxRingBuffer.head)
  {
    USART_incrementIndex(USART_TxRingBuffer.tail);
    U0DBUF = USART_TxRingBuffer.buffer[USART_TxRingBuffer.tail];
  }
}

/**
 * USART Rx data received ISR. No check is done for buffre overflow!
*/
#pragma vector = URX0_VECTOR
__near_func __interrupt void USART_RxComplete(void)
{
  URX0IF = 0;
  USART_incrementIndex(USART_RxRingBuffer.head);
  USART_RxRingBuffer.buffer[USART_RxRingBuffer.head] = U0DBUF;
}

/** @}*/