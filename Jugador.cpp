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
	for (int c = 0; c < lugares.size(); c++)
	{
		for (int d = 0; d < individuos.size(); d++)
		{
			if (lugares[c]->individuoPresente(individuos[d]) >= 0 )
			{
				lugar::moverIndividuo(individuos[d]);
				break;
			}
		}
	}
}


Jugador::moverBarca()
{
	Barca::moverseDeOrilla();	
}



Jugador::jugar(string tecla)
{
	for (int i = 0; i < individuos.size(); i++ )
	{
		if (individuos[i]->mostrarLetraAsociada() == tecla)
		{
			this->moverIndividuo(individuos[i]);
			break;
		}
	}

		
	if ( lugares[2]->mostrarLetraAsociada() == tecla )
	{
		this->moverBarca();
	}
}



Jugador::estado()
{
	for (int i = 0; i < lugares.size(); i++)
	{
		cout << lugares[i]->mostrarNombre() << "\t" << "|" << "\t";
	}
	
	
	for (int i = 0; i < individuos.size(); i++)
	{
		for (int n = 0; n < lugares.size(); n++)
		{
			if (lugar[n]->individuoPresente(individuos[i]) >= 0)
			{
				cout << individuos[i]->mostrarNombre();
			}
			else
			{
				cout << "\t";
			}
		
			cout << "\t" << "|" << "\t";
		}
		cout << endl;
	}
	
}









