/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            O _ S T R E A M                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The O_Stream class defines the << operator for several pre-defined data   */
/* types and thereby realizes output functionality similar to C++'s iostream */
/* library. By default, this class supports printing characters, strings and */
/* integer numbers of various bit sizes. Another << operator allows to use   */
/* so-called 'manipulators'.                                                 */
/*                                                                           */
/* Besides class O_Stream this file also defines the manipulators hex, dec,  */
/* oct and bin for choosing the basis in number representations, and endl    */
/* for implementing an (implicitly flushing) line termination.               */
/*****************************************************************************/

#include "object/o_stream.h"

void O_Stream::putbase(int base){
    switch(base){
        case 2: //binary
            put('0');
            put('b');
            break;
        case 8: //octal
            put('0');
            //put('o');
            break;
        case 10: //decimal
            break;
        case 16: //hexadecimal
            put('0');
            put('x');
            break;
        default:
            break;
    }
}

O_Stream::O_Stream() : Stringbuffer(){}

O_Stream& O_Stream::operator<< (char c){
    put(c);
    return *this; //important to chain operators, it gives the value at the memory and O_Stream then returns it as a reference
}

O_Stream& O_Stream::operator<< (unsigned char c){ 
    /*C++ implicitly converts unsigned char to char (same size, 8 bits)*/
    put(c);
    return *this;
}

O_Stream& O_Stream::operator<< (unsigned short number) { //     /-ganzzahldivision
    putbase(base);
    char buf[17]; // 16 bits for binary + 1 extra
    int pos = 16;
    if (number == 0) {
        put('0');
        return *this;
    }
    while (number > 0 && pos >= 0) {
        int digit = number % base;
        buf[pos] = (digit < 10) ? '0' + digit : 'a' + (digit - 10);
        number /= base;
        pos--;
    }
    for (int i = pos + 1; i < 17; i++) {
        put(buf[i]);
    }
    return *this;
}

O_Stream& O_Stream::operator<< (short number) {
    putbase(base);
    char buf[17];
    int pos = 16;
    if (number == 0) {
        put('0');
        return *this;
    }
    unsigned short num;
    if (number < 0 && base == 10) {
        put('-');
        num = -number; // Absolute value
    } else {
        num = static_cast<unsigned short>(number);
    }
    while (num > 0 && pos >= 0) {
        int digit = num % base;
        buf[pos] = (digit < 10) ? '0' + digit : 'a' + (digit - 10);
        num /= base;
        pos--;
    }
    for (int i = pos + 1; i < 17; i++) {
        put(buf[i]);
    }
    return *this;
}

O_Stream& O_Stream::operator<< (unsigned int number) {
    putbase(base);
    char buf[33];
    int pos = 32;
    if (number == 0) {
        put('0');
        return *this;
    }
    while (number > 0 && pos >= 0) {
        int digit = number % base;
        buf[pos] = (digit < 10) ? '0' + digit : 'a' + (digit - 10);
        number /= base;
        pos--;
    }
    for (int i = pos + 1; i < 33; i++) {
        put(buf[i]);
    }
    return *this;
}

O_Stream& O_Stream::operator<< (int number) {
    putbase(base);
    char buf[33];
    int pos = 32;
    if (number == 0) {
        put('0');
        return *this;
    }
    unsigned int num;
    if (number < 0 && base == 10) { // Decimal: show sign
        put('-');
        num = -number;
    } else {
        num = static_cast<unsigned int>(number); // 2’s complement but how?
    }
    while (num > 0 && pos >= 0) {
        int digit = num % base;
        buf[pos] = (digit < 10) ? '0' + digit : 'a' + (digit - 10);
        num /= base;
        pos--;
    }
    for (int i = pos + 1; i < 33; i++) {
        put(buf[i]);
    }
    return *this;
}

O_Stream& O_Stream::operator<< (unsigned long number) {
    putbase(base);
    char buf[65];
    int pos = 64;
    if (number == 0) {
        put('0');
        return *this;
    }
    while (number > 0 && pos >= 0) {
        int digit = number % base;
        buf[pos] = (digit < 10) ? '0' + digit : 'a' + (digit - 10);
        number /= base;
        pos--;
    }
    for (int i = pos + 1; i < 65; i++) {
        put(buf[i]);
    }
    return *this;
}

O_Stream& O_Stream::operator<< (long number) {//because of 64?
    putbase(base);
    char buf[65];
    int pos = 64;
    if (number == 0) {
        put('0');
        return *this;
    }
    unsigned long num;
    if (number < 0 && base == 10) {
        put('-');
        num = -number;
    } else {
        num = static_cast<unsigned long>(number);
    }
    while (num > 0 && pos >= 0) {
        int digit = num % base;
        buf[pos] = (digit < 10) ? '0' + digit : 'a' + (digit - 10);
        num /= base;
        pos--;
    }
    for (int i = pos + 1; i < 65; i++) {
        put(buf[i]);
    }
    return *this;
}

O_Stream& O_Stream::operator<< (void* ptr) {
    unsigned long addr = reinterpret_cast<unsigned long>(ptr);
    char buf[19]; // Enough for "0x" + 16 digits (64-bit max)
    int pos = 18;
    // Prefix
    put('0');
    put('x');
    
    if (addr == 0) {
        put('0');
        return *this;
    }
    //to hex
    while (addr > 0 && pos >= 0) {
        int digit = addr % 16;
        buf[pos] = (digit < 10) ? '0' + digit : 'a' + (digit - 10);
        addr /= 16;
        pos--;
    }
    
    for (int i = pos + 1; i < 19; i++) {
        put(buf[i]);
    }
    return *this;
}

O_Stream& O_Stream::operator<< (char* text) { //?
    while (*text) {
        put(*text);
        text++;
    }
    return *this;
}

O_Stream& O_Stream::operator<< (O_Stream& (*fkt)(O_Stream&)) {
    return fkt(*this); // i think also returns *this
}

O_Stream& endl(O_Stream& os) {
    os.put('\n'); 
    os.flush();   
    return os;     //since not part of the class no *this pointer
}

O_Stream& bin(O_Stream& os) {
    os.setBase(2);
    return os;
}

O_Stream& oct(O_Stream& os) {
    os.setBase(8);
    return os;
}

O_Stream& dec(O_Stream& os) {
    os.setBase(10);
    return os;
}

O_Stream& hex(O_Stream& os) {
    os.setBase(16);
    return os;
}