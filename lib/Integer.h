#ifndef INTEGER_H_
#define INTEGER_H_

#include "Object.h"

class Integer : public Object {
public:
	Integer();
	Integer( int );
	virtual ~Integer();
	int get ();
private:
	int * entero;
	int _entero ();
	void _entero ( int );
};

#endif /*INTEGER_H_*/
