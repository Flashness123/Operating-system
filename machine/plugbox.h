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

#ifndef __Plugbox_include__
#define __Plugbox_include__

#include "guard/gate.h"
#include "device/panic.h"

class Plugbox {
public:
	static const unsigned int timer = 32;
	static const unsigned int keyboard = 33;

	Plugbox(const Plugbox &copy) = delete; // prevent copying
	Plugbox& operator=(const Plugbox&) = delete; // prevent assignment

	Plugbox();
	void assign(unsigned int slot, Gate& gate);
	Gate& report(unsigned int slot);
private:
	static const unsigned int MAX_SLOTS = 64;
	Gate* gates[MAX_SLOTS];
	Panic panic;
};

// Example
extern Plugbox plugbox;

#endif
