/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                       S T R I N G B U F F E R                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Stringbuffer class provides a buffer for collecting characters to be  */
/* printed to an output device, in our case the PC screen. The actual output */
/* occurs once the buffer is full, or when the user explicitly calls         */
/* flush().                                                                  */
/* As Stringbuffer is intended to be device independent, flush() is a        */
/* (pure) virtual method that must be defined by derived classes.            */
/*****************************************************************************/

#include "object/strbuf.h"

Stringbuffer::Stringbuffer(){
    buffer_size = 0;
} 

void Stringbuffer::put (char c){
    /*For this to work, note:   flush() only reads up to buffer_size*/
    if (buffer_size >= BUFFER_SIZE) {
        flush();
        buffer_size = 0;  //could be called pos
    }
    buffer[buffer_size] = c;
    buffer_size++; //point to a free position
}
