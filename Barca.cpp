/*
  Archivo: Barca.cpp
  Autores: Andrés Rincón "andres.rincon.lopez@correounivalle.edu.co"
  		   Jos� David Barona Hern�ndez "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creación: 2020-03-30
  Fecha última modificación: 2020-03-30
*/
#include <iostream>
#include "Barca.h"

//Constructor
Barca::Barca(string nombreLugar, Lugar *lugarVecino, string letraAsociada): Lugar(nombreLugar, lugarVecino, letraAsociada)
{
	
 // lugarVecino->cambiarDeVecino(this);//  Le avisa a la orilla que tiene como vecina, que son vecinas.
}

Barca::~Barca()
{
	//Destructor
}

//Mueve la barca de una orilla a otra
void Barca::movimientoDeBarca() 
{
	cerr << "4 entra en movimientoDeBarca" << endl; 	
	this->cambiarDeVecino(); //Cambia el vecino de la barca
	cerr << " 4.3 barca cambia de vecino " << this->tieneVecino() <<endl;
    orillas[0]->cambiarDeVecino(this); //La orilla izquierda cambia de vecino.
	cerr << " 4.4 izq cambia de vecino " << orillas[0]->tieneVecino() <<endl;
   	orillas[1]->cambiarDeVecino(this); //La orilla derecha cambia de vecino.	
	cerr << " 4.5 der cambia de vecino " << orillas[1]->tieneVecino() <<endl;
	cerr << "5 cambia de vecinos en barca y orillas " <<endl; 	
}

//Cambia el vecino de la barca entre las dos posibilidades que tiene: las dos orillas
void Barca::cambiarDeVecino(Lugar *nuevoLugarVecino  /*= nullptr*/) //PREGUNTAR
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


