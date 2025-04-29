/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              P L U G B O X                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Abstracts an interrupt vector table. Allows to configure handler routines */
/* for every hardware and software interrupt and every CPU exception.        */
/*****************************************************************************/

#include "guard/gate.h"
#include "machine/plugbox.h"
#include "device/panic.h"
#include "device/cgastr.h"

Plugbox::Plugbox(){
    for (unsigned int i = 0; i < MAX_SLOTS; i++) {
        gates[i] = &panic;
    }

}

void Plugbox::assign(unsigned int slot, Gate& gate){
    kout << "Assign" << slot << endl;
    if (slot < MAX_SLOTS) {
        gates[slot] = &gate;
    }
    
}

Gate& Plugbox::report(unsigned int slot){
    kout << "Report" << slot << endl;
    if (slot < MAX_SLOTS) {
        return *gates[slot];
    }
    
    return panic;
}

Plugbox plugbox;