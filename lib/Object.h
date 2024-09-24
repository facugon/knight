#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>

using namespace std;

class Object{

public:
	Object();
	virtual ~Object();
	bool isEqual ( Object * );	//// si es el mismo objeto
	bool notEqual ( Object * );
	bool isNull ( Object * );
	bool notNull ( Object * );
	void inspeccionar();
	string * nombre();
	void nombre(string *);


private:
	string * _nombre;
};

#endif // OBJECT_H
