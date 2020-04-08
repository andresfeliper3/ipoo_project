/*
  Archivo: Orilla.cpp
  Autores: Andrés Rincón "andres.rincon.lopez@correounivalle.edu.co"
  		   Jos� David Barona Hern�ndez "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creación: 2020-03-30
  Fecha última modificación: 2020-03-30
*/

#include "Orilla.h"

Orilla::Orilla(Lugar *lugarVecino)
: LugarVecino(lugarVecino)
{
	//Constructor
}

Orilla::~Orilla()
{
	//Destructor
}
	    
//Quita el lugar vecino debido al movimiento
void Orilla::quitarLugarVecino()
{
	this->lugarVecino = nullptr;
}

//Pone un lugar vecino debido al movimiento
void Orilla:: agregarLugarVecino(Lugar *nuevoLugarVecino)
{
	this->lugarVecino = nuevoLugarVecino;
}


