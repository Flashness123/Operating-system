/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Keyboard driver.                                                          */
/*****************************************************************************/

/* Add your code here */ 
#include "device/keyboard.h"
#include "machine/plugbox.h"
#include "guard/gate.h"
#include "machine/key.h"
#include "device/cgastr.h"

//extern CGA_Stream kout;

Keyboard::Keyboard() : Gate() {}

void Keyboard::plugin(){
    kout << "Keyboard plugin" << endl;
    plugbox.assign(plugbox.keyboard, *this);
}

void Keyboard::trigger(){
    if(key_hit().valid()){
        Key key = key_hit();
        if (key.scancode() == Key::scan::del){ Keyboard_Controller::reboot(); } //was das
        kout << "Key pressed: " << key.ascii() << endl;
        kout.flush();
    
    }
    else{
        // Handle no key press
    }
}

