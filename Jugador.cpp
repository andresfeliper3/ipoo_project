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
Jugador::Jugador(bool partidaEnCurso, Barca *barca) : partidaEnCurso(partidaEnCurso), barca(barca)
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
Individuo* Jugador::crearIndividuo(string nombre, string letraParaMover, bool esRobot)
{
	Individuo* nuevoIndividuo = new Individuo(nombre, letraParaMover, esRobot);
	individuos.push_back(nuevoIndividuo); 
  	lugares[0]->agregarIndividuo(nuevoIndividuo); //Coloca el individuo en la orilla izquierda
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

//Agrega una presa a un predador correspondiente
void Jugador::agregarPresa(Individuo* predador, Individuo* presa)
{
  predador->agregarPresa(presa);
}

//Recibe la tecla oprimida por el usuario y la guarda en la parte privada
void Jugador::leerTeclado()
{
	getline(cin, this->tecla);
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


void Jugador::revisarPartida()
{
	cerr << "Entró a revisarPartida de Jugador" <<endl; 
	//lugares[1]->cambiarDeVecino(); //Cambia el lugar vecino de la barca	
	if (lugares[0]->revisarSiPierde() or lugares[2]->revisarSiPierde())
	{
    //Perdiste
		partidaEnCurso = false;
		cerr << "Perdiste" <<endl; 
   // perdiste();
	} 
	else if (lugares[2]->cantidadDeIndividuos() == individuos.size())
	{
    //Ganaste
		partidaEnCurso = false;
		cerr << "Ganaste" <<endl;
    //ganaste();
	}
	partidaEnCurso = true;
	cerr << "Pronto a salir de revisarPartida de Jugador con partida en curso " << partidaEnCurso << endl;  
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

/*Compara la letra recibida de leerTeclado con las letras correspondientes a cada individuo y a la barca, y al encontrar una coincidencia, hace que se se mueva a su lugar vecino. */
void Jugador::jugar()
{
	if (partidaEnCurso) //Mientras la partida esté en curso
	{
		cerr << "2 entra en Jugar " << tecla << " " << this->barca->mostrarLetraAsociada() <<  endl; 

		//Movimiento de la barca
		if ("B" == tecla ) //Si el usuario ha marcado la tecla de la barca, la barca se mueve
		{
			cerr << "2.1 " << barca->mostrarLetraAsociada() << endl; 
			if(barca->robotPresente()) //Si el robot está en la barca
			{
				cerr << "El robot está presente en la barca" << endl;
				cerr << "3 Jugar activa el movimiento de la barca " << barca->mostrarNombre() << endl;
				barca->movimientoDeBarca(); //Movimiento de la barca
					
			}			
		}
		//Movimiento de los individuos
		else
		{
			for (int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++ )
			{
				if (individuos[cualIndividuo]->mostrarLetraAsociada() == tecla)
				{
					cerr << "3 hay un individuo con la letra asociada " << individuos[cualIndividuo]->mostrarLetraAsociada() <<endl;
					if(this->moverIndividuo(individuos[cualIndividuo]))
					{
						cerr << "4 se ejecutó la función de moverIndividuo de Jugador para " << individuos[cualIndividuo]->mostrarNombre() <<endl;
						break;
					}		
				}
			}	
		//	cout << "Presiona una tecla válida" <<endl; //Cambiar por throw
		}	
				
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









