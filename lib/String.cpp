#include "String.h"

using namespace std;

String::String(){
	this->str = new string;
}

String::String( const char * str ){
	this->_string( new string( str ) );
}

String::~String(){
	delete this->_string();
}

const char * String::get(){
	return this->_string()->data();
}


// ---------------------------------------------------------

void String::_string ( string * str ){
	this->str = str;
}

string * String::_string ( ){
	return this->str;
}
