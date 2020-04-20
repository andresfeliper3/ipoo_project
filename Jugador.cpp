/*
  Archivo: Jugador.cpp
  Autor: Andrés Rincón "andres.rincon.lopez@correounivalle.edu.co"
  		   Jos� David Barona Hern�ndez "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creación: 2020-03-30
  Fecha última modificación: 2020-04-03
*/

#include<iostream>
#include "Jugador.h"
#include <string>


Jugador::Jugador()
{
	tecla = "";
	partidaEnCurso = true;
}

Jugador::~Jugador()
{
	for (int i = 0; i < individuos.size(); i++ )
	{
		delete individuos[i];
		individuos[i] = nullptr;	
	}	
	
}


void Jugador::crearIndividuo(string nombre, string letraParaMover)
{
	individuos.push_back(new Individuo(nombre, letraParaMover));
}


void Jugador::conocerLugar(Lugar* nuevoLugar)
{
	if (nuevoLugar != nullptr)
	{
		lugares.push_back(nuevoLugar);

    if (lugares.size() == 2)
    { 
      lugares[1]->conocerOrillas(lugares[0]);
      lugares[1]->conocerOrillas(lugares[2]);
    }
	}
}


void Jugador::agregarPresa (Individuo* predador, Individuo* presa)
{
  predador->agregarPresa(presa);
}



void Jugador::leerTeclado()
{
	getline(cin,tecla);
	this->jugar(tecla);
}



void Jugador::moverIndividuo(Individuo* individuo)
{
	for (int c = 0; c < lugares.size(); c++)
	{
		for (int d = 0; d < individuos.size(); d++)
		{
			if (lugares[c]->individuoPresente(individuos[d]) >= 0 )
			{
				lugares[c]->moverIndividuo(individuos[d]);
				break;
			}
		}
	}
}

//Jugador debe encargarse de que Barca conozca a las dos orillas.

/* REVISAR ESTO XD!
void Jugador::moverBarca()
{
  
	lugares[1]->cambiarDeVecino(Lugar); //Cambia el lugar vecino de la barca	
	
	if (lugares[0]->revisarSiPierde() or lugares[2]->revisarSiPierde())
	{
		partidaEnCurso = false;
		cout << "\n\n�Has perdido la partida!\n\n";
	}
	
	if (lugares[2]->cantidadDeIndividuos() == individuos.size())
	{
		partidaEnCurso = false;
		cout << "\n\n�Has ganado la partida!\n\n"	
	}
}
*/

void Jugador::jugar(string tecla)
{
	while (partidaEnCurso)
	{
		for (int i = 0; i < individuos.size(); i++ )
		{
			if (individuos[i]->mostrarLetraAsociada() == tecla)
			{
				this->moverIndividuo(individuos[i]);
				break;
			}
		}	
		
		if ( lugares[1]->mostrarLetraAsociada() == tecla )
		{
			this->moverBarca();
		}
		
		this->estado();
	}
}



void Jugador::estado()
{
  //Imprime los nombres de los lugares
	for (int cualLugar = 0; cualLugar < lugares.size(); cualLugar++)
	{
		cout <<lugares[cualLugar]->mostrarNombre() << "\t" << "|" << "\t";
	}
	//Imprime los individuos de la orilla izquierda
	for (int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++)
	{
		for (int n = 0; n < lugares.size(); n++)
		{
			if (lugares[n]->individuoPresente(individuos[cualIndividuo]) >= 0)
			{
				cout << individuos[cualIndividuo]->mostrarNombre();
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









