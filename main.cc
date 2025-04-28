#include "machine/cpu.h"
#include "machine/pic.h"
#include "device/keyboard.h"
#include "device/cgastr.h"
#include "machine/plugbox.h"

CPU cpu;
PIC pic;
Keyboard_Controller keyboard;
CGA_Stream kout;
Plugbox plugbox;

int main() {

    // Clear keyboard buffer
    while (keyboard.key_hit().valid()) {}

    cpu.enable_int();
    pic.allow(PIC::keyboard);

    int key_row = 10;
    while (true) {
        Key key = keyboard.key_hit();
        if (key.valid()) {
            kout.setpos(0, key_row);
            kout << "Key pressed: " << key.ascii() << endl;
            kout.flush();
            key_row++;
            if (key_row >= 25) {
                key_row = 10;
            }
        }
    }
    return 0;
}