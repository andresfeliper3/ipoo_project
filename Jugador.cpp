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

//Constructor
Jugador::Jugador(bool partidaEnCurso) : partidaEnCurso(partidaEnCurso)
{
	tecla = "";
}
//Destructor
Jugador::~Jugador()
{
	//Destruye todos los individuos creados para la partida
	for (int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++ )
	{
		delete individuos[cualIndividuo];
		individuos[cualIndividuo] = nullptr;	
	}	
	
}

//Crea un individuo, y lo añade al vector de individuos y a la orilla izquierda
void Jugador::crearIndividuo(string nombre, string letraParaMover)
{
	individuos.push_back(new Individuo(nombre, letraParaMover)); 
  	lugares[0]->agregarIndividuo(individuos.back());
}


void Jugador::conocerLugar(Lugar* nuevoLugar)
{
	if (nuevoLugar != nullptr)
	{
		lugares.push_back(nuevoLugar);

  //  REVISAR
    if (lugares.size() == 3)
    { 
     // lugares[1]->conocerOrillas(lugares[0]);
     // lugares[1]->conocerOrillas(lugares[2]);
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


void Jugador::moverBarca()
{
  
	lugares[1]->cambiarDeVecino(); //Cambia el lugar vecino de la barca	
//ESTO FUNCIONA

	if (lugares[0]->revisarSiPierde() or lugares[2]->revisarSiPierde())
	{
    //Perdiste
		partidaEnCurso = false;
   // perdiste();
	}
	
	if (lugares[2]->cantidadDeIndividuos() == individuos.size())
	{
    //Ganaste
		partidaEnCurso = false;
    //ganaste();
	}
}
//REVISAR Y REACTIVAR ESTA FUNCIÓN

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
		
		if ( "B" == tecla )
		{
			this->moverBarca();
		}
		
		this->estado();
	}
}



void Jugador::estado()
{
  const int espaciado = lugares[0]->mostrarNombre().size();
  //Imprime los nombres de los lugares
	for (int cualLugar = 0; cualLugar < lugares.size()+1; cualLugar++)
	{
		if(cualLugar != 2 && cualLugar != 3) //Orilla izq. y barca
    {
      cout <<lugares[cualLugar]->mostrarNombre() << "        "<< "|" << "        ";
    }
    else if(cualLugar == 2) //Espacio vacío
    {
      cout << "        "<< "|" << "        ";
    }
    else //Orilla derecha
    {
      cout << lugares[cualLugar-1]->mostrarNombre() << endl << endl;
    }

	}
	//Imprime los individuos de la orilla izquierda
	for (int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++)
	{
		for (int cualLugar = 0; cualLugar < lugares.size(); cualLugar++)
		{
			if (lugares[cualLugar]->individuoPresente(individuos[cualIndividuo]))
			{
				cout << individuos[cualIndividuo]->mostrarNombre();
			}
			else
			{
				cout << "\t";
			}
		
			cout << "        " << " | " << "        ";
		}
		cout << endl << endl;
	}
  //Imprime las instrucciones para mover los individuos
  cout << "Presione una tecla para jugar: " << endl << endl;

  for(int cualIndividuo = 0; cualIndividuo < individuos.size();cualIndividuo++)
  {

    cout << individuos[cualIndividuo]->mostrarNombre() << " salta de/a la barca con la tecla " << individuos[cualIndividuo]->mostrarLetraAsociada() << endl; 
    
  }
	
  cout << "Pulse B para mover la barca de una orilla a la otra" << endl;

}









