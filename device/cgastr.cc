/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         C G A _ S T R E A M                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The CGA_Stream class allows to print different data types as text strings */
/* to a PC's CGA screen.                                                     */
/* For attributes/colors and cursor positioning use the methods of class     */
/* CGA_Screen.                                                               */
/*****************************************************************************/

#include "device/cgastr.h"
#include "machine/cgascr.h"

CGA_Stream::CGA_Stream() : O_Stream(), CGA_Screen() {}

void CGA_Stream::flush() {
    print(buffer, buffer_size, 0x07); // Output buffer to VGA
    buffer_size = 0; // Reset buffer
}

CGA_Stream kout; 