/*
  Archivo: Barca.cpp
  Autores: Andr√©s Rinc√≥n "andres.rincon.lopez@correounivalle.edu.co"
  		   JosÈ David Barona Hern·ndez "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creaci√≥n: 2020-03-30
  Fecha √∫ltima modificaci√≥n: 2020-03-30
*/

#include "Barca.h"


Barca::Barca(string nombreLugar,Lugar *lugarVecino) : nombreLugar(nombreLugar), Lugar(lugarVecino)
{
	//Constructor
}

Barca::~Barca()
{
	//Destructor
}

//Cambiar de Orilla
void Barca::cambiarDeOrilla(Lugar *lugarVecino)
{
	for(int cualIndividuo = 0;cualIndividuo < individuosPresentes.size(); cualIndividuo++)
	{
		if(individuosPresentes[cualIndividuo]->mostrarLetraAsociada() == "R")
		{
			this->LugarVecino = cambiarDeVecino(nullptr);
			this->LugarVecino = lugarVecino;
			lugarVecino->cambiarDeVecino(this);
		}
	}
}

//Recibir individuo
void Barca::agregarIndividuo(Individuo *recibirIndividuo)
{
	//La barca sÛlo puede transportar un individuo aparte del Robot
	if(individuosPresentes.size() <=1)
	{
		individuosPresentes.push_back(recibirIndividuo);
		recibirIndividuo->moverIndividuo(this);
	}
} 
