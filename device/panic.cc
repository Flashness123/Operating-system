/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Default interrupt handler.                                                */
/*****************************************************************************/

#include "device/panic.h"
#include "device/cgastr.h"
#include "machine/cpu.h"

//extern CGA_Stream kout;
extern CPU cpu;

Panic::Panic(){}

void Panic::trigger() {
    kout << "Panic: Unhandled interrupt!" << endl;
    kout.flush();
    cpu.halt();
}
