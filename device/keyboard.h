/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Keyboard driver.                                                          */
/*****************************************************************************/

#ifndef __Keyboard_include__
#define __Keyboard_include__

#include "machine/keyctrl.h"
#include "guard/gate.h"
#include "machine/key.h"
 
class Keyboard : public Keyboard_Controller, public Gate
{
public:
	Keyboard(const Keyboard &copy) = delete; // prevent copying
	Keyboard& operator=(const Keyboard&) = delete; // prevent assignment

	Keyboard(); // constructor
	~Keyboard() {} 


 
	// PLUGIN: "Plugs in" the keyboard (driver). From now on, keypresses are handled.
	void plugin();
	void trigger();

};

#endif
