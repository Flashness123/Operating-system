make qemu

debug:
make qemu-gdb
+ second terminal make gdb

Hardware info:
I/O Port - to communicate with hardware devices, read or write to port to send information, receive - written in assembly


C++ Tips:
– signed int from -2^31 to 2^31-1
– unsigned int from 0 to 2^32-1
short = 16 bits = 8/ascii + 8/color
high byte = first 8 bits  (left)
low byte = second 8 bits  (right)

Dont forget constructor/destructor 
:: - tells compiler which class the method belongs to

pointers have types and & - adress, 
The & operator returns the memory address of a variable.
* accesses the value at the memory address stored in the pointer.
int x = 42;
int* ptr = &x; // ptr holds x’s address
int y = *ptr;  // *ptr gets the value at ptr’s address (42)
*ptr = 100;    // Changes x to 100 by writing to its address

high byte               /        low byte
15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0
2^

const -cannot be modified
static - shared across all instances and derived classes
virtual - can be overriden by derived classes
pure - no implementation in base (Syntax: =0)
copy!=assignment, assignment, makes the already created object have the same values, copy creates new object
&O_Stream - reference to O_Stream object
*this dereferences the pointer, yielding the O_Stream object itself
A reference is bound to an existing object and acts like that object, modifiing one, changes the other

private - not accessible to derived classes and external code
protected - accessible from derived classes but not external code

SETUP Task 2:
Keyboard controller on motherboard has buffer (in the Class is just teh driver), it activates a cabel if output buffer nonempty (key pressed) -> this is called interrupt signal, 
Programmable Interrupt controller is hardware (in PIC we just configuter it, like priority or enable/disable interrupts), cable from keyboard controller is attached to PIC, PIC has one single output cable which connects to CPU, so PIC only sends one at a time, unknown which, CPU asks which, PIC answers
CPU calls guardian and tells it the number which corresponds to the type of interrupt.
Guradian has in our case 64 different initerrupts and looks up what happens on which. 
Gate is base class for every interrupt handler (Panic -default=all dead, Keyboard=33), Derived class from gate executes trigger

QUESTIONS:
Functions vs Methods?
private vs protected?
Interpreter vs compiler?
Segmentation fault?
Fork and keep updates?