/*
  Archivo: Barca.cpp
  Autores: Andrés Rincón "andres.rincon.lopez@correounivalle.edu.co"
  		   Jos� David Barona Hern�ndez "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creación: 2020-05-05
  Fecha última modificación: 2020-05-05
*/
#include <iostream>
#include "Barca.h"

//Constructor
Barca::Barca(string nombreLugar, Lugar *lugarVecino, string letraAsociada): Lugar(nombreLugar, lugarVecino, letraAsociada)
{
	
}

Barca::~Barca()
{
	//Destructor
}

//Mueve la barca de una orilla a otra
void Barca::movimientoDeBarca() 
{
	this->cambiarDeVecino(); //Cambia el vecino de la barca
  orillas[0]->cambiarDeVecino(this); //La orilla izquierda cambia de vecino.
  orillas[1]->cambiarDeVecino(this); //La orilla derecha cambia de vecino.	 	
}

//Cambia el vecino de la barca entre las dos posibilidades que tiene: las dos orillas
void Barca::cambiarDeVecino(Lugar *nuevoLugarVecino) //PREGUNTAR
{
	if(this->lugarVecino == this->orillas[0]) //Si su vecino es la orilla izquierda, pasa a ser la orilla derecha
	{
		this->lugarVecino = orillas[1];
	}
	else if(this->lugarVecino == this->orillas[1]) //Si su vecino es la orilla derecha, pasa a ser la orilla izquierda
	{
		this->lugarVecino = orillas[0];
	}
}

//Muestra la letra asociada a la barca
string Barca::mostrarLetraAsociada()
{
  return letraAsociada;
}

//Agrega una nueva orilla al vector de orillas conocidas de la barca
void Barca::conocerOrillas(Lugar *orilla)
{
  orillas.push_back(orilla);
}


