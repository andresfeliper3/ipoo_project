/*
  Archivo: Jugador.h
  Autor: Andrés Rincón
         Jose David Hernández
         Diego Ledesma
  Fecha creación: 2020-03-30
  Fecha última modificación: 2020-03-30
*/

#ifndef JUGADOR__HH
#define JUGADOR__HH

#include "Individuo.h"
#include "Lugar.h"


/*
  Clase: Jugador
  Atributos: Vector de punteros que apuntan a Lugar.
            Vector de parejas que contienen un vector a Individuo y una letraParaMover.
  Funcionalidades:
    - Puede crear individuos.
    - Puede leer el teclado.
    - Puede mover a un individuo hacia su lugar vecino.
    - Puede mostrar el estado del juego en la pantalla.

  Relaciones: Conoce a Individuo, conoce a Lugar.


*/
class Jugador
{
  Protected:
    vector <Lugar*> lugares; //Vector con todos los lugares existentes.
    vector <pair <Individuo*, string letraParaMover>> individuos; //Vector de parejas con individuos asociados a su letraParaMover.

  Public:
    //Constructor.
    Jugador();

    //Destructor.
    ~Jugador();

    //Crea un objeto de la clase Individuo y le asocia una letraParaMover.
    crearIndividuo(string nombre, string letraParaMover);

    //Lee el teclado para recibir las órdenes del usuario.
    virtual string leerTeclado();

    /*Quita un individuo de un Lugar y lo pone en su Lugar vecino,
    o mueve a la Barca de un lado a otro del río, según la letra que reciba. */
    void mover(string tecla);

    //Muestra el estado del juego en pantalla.
    void estado();
};
#else
class Jugador;
#endif
