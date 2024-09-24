#ifndef CHAR_H_
#define CHAR_H_

#include "Object.h"

class Char : public Object {
public:
	Char();
	Char( char );
	virtual ~Char();
	char get();
private:
	char * caracter;
	char _caracter ();
	void _caracter ( char );
};

#endif /*CHAR_H_*/
