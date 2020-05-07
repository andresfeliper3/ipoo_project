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
void Jugador::conocerBarca(Barca* nuevaBarca)
{
	if(nuevaBarca)
	{
		this->barca = nuevaBarca;
	}
}

//Añade al robot a la parte privada
void Jugador::conocerRobot(Individuo* nuevoRobot)
{
	if(nuevoRobot)
	{
		this->robot = nuevoRobot;
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
	getline(cin,this->tecla);
	cerr << "1, leer teclado " <<  tecla << " " << barca->mostrarLetraAsociada() <<endl;
}

//Mueve un individuo al lugar vecino del lugar que esté.
bool Jugador::moverIndividuo(Individuo* individuo)
{
	for (int cualLugar = 0; cualLugar < lugares.size(); cualLugar++)
	{
		if (lugares[cualLugar]->individuoPresente(individuo) >= 0 ) //Revisa si el individuo está presente en el lugar
		{
			if(lugares[cualLugar]->moverIndividuo(individuo))  //NOTA: ESTA FUNCIÓN YA REVISA QUE EL INDIVIDUO ESTÉ PRESENTE
			{
				cerr << "3.1 se ejecutó la función de moverIndividuo de Lugar "  <<endl;
				cerr << individuo->mostrarNombre() << " se movió desde " << lugares[cualLugar]->mostrarNombre() << " hasta su lugar vecino" <<endl;
				return true;
			}
		}	
	}
	return false;
}

//Jugador debe encargarse de que Barca conozca a las dos orillas.


void Jugador::revisarPartida(Individuo* robot)
{
	//lugares[1]->cambiarDeVecino(); //Cambia el lugar vecino de la barca	
	if (lugares[0]->revisarSiPierde(robot) or lugares[2]->revisarSiPierde(robot))
	{
    //Perdiste
		partidaEnCurso = false;
		cout << "Perdiste" <<endl; 
   // perdiste();
	} 
	else if (lugares[2]->cantidadDeIndividuos() == individuos.size())
	{
    //Ganaste
		partidaEnCurso = false;
		cout << "Ganaste" <<endl;
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
bool Jugador::jugar(string tecla)
{
	if (partidaEnCurso) //Mientras la partida esté en curso
	
	{
		cerr << "2 entra en Jugar " << tecla << " " << barca->mostrarLetraAsociada() <<  endl; 
		if ("B" == tecla ) //Si el usuario ha marcado la tecla de la barca, la barca se mueve
		{
			cerr << "2.1 " << barca->mostrarLetraAsociada() << endl; 
			if(barca->individuoPresente(this->robot) >= 0 )
			{
				cerr << "El robot está presente en la barca" << endl;
				if(barca->movimientoDeBarca()) //Si la barca se pudo mover
				{
					cerr << "3 Jugar activa el movimiento de la barca " << barca->mostrarNombre() << endl;
					return true;
				}	
			}
				
		}
		for (int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++ )
		{
			if (individuos[cualIndividuo]->mostrarLetraAsociada() == tecla)
			{
				cerr << "3 hay un individuo con la letra asociada " << individuos[cualIndividuo]->mostrarNombre() <<endl;
				if(this->moverIndividuo(individuos[cualIndividuo]))
				{
					cerr << "4 se ejecutó la función de moverIndividuo de Jugador para " << individuos[cualIndividuo] <<endl;
					//break;?
					return true;
				}		
			}
		}	
		throw "Presiona una tecla válida";		
	}
}



void Jugador::estado()
{
  const int espaciado = lugares[0]->mostrarNombre().size();
  bool orillaIzquierdaTieneVecino = true;

  //Imprime los nombres de los lugares
	for (int cualLugar = 0; cualLugar < lugares.size(); cualLugar++)
	{
		//Revisa si se está mirando la orilla derecha
		if(cualLugar == 2)
		{
			if(!lugares[cualLugar]->tieneVecino()) //Si la orilla derecha no tiene vecino
			{
				orillaIzquierdaTieneVecino = true;
				cout << "| \t \t \t |";
			}
		}
		cout << "|\t" << lugares[cualLugar]->mostrarNombre() << "\t  "; //Imprime el nombre del lugar
		if(cualLugar == 0) //Revisa si se está mirando la orilla izquierda
		{
			if(!lugares[cualLugar]->tieneVecino()) //Si la orilla izquierda no tiene vecino
			{
				orillaIzquierdaTieneVecino = false;
				cout << "| \t \t \t|";
			}
		}
	}
	cout << endl; 

	//Imprime a los individuos por orden según el vector de individuos. NO ME GUSTÓ MUCHO
	for (int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++)
	{
		if(lugares[0]->individuoPresente(individuos[cualIndividuo]) >= 0) //Si el individuo está en la orilla izquierda
		{
			cout << " | \t  " << individuos[cualIndividuo]->mostrarNombre() << "\t ";		
			cout << "| \t \t \t| \t \t \t | \t \t \t " << endl;
		} 
		else if(lugares[1]->individuoPresente(individuos[cualIndividuo]) >= 0) //Si el individuo está en la barca
		{
			if(orillaIzquierdaTieneVecino) //Si la barca está al lado izquiedo
			{
				cout << "| \t \t \t |";
				cout << " \t " << individuos[cualIndividuo]->mostrarNombre() << "\t ";
				cout << "| \t \t \t | \t \t \t |" << endl;
			}
			else //Si la barca está al lado derecho
			{
				cout << "| \t \t \t | \t \t \t |";
				cout << " \t " << individuos[cualIndividuo]->mostrarNombre() << "\t ";
				cout << "| \t \t \t |" << endl;
			}
		}
		else if(lugares[2]->individuoPresente(individuos[cualIndividuo]) >= 0) //Si el individuo está en la orilla derecha
		{
			cout << "| \t \t \t| \t \t \t | \t \t \t ";
			cout << " | \t  " << individuos[cualIndividuo]->mostrarNombre() << "\t " << endl;   

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









