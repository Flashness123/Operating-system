/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             C G A _ S C R E E N                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* This class allows accessing the PC's screen.  Accesses work directly on   */
/* the hardware level, i.e. via the video memory and the graphic adapter's   */
/* I/O ports.                                                                */
/*****************************************************************************/

#include "machine/cgascr.h" // ensures the comipler knows about the class
#include "machine/io_port.h" 
CGA_Screen::CGA_Screen(){}  // constructor

void CGA_Screen::show(int x, int y, char c, unsigned char attrib) {
    // Validate input
    // Note: CGA screen size is typically 80x25
    if (x < 0 || x >= 80 || y < 0 || y >= 25) {
        return; // Out of bounds
    }
    // Note: CGA always begins at 0xB8000
    // Calculate memory address: 0xB8000 + 2 * (y * 80 + x)
    unsigned short* video_memory = (unsigned short*)0xB8000; //the cast is then treating the address as a pointer to an array of unsigned shorts
    int offset = y * 80 + x;
    
    // Write character and attribute
    video_memory[offset] = (attrib << 8) | c;  //<< shifts by 8 bits to the left, here writing to the high byte
    // The attribute is in the high byte, and the character is in the low byte
    // The | operator combines the two values into a single 16-bit value

}

void CGA_Screen::getpos (int &x, int &y){
    IO_Port index_port(0x3D4);
    IO_Port data_port(0x3D5);

    index_port.outb(14); // I want to read high byte
    unsigned char high_byte = data_port.inb(); // Read high byte
    index_port.outb(15); // I want to read low byte
    unsigned char low_byte = data_port.inb(); // Read low byte
    unsigned short offset = (static_cast<unsigned short>(high_byte) << 8) | low_byte;

    y = offset / 80;
    x = offset % 80;
} 

void CGA_Screen::setpos (int x, int y)
/*  Index port (0x3D4): To select the cursor register (e.g., 14 for high byte, 15 for low byte).
    Data port (0x3D5): To write the actual cursor position value.*/
{
    if (x < 0 || x >= 80 || y < 0 || y >= 25) return; 

    // Calculates my CGA coordinates from the x,y values
    // static_cast<target_type>(expression) - safer way of casting values, casted so max 16 bits used
    unsigned short offset = static_cast<unsigned short>(y * 80 + x);

    // Use separate ports for index and data
    IO_Port index_port(0x3D4); // Index register, which register to access
    IO_Port data_port(0x3D5);  // Data register, writes the actual data

    // Set high byte of cursor position
    index_port.outb(14); // Here the high byte is stored
    // casted so that max 8 bits used
    data_port.outb(static_cast<unsigned char>(offset >> 8)); // Get first 8 bits of number - Write high byte

    // Set low byte of cursor position
    index_port.outb(15); // Here the low byte is stored
    data_port.outb(static_cast<unsigned char>(offset & 0xFF)); // Write low byte
}

void CGA_Screen::print (char* text, int length, unsigned char attrib)
{
    if (length <= 0) return; 

    int x, y;
    getpos(x, y); 
    unsigned short* video_memory = (unsigned short*)0xB8000;

    for (int i = 0; i < length; i++) {
        if (text[i] == '\n') {
            y++;
            x = 0;
        } else {
            show(x, y, text[i], attrib);
            x++;
        }

        if (x >= 80) {
            x = 0;
            y++;
        }

        if (y >= 25) {
            // Move everything up one line
            for (int j = 0; j < 24; j++) {
                for (int k = 0; k < 80; k++) {
                    video_memory[j * 80 + k] = video_memory[(j + 1) * 80 + k]; //write to destination j the car from j+1
                }
            }
            for (int k = 0; k < 80; k++) {
                video_memory[24 * 80 + k] = (attrib << 8) | 0x20; // Space = 0x20
            }
            y = 24;
            x = 0; 
        }
    }

    if (y < 25) {
        setpos(x, y);
    } else {
        setpos(0, 24);
    } 
}