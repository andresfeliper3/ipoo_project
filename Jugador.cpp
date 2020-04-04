/*
  Archivo: Jugador.cpp
  Autor: Andrés Rincón "andres.rincon.lopez@correounivalle.edu.co"
  		   Jos� David Barona Hern�ndez "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creación: 2020-03-30
  Fecha última modificación: 2020-04-03
*/

#include "Jugador.h"
#include "iomanip"

Jugador::Jugador()
{
	tecla = "";
}

Jugador::~Jugador()
{
	for (i = 0; i < individuos.size(); i++ )
	{
		delete individuos[i];
		individuos[i] = nullptr;	
	}	
	
}


Jugador::crearIndividuo(string nombre, string letraParaMover)
{
	individuos.push_back(new Individuo(nombre, letraParaMover));
}


Jugador::conocerLugar(Lugar* nuevoLugar)
{
	if (nuevoLugar != nullptr)
	{
		lugares.push_back(nuevoLugar);
	}
}


Jugador::leerTeclado()
{
	getline(tecla, cin);
	this->jugar(tecla);
}

Jugador::moverIndividuo(Individuo* individuo)
{
	for (int n = 0; n < lugares.size(); n++)
	{
		
	}
}



Jugador::jugar()
{
	for (int i = 0; i < individuos.size(); i++ )
	{
		if (individuos[i]->decirLetra == tecla)
		{
			this->moverIndividuo();
		}
	}
	
	
	if ( lugares[2]->decirLetra == tecla )
	{
		this->moverBarca();
	}
}










