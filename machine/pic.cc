/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I C                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interrupt Controller.                                        */
/* By using the PIC, hardware interrupts can be enabled or suppressed        */
/* individually. This way we can control whether interrupts of a specific    */
/* device are forwarded to the CPU at all. Even then, the interrupt handler  */
/* gets only activated if the CPU is ready to react to interrupts. This can  */
/* be controlled by using class CPU.                                         */
/*****************************************************************************/

/* Add your code here */ 

#include "machine/pic.h"
#include "machine/io_port.h"

const IO_Port PIC::data_port(0x21);

PIC::PIC(){}

void PIC::allow(int interrupt_device){
    unsigned char mask = data_port.inb();
    mask &= ~(1 << interrupt_device); //Shifts the number 1 to the left by interrupt_device, NOT flips all the bits, 0b00001000 → 0b11110111, AND
    data_port.outb(mask);
}

void PIC::forbid(int interrupt_device){
    unsigned char mask = data_port.inb();
    mask |= (1 << interrupt_device); //Shifts the number 1 to the left by interrupt_device, OR 
    data_port.outb(mask);
}

bool PIC::is_masked(int interrupt_device){
    // IO_Port data_port(0x21);
    unsigned char mask = data_port.inb();
    return (mask & (1 << interrupt_device)) != 0;
}


    