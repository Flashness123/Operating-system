/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              G U A R D I A N                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The system's central interrupt handling routine.                          */
/* The parameter specifies the number of the interrupt that occurred.        */
/*****************************************************************************/

/* INCLUDES */

/* FUNCTIONS */
#include "device/cgastr.h"
//extern "C" void guardian (unsigned int slot);

/* GUARDIAN: Low-level interrupt handling. We will extend this function at */
/*           a later point in time.  */

//testing:
extern CGA_Stream kout; // telling the compiler that this variable is defined somewhere else
extern "C" void guardian() {
    static int interrupt_count = 0;
    static int row = 0; // Start at row 0

    // Print interrupt message on a new line
    kout.setpos(0, row);
    kout << "Interrupt #" << interrupt_count++ << " received" << endl;
    kout.flush();

    // Move to the next line for the next interrupt
    row++;
    if (row >= 25) { // Assuming 25 rows in CGA display, wrap around
        row = 0;
        kout.setpos(0, 0); 
    }
}

void guardian (unsigned int slot){}
