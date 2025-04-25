#include "machine/cpu.h"
#include "machine/pic.h"
#include "device/keyboard.h"
#include "device/cgastr.h"

CPU cpu;
PIC pic;
Keyboard_Controller keyboard;
CGA_Stream kout;

int main() {
    // Clear keyboard buffer to prevent residual interrupts
    while (keyboard.key_hit().valid()) {
        // Discard pending scan codes
    }

    // Enable interrupts
    cpu.enable_int();
    pic.allow(PIC::keyboard);

    // Test loop to read scan codes and print on new lines
    int key_row = 10; // Start key messages at row 10
    while (true) {
        Key key = keyboard.key_hit();
        if (key.valid()) {
            kout.setpos(0, key_row);
            kout << "Key pressed: " << key.ascii() << endl;
            kout.flush();

            // Move to the next line for the next key press
            key_row++;
            if (key_row >= 25) { // Wrap around if needed
                key_row = 10;
            }
        }
    }
    return 0;
}