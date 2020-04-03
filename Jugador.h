/*
  Archivo: Jugador.h
  Autor: AndrÃ©s RincÃ³n
         Jose David HernÃ¡ndez
         Diego Ledesma
  Fecha creaciÃ³n: 2020-03-30
  Fecha Ãºltima modificaciÃ³n: 2020-03-30
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
            variable que guarda la letra que recibiï¿½.
  Funcionalidades:
    - Puede crear individuos.
    - Puede conocer un nuevo lugar y lo agrega a su vector de punteors a Lugar. La barca siempre debe quedar en la última posición (Posición 2).
    - Puede leer el teclado.
    - Puede jugar: comparar cada letra de cada individuo con la letra que recibió del usuario para mover al individuo correspondiente.
    - Puede mostrar el estado del juego en la pantalla.

  Relaciones: Conoce a Individuo, conoce a Lugar.


*/
class Jugador
{
  protected:
    vector <Lugar*> lugares; //Vector con todos los lugares existentes. La barca siempre debe estar en la posición 2 (La última).
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

    /*Lee el teclado para recibir las Ã³rdenes del usuario y avisa a los individuos y a la barca la letra recibida
	  llamando al mï¿½todo decirTecla.*/
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
