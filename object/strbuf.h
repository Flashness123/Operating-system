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

#ifndef __strbuf_include__
#define __strbuf_include__

class Stringbuffer {
protected:
	static const int BUFFER_SIZE = 1024;
	int buffer_size;
	char buffer[BUFFER_SIZE];

public:
	Stringbuffer();
	Stringbuffer(const Stringbuffer &copy) = delete; // Prevents creating a Stringbuffer object by copying another, thaey would share the same buffer
	Stringbuffer& operator=(const Stringbuffer&) = delete; // prevent assignment
	void put (char c);
	virtual void flush()=0;
};

#endif
