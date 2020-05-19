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
#include <cctype>
#include <algorithm>
#include <cmath>

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

    if (lugares.size() == 2)
    { 
      lugares[1]->conocerOrillas(lugares[0]);
      lugares[1]->conocerOrillas(lugares[2]);
    }
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
}

//Mueve un individuo al lugar vecino del lugar que esté.
bool Jugador::moverIndividuo(Individuo* individuo)
{
	for (int cualLugar = 0; cualLugar < lugares.size(); cualLugar++)
	{
		if(lugares[cualLugar]->moverIndividuo(individuo))  
			return true;	
	}
	return false;
}

//Jugador debe encargarse de que Barca conozca a las dos orillas.


void Jugador::revisarPartida()
{	
	if (lugares[0]->revisarSiPierde() or lugares[2]->revisarSiPierde() or lugares[1]->revisarSiPierde())
	{
    //Perdiste
		partidaEnCurso = false;
		cerr << endl << 
"´´´´´´´´´´´´´´´´´´´´´$$$$$$$$$$$$$$$$´´´´´´´´´´´´´´´´´´´´´´"<< endl <<
"´´´´´´´´´´´´´´´´´$$$$$$´´´´´´´´´´´´´$$$$$$´´´´´´´´´´´´´´´´´"<< endl <<
"´´´´´´´´´´´´´´$$$$´´´´´´´´´´´´´´´´´´´´´´´$$$$´´´´´´´´´´´´´´"<< endl <<
"´´´´´´´´´´´´´$$$´´´´´´´´´´´´´´´´´´´´´´´´´´´$$$´´´´´´´´´´´´´"<< endl <<
"´´´´´´´´´´´´$$´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´$$´´´´´´´´´´´´"<< endl <<
"´´´´´´´´´´´$$´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´$$´´´´´´´´´´´"<< endl <<
"´´´´´´´´´´$$´´´´´´´´´´P E R D I S T E´´´´´´´´´$$´´´´´´´´´´´"<< endl <<
"´´´´´´´´´´$$´$$´´´´´´´´´´´´´´´´´´´´´´´´´´´´´$$´$$´´´´´´´´´´"<< endl <<
"´´´´´´´´´´$$´$$´´´´´´´´´´´´´´´´´´´´´´´´´´´´´$$´$$´´´´´´´´´´"<< endl <<
"´´´´´´´´´´$$´$$´´´´´´´´´´´´´´´´´´´´´´´´´´´´´$$´$$´´´´´´´´´´"<< endl <<
"´´´´´´´´´´$$´´$$´´´´´´´´´´´´´´´´´´´´´´´´´´´$$´´$$´´´´´´´´´´"<< endl <<
"´´´´´´´´´´$$´´$$´´´´´´´´´´´´´´´´´´´´´´´´´´´$$´´$$´´´´´´´´´´"<< endl <<
"´´´´´´´´´´´$$´$$´´´$$$$$$$$´´´´´´$$$$$$$´´´$$´$$´´´´´´´´´´´"<< endl <<
"´´´´´´´´´´´´$$$$´$$$$$$$$$$´´´´´$$$$$$$$$$´$$$$¶´´´´´´´´´´´"<< endl <<
"´´´´´´´´´´´´´$$$´$$$$$$$$$$´´´´´$$$$$$$$$$´$$$´´´´´´´´´´´´´"<< endl <<
"´´´´$$$´´´´´´´$$´´$$$$$$$$´´´´´´´$$$$$$$$$´$$´´´´´´´´$$$$´´"<< endl <<
"´´´$$$$$´´´´´$$´´´$$$$$$$´´´$´$´´´$$$$$$$´´´$$´´´´´$$$$$$´´"<< endl <<
"´´$$´´´$$´´´´$$´´´´´$$$´´´´$$$$$´´´´$$$´´´´´$$´´´´$$´´´$$´´"<< endl <<
"´$$$´´´´$$$$´´$$´´´´´´´´´´$$$´$$$´´´´´´´´´´$$´´$$$$´´´´$$$´"<< endl <<
"$$´´´´´´´´´$$$$$$$$´´´´´´´$$$´$$$´´´´´´´$$$$$$$$$´´´´´´´´$$"<< endl <<
"$$$$$$$$$´´´´´$$$$$$$$´´´´$$$´$$$´´´´$$$$$$$$´´´´´´$$$$$$$$"<< endl <<
"´´$$$$´$$$$$´´´´´´$$$$$´´´´´´´´´´´´$$$´$$´´´´´$$$$$$´$$$´´´"<< endl <<
"´´´´´´´´´´$$$$$$´´$$$´$$´´´´´´´´´´´$$´$$$´´$$$$$$´´´´´´´´´´"<< endl <<
"´´´´´´´´´´´´´´$$$$$$´$´´$$$$$$$$$$$´$$´$$$$$$´´´´´´´´´´´´´´"<< endl <<
"´´´´´´´´´´´´´´´´´´$$´$´$$´$$´$´$$$$$$$´$$´´´´´´´´´´´´´´´´´´"<< endl <<
"´´´´´´´´´´´´´´´´$$$$´$$´$´$$´$´$$´$´$$´$$$$$´´´´´´´´´´´´´´´"<< endl <<
"´´´´´´´´´´´´$$$$$´$$´´´$$$$$$$$$$$$$´´´$$´$$$$$´´´´´´´´´´´´"<< endl <<
"´´´´$$$$$$$$$$´´´´´$$´´´´´´´´´´´´´´´´´$$´´´´´´$$$$$$$$$´´´´"<< endl <<
"´´´$$´´´´´´´´´´´$$$$$$$´´´´´´´´´´´´´$$$$$$$$´´´´´´´´´´$$´´´"<< endl <<
"´´´´$$$´´´´´$$$$$´´´´´$$$$$$$$$$$$$$$´´´´´$$$$$´´´´´$$$´´´´"<< endl <<
"´´´´´´$$´´´$$$´´´´´´´´´´´$$$$$$$$$´´´´´´´´´´´$$$´´´$$´´´´´´"<< endl <<
"´´´´´´$$´´$$´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´$$´´$$´´´´´´"<< endl <<
"´´´´´´´$$$$´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´$$$´´´´´´´´"<<endl <<endl; 
	} 
	else if (lugares[2]->cantidadDeIndividuos() == individuos.size())
	{
    //Ganaste
		partidaEnCurso = false;
		cerr << endl << 
"||||$$$$||||||||||||||||$$$$$$$$$||||||||||"<< endl <<
"|||$-----$||||||||||$$$--------$$$|||||||||"<< endl <<
"|||$------$|||||||$$$-------------$$$||||||"<< endl <<
"||||$------$||||$$-------------------$$||||"<< endl <<
"|||||$-----$|||$$-----$$------$$-----$$$|||"<< endl <<
"||||||$----$||$------$$$$----$$$$------$$||"<< endl <<
"||||$$$$$$$$$$$$$----------------------$$||"<< endl <<
"||||$------------$---------$-----------$$||"<< endl <<
"||$$-------------$---$$----------$$----$$||"<< endl <<
"|$$---$$$$$$$$$$$-----$$--------$$-----$$||"<< endl <<
"|$---------------$------$$$$$$$$-------$$||"<< endl <<
"|$$--------------$--------------------$$|||"<< endl <<
"||$---$$$$$$$$$$$----G A N A S T E----$$|||"<< endl <<
"||$$----------$$$$-----------------$|||||||"<< endl <<
"|||$$$$$$$$$$$$|||$$$$$$$$$$$$$$$$$||||||||"<< endl << 
"|||||||||||||||||||||||||||||||||||||||||||"<< endl << endl;
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

//Compara la letra recibida de leerTeclado con las letras correspondientes a cada individuo y a la barca, y al encontrar una coincidencia, hace que se se mueva a su lugar vecino. */
void Jugador::jugar()
{
	if (partidaEnCurso) //Mientras la partida esté en curso
	{
    string j = barca->mostrarLetraAsociada();
    transform(j.begin(), j.end(),j.begin(),[](unsigned char c) 
    { 
      return tolower(c); //transformar una letra mayúscula a minúscula
    }); 
		
    if((barca->mostrarLetraAsociada())== tecla || tecla == j) //Si el usuario ha marcado la tecla de la barca, la barca se mueve
		{
			if(barca->robotPresente()) //Si el robot está en la barca y hay menos de 3 individuos
			{
				barca->movimientoDeBarca(); //Movimiento de la barca			
			}		
		}
		//Movimiento de los individuos
		else
		{
			for (int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++ )
			{
        string k = individuos[cualIndividuo]->mostrarLetraAsociada();

        transform(k.begin(), k.end(),k.begin(),[](unsigned char c)
        { 
          return tolower(c); //transformar una letra mayúscula a minúscula
        });

				if (individuos[cualIndividuo]->mostrarLetraAsociada() == tecla || tecla == k)
				{
					if(this->moverIndividuo(individuos[cualIndividuo]))
					{
						break;
					}		
				}
			}	
		}	
				
	}
}

string Jugador::diseño(string palabra, int dondeInicia)
{
  string palabraFinal;
  do
  {
    palabraFinal += " ";

  } while(palabraFinal.size() < dondeInicia);
  
  palabraFinal += palabra;
  return palabraFinal;
}    

string Jugador::centrarPalabra(string palabra)
{
  int tamanio = palabra.size();
  int dondeInicia = 9 - (tamanio / 2) - 1;
  
  string cadenaFinal = "|" + diseño(palabra, dondeInicia);
  
  for (int ubicacion = cadenaFinal.size(); ubicacion < 18 ; ubicacion++ )
  {
    cadenaFinal += " ";
  }
return cadenaFinal;
}



void Jugador::estado()
{
  const int espaciado = lugares[0]->mostrarNombre().size();
  bool orillaIzquierdaTieneVecino = true;

  //Imprime los nombres de los lugares

  cout << centrarPalabra("ORILLA") << centrarPalabra("") << centrarPalabra("") << centrarPalabra("ORILLA")  << endl;

	for (int cualLugar = 0; cualLugar < lugares.size(); cualLugar++)
	{
		//Revisa si se está mirando la orilla derecha
		if(cualLugar == 2)
		{
			if(!lugares[cualLugar]->tieneVecino()) //Si la orilla derecha no tiene vecino
			{
				orillaIzquierdaTieneVecino = true;
				cout << centrarPalabra("");
			}
		}
		cout << centrarPalabra(lugares[cualLugar]->mostrarNombre()); //Imprime el nombre del lugar
		if(cualLugar == 0) //Revisa si se está mirando la orilla izquierda
		{
			if(!lugares[cualLugar]->tieneVecino()) //Si la orilla izquierda no tiene vecino
			{
				orillaIzquierdaTieneVecino = false;
				cout << centrarPalabra("");
			}
		}
	}
	cout << endl << endl; 

	//Imprime a los individuos por orden según el vector de individuos. 
	for (int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++)
	{
		if(lugares[0]->individuoPresente(individuos[cualIndividuo]) >= 0) //Si el individuo está en la orilla izquierda
		{
			cout << centrarPalabra(individuos[cualIndividuo]->mostrarNombre());		
			cout << centrarPalabra("") << centrarPalabra("") << centrarPalabra("") << endl;
		} 
		else if(lugares[1]->individuoPresente(individuos[cualIndividuo]) >= 0) //Si el individuo está en la barca
		{
			if(orillaIzquierdaTieneVecino) //Si la barca está al lado izquiedo
			{
				cout << centrarPalabra("");
				cout << centrarPalabra(individuos[cualIndividuo]->mostrarNombre());
				cout << centrarPalabra("") << centrarPalabra("") << endl;
			}
			else //Si la barca está al lado derecho
			{
				cout << centrarPalabra("") << centrarPalabra("");
				cout << centrarPalabra(individuos[cualIndividuo]->mostrarNombre());
				cout << centrarPalabra("") << endl;
			}
		}
		else if(lugares[2]->individuoPresente(individuos[cualIndividuo]) >= 0) //Si el individuo está en la orilla derecha
		{
			cout << centrarPalabra("") << centrarPalabra("") << centrarPalabra("");
			cout << centrarPalabra(individuos[cualIndividuo]->mostrarNombre()) << endl;   

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









