/*
  Archivo: Orilla.cpp
  Autores: Andrés Rincón "andres.rincon.lopez@correounivalle.edu.co"
  		   Jos� David Barona Hern�ndez "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creación: 2020-03-30
  Fecha última modificación: 2020-03-30
*/

#include "Orilla.h"

Orilla::Orilla(string nombreLugar,Lugar *lugarVecino): Lugar(nombreLugar, lugarVecino)

{
	//Constructor
}

Orilla::~Orilla()
{
	//Destructor
}

//Cambia de lugar vecino dependiendo del movimiento de la Barca
void Orilla::cambiarDeVecino(Lugar *nuevoLugarVecino)
{
	if(lugarVecino)
	{
		this->lugarVecino = nullptr; //deja de conocer la Barca
	}else
	{
		this->lugarVecino = nuevoLugarVecino; //Conoce la Barca
	}
}

