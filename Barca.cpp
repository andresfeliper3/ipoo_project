/*
  Archivo: Barca.cpp
  Autores: Andrés Rincón "andres.rincon.lopez@correounivalle.edu.co"
  		   Jos� David Barona Hern�ndez "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creación: 2020-03-30
  Fecha última modificación: 2020-03-30
*/

#include "Barca.h"


Barca::Barca(string nombreLugar,Lugar *lugarVecino, string letraAsociada): Lugar(nombreLugar, lugarVecino)
{
	//Constructor
  this->letraAsociada = letraAsociada;
}

Barca::~Barca()
{
	//Destructor
}

//Cambiar de Orilla
void Barca::cambiarDeVecino(Lugar *lugarVecino)
{
	for(int cualIndividuo = 0;cualIndividuo < individuosPresentes.size(); cualIndividuo++)
	{
		if(individuosPresentes[cualIndividuo]->mostrarLetraAsociada() == "R") //Reconoce si el robot está en la orilla 
		{
      this->LugarVecino = nullptr; //La barca deja de conocere a la orilla
			this->LugarVecino = lugarVecino; //La barca conoce a su nuevo vecino
			lugarVecino->cambiarDeVecino(this);//  nueva orilla conoce a la Barca
	  }
  }	
}

/*
REVISAR ESTO!!!!
//Recibir individuo
void Barca::agregarIndividuo(Individuo *recibirIndividuo)
{
	//La barca s�lo puede transportar un individuo aparte del Robot
	if(individuosPresentes.size() <=1)
	{
		individuosPresentes.push_back(recibirIndividuo);
		recibirIndividuo->moverIndividuo(this);
    this->moverIndividuo(recibirIndividuo);
	}

  //
} 
*/

string Barca::mostrarLetraAsociada()
{
  return letraAsociada;
}

//Agrega una nueva orilla al vector de orillas conocidas de la barca
void Barca::conocerOrillas(Lugar *orilla)
{
  orillas.push_back(orilla);
}