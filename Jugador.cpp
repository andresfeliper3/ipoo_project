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
Individuo* Jugador::crearIndividuo(string nombre, string letraParaMover)
{
	Individuo* nuevoIndividuo = new Individuo(nombre, letraParaMover);
	individuos.push_back(nuevoIndividuo); 
  	lugares[0]->agregarIndividuo(nuevoIndividuo);
	return nuevoIndividuo;
}

//Añade un lugar al vector de lugares
void Jugador::conocerLugar(Lugar* nuevoLugar)
{
	if (nuevoLugar)
	{
		lugares.push_back(nuevoLugar);
	}
}

//Añade la barca a la parte privada
void Jugador::conocerBarca(Barca* barca)
{
	if(barca)
	{
		this->barca = barca;
	}
}

//Agrega una presa a un predador correspondiente
void Jugador::agregarPresa (Individuo* predador, Individuo* presa)
{
  predador->agregarPresa(presa);
}

//Recibe la tecla oprimida por el usuario y la guarda en la parte privada
void Jugador::leerTeclado()
{
	getline(cin,tecla);
}

//Mueve un individuo al lugar vecino del lugar que esté.
bool Jugador::moverIndividuo(Individuo* individuo)
{
	for (int cualLugar = 0; cualLugar < lugares.size(); cualLugar++)
	{
		for (int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++)
		{
			if (lugares[cualLugar]->individuoPresente(individuos[cualIndividuo]) >= 0 ) //Revisa si el individuo está presente en el lugar
			{
				lugares[cualLugar]->moverIndividuo(individuos[cualIndividuo]); //NOTA: ESTA FUNCIÓN YA REVISA QUE EL INDIVIDUO ESTÉ PRESENTE
				//break; ?
				return true;
			}
		}
	}
	return false;
}

//Jugador debe encargarse de que Barca conozca a las dos orillas.


void Jugador::revisarPartida()
{
	//
	//lugares[1]->cambiarDeVecino(); //Cambia el lugar vecino de la barca	
	if (lugares[0]->revisarSiPierde() or lugares[2]->revisarSiPierde())
	{
    //Perdiste
		partidaEnCurso = false;
   // perdiste();
	} 
	else if (lugares[2]->cantidadDeIndividuos() == individuos.size())
	{
    //Ganaste
		partidaEnCurso = false;
    //ganaste();
	}
}

//Mostrar la tecla oprimida por el usuario
string Jugador::mostrarTecla()
{
	return tecla;
}

//Mostrar si la partida está en curso
bool Jugador::mostrarSiPartidaEnCurso()
{
	return partidaEnCurso;
}

/*Compara la letra recibida de leerTeclado con las letras correspondientes a cada individuo y a la barca y al encontrar una coincidencia, hace que se se mueva a su lugar vecino. */
void Jugador::jugar(string tecla)
{
	if (partidaEnCurso) //Mientras la partida esté en curso
	{
		if ( barca->mostrarLetraAsociada() == tecla ) //Si el usuario ha marcado la tecla de la barca, la barca se mueve
		{
			barca->movimientoDeBarca();
		}
		for (int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++ )
		{
			if (individuos[cualIndividuo]->mostrarLetraAsociada() == tecla)
			{
				this->moverIndividuo(individuos[cualIndividuo]);
				break;
			}
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
	
  cout << "Pulse " << this->barca->mostrarLetraAsociada() << " para mover la barca de una orilla a la otra" << endl;

}









