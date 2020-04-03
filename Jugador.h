/*
  Archivo: Jugador.h
  Autor: Andr√©s Rinc√≥n
         Jose David Hern√°ndez
         Diego Ledesma
  Fecha creaci√≥n: 2020-03-30
  Fecha √∫ltima modificaci√≥n: 2020-03-30
*/

#ifndef JUGADOR__HH
#define JUGADOR__HH

#include "Individuo.h"
#include "Lugar.h"


/*
  Clase: Jugador
  Atributos: Vector de punteros que apuntan a Lugar.
            Vector de punteros que contiene los individuos.
            Puntero que apunta a la barca.
            variable que guarda la letra que recibiÛ.
  Funcionalidades:
    - Puede crear individuos.
    - Puede leer el teclado.
    - Puede decirle a los individuos y a la barca la letra que recibiÛ.
    - Puede mostrar el estado del juego en la pantalla.

  Relaciones: Conoce a Individuo, conoce a Lugar.


*/
class Jugador
{
  Protected:
    vector <Lugar*> lugares; //Vector con todos los lugares existentes.
    vector <Individuo*> individuos; //Vector de punteros a individuo.
    Lugar* barcaPtr; //Puntero a la Barca.
	string tecla;
	
  Public:
    //Constructor.
    Jugador();

    //Destructor.
    ~Jugador();

    //Crea un objeto de la clase Individuo y le asocia una letraParaMover.
    crearIndividuo(string nombre, string letraParaMover);

    /*Lee el teclado para recibir las √≥rdenes del usuario y avisa a los individuos y a la barca la letra recibida
	  llamando al mÈtodo decirTecla.*/.
    virtual string leerTeclado();

    /*Le avisa a los individuos y a la barca la letra que recibiÛ del usuario. */
    virtual string decirTecla (string tecla);

    //Muestra el estado del juego en pantalla.
    void estado();
};
#else
class Jugador;
#endif
