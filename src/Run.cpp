/*
 * Run.c
 *
 *  Created on: 29/07/2008
 *      Author: Facundo
 */
#include "Run.h"
#include <string>
#include "../lib/Framework.h"

using namespace std;

int main(int argc, char **argv) {

	Tablero * tablero;
	Caballero * caballo;


	tablero = new Tablero;
	caballo = new Caballero;

	caballo->tablero(tablero);

	caballo->obtenerCaminos();

	return 0;

}

//////////////////////////////////////////////////////



