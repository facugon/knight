#ifndef STRING_H_
#define STRING_H_

#include "Object.h"
#include <string>

using namespace std;

class String : public Object {
public:
	String();

	String( const char * );

	virtual ~String();

	const char * get();

private:
	string * str;

	void _string ( string * );

	string * _string ( );
};

#endif /*STRING_H_*/
