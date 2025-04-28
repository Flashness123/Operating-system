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
#include "machine/plugbox.h"
#include "guard/gate.h"
//extern "C" void guardian (unsigned int slot);

/* GUARDIAN: Low-level interrupt handling. We will extend this function at */
/*           a later point in time.  */

//testing:
extern Plugbox plugbox;
extern CGA_Stream kout;

extern "C" void guardian(unsigned int slot) {
    Gate& gate = plugbox.report(slot);
    kout << "Guardian: Interrupt " << slot << " occurred." << endl;
    kout.flush();
    //gate.trigger();
}