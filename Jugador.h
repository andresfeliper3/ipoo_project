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
            Vector de punteros que contiene los individuos.
            Puntero que apunta a la barca.
            variable que guarda la letra que recibi�.
  Funcionalidades:
    - Puede crear individuos.
    - Puede conocer un nuevo lugar y lo agrega a su vector de punteors a Lugar. La barca siempre debe quedar en la �ltima posici�n (Posici�n 2).
    - Puede leer el teclado.
    - Puede jugar: comparar cada letra de cada individuo con la letra que recibi� del usuario para mover al individuo correspondiente.
    - Puede mostrar el estado del juego en la pantalla.

  Relaciones: Conoce a Individuo, conoce a Lugar.


*/
class Jugador
{
  protected:
    vector <Lugar*> lugares; //Vector con todos los lugares existentes. La barca siempre debe estar en la posici�n 2 (La �ltima).
    vector <Individuo*> individuos; //Vector de punteros a individuo.
	string tecla;

  public:
    //Constructor.
    Jugador();

    //Destructor.
    ~Jugador();

    //Crea un objeto de la clase Individuo y le asocia una letraParaMover.
    virtual crearIndividuo(string nombre, string letraParaMover);
    
    //Pone un lugar en el vector de punteros a lugar.
    virtual conocerLugar (Lugar* nuevoLugar);

    /*Lee el teclado para recibir las órdenes del usuario y avisa a los individuos y a la barca la letra recibida
	  llamando al m�todo decirTecla.*/
    virtual string leerTeclado();

    /*Compara la letra recibida de leerTeclado con las letras correspondientes a cada individuo y a la barca y al encontrar una coincidencia, 
	hace que se se mueva a su lugar vecino. */
    virtual void jugar (string tecla);

    //Muestra el estado del juego en pantalla.
    void estado();
};
#else
class Jugador;
#endif
