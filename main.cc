#include "machine/cgascr.h"
#include "device/cgastr.h"
#include "device/cgastr.h"
#include "machine/keyctrl.h"
#include "machine/cgascr.h"
#include "user/appl.h"
#include "object/o_stream.h"

// int main() {
//     CGA_Stream kout;
//     Keyboard_Controller keyboard;
//     kout << "Press a key (or Esc to exit):" << endl;
//     while (true) {
//         Key key = keyboard.key_hit();
//         if (key.valid()) {
//             kout << "ASCII: " << (int)key.ascii() << ", Scancode: " << (int)key.scancode() << endl;
//             if (key.scancode() == 1) { // Esc key
//                 kout << "Esc pressed, exiting..." << endl;
//                 break;
//             }
//         }
//     }
//     return 0;
// }

int main(){
    CGA_Stream kout;
    kout << "Test          <stream result> -> <expected>" << endl;
    kout << "zero:         " << 0 << " -> 0" << endl;
    kout << "decimal:      " << dec << 42 << " -> 42" << endl;
    kout << "binary:       " << bin << 42 << dec << " -> 0b101010" << endl;
    kout << "octal:        " << oct << 42 << dec << " -> 052" << endl;
    kout << "hex:          " << hex << 42 << dec << " -> 0x2a" << endl;
    kout << "uint64_t max: " << ~((unsigned long)0) << " -> 18446744073709551615" << endl;
    kout << "int64_t max:  " << ~(1l<<63) << " -> 9223372036854775807" << endl;
    kout << "int64_t min:  " << (1l<<63) << " -> -9223372036854775808" << endl;
    kout << "some int64_t: " << (-1234567890123456789) << " -> -1234567890123456789" << endl;
    kout << "some int64_t: " << (1234567890123456789) << " -> 1234567890123456789" << endl;
    kout << "pointer:      " << reinterpret_cast<void*>(1994473406541717165ul) << " -> 0x1badcafefee1dead" << endl;
    kout << "smiley:       " << static_cast<char>(1) << endl;

    kout << "binary long   " << bin << ~((unsigned long)0) << endl; 
    kout << "binary long   " << bin << -42 << endl; 
    return 0;
}
