/** @ingroup Platform
 * @{
 */
#ifndef PLATFORMTYPES_H_
#define PLATFORMTYPES_H_

/*******************| Inclusions |*************************************/
   
/*******************| Macros |*****************************************/
#define STD_ON                  1
#define STD_OFF                 0

/**
 * Macros to access high and low part of 16bit word separately 
*/
#define HI_UINT16(a)            (((uint16_t)(a) >> 8) & 0xFF)
#define LO_UINT16(a)            ((uint16_t)(a) & 0xFF)
   
/*******************| Type definitions |*******************************/

/* Data lenght according to EW8051_CompilerReference.pdf page 276 */
typedef unsigned char uint8_t;
typedef signed char sint8_t;

typedef unsigned short uint16_t;
typedef signed short sint16_t;

typedef unsigned long uint32_t;
typedef signed long sint32_t;

/*******************| Global variables |*******************************/

/*******************| Function prototypes |****************************/

void delay_us(uint16_t usec);
#endif

/** @}*/
