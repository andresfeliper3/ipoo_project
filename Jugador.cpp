/*
  Archivo: Jugador.cpp
  Autor: Andr√©s Rinc√≥n "andres.rincon.lopez@correounivalle.edu.co"
  		   JosÈ David Barona Hern·ndez "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creaci√≥n: 2020-03-30
  Fecha √∫ltima modificaci√≥n: 2020-04-03
*/

#include "Jugador.h"


Jugador::Jugador()
{
	tecla = "";
	partidaEnCurso = true;
}

Jugador::~Jugador()
{
	for (i = 0; i < individuos.size(); i++ )
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
	}
}


void Jugador::leerTeclado()
{
	getline(tecla, cin);
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


void Jugador::moverBarca()
{
	lugares[1]->moverseDeOrilla();	
	
	if (lugares[0]->revisarSiPierde() or lugares[2]->revisarSiPierde())
	{
		partidaEnCurso = false;
		cout << "\n\n°Has perdido la partida!\n\n";
	}
	
	if (lugares[2]->cantidadDeIndividuos() == individuos.size())
	{
		partidaEnCurso = false;
		cout << "\n\n°Has ganado la partida!\n\n"	
	}
}



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









