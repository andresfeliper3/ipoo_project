/*
  Archivo: Jugador.h
  Autor: AndrÃƒÂ©s RincÃƒÂ³n "andres.rincon.lopez@correounivalle.edu.co"
  		   JosÃ© David Barona HernÃ¡ndez "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creaciÃƒÂ³n: 2020-03-30
  Fecha ÃƒÂºltima modificaciÃƒÂ³n: 2020-04-03
*/

#ifndef JUGADOR__HH
#define JUGADOR__HH

#include "Individuo.h"
#include "Lugar.h"


/*
  Clase: Jugador
  Atributos: Vector de punteros que apuntan a Lugar.
            Vector de punteros que contiene los individuos.
            variable que guarda la letra que recibiÃ¯Â¿Â½.
            Variable que indica si la partida sigue en curso.
  Funcionalidades:
    - Puede crear individuos.
    - Puede conocer un nuevo lugar y lo agrega a su vector de punteors a Lugar. La barca siempre debe quedar en la última posiciÃ³n (PosiciÃ³n 2).
    - Puede leer el teclado.
    - Puede mover un individuo al lugar vecino a su lugar actual. 
	- Puede mover la barca de una orilla a otra del río, y al mismo tiempo 
		revisar si ya se ganó o perdió la partida.
    - Puede jugar: comparar cada letra de cada individuo con la letra que recibiÃ³ del usuario para mover al individuo correspondiente.
    - Puede mostrar el estado del juego en la pantalla.
  Relaciones: Conoce a Individuo, conoce a Lugar.
*/
class Jugador
{
  protected:
    vector <Lugar*> lugares; /*Vector con todos los lugares existentes, éstos deben ponerse en el siguiente orden: 
    							Orilla izquierda, barca, orilla derecha.*/
    vector <Individuo*> individuos; //Vector de punteros a individuo.
	string tecla;
	bool partidaEnCurso; //Mientras este booleano esté en true, la partida seguirá su curso.

  public:
    //Constructor.
    Jugador();

    //Destructor.
    ~Jugador();

    //Crea un objeto de la clase Individuo y le asocia una letraParaMover.
    virtual void crearIndividuo(string nombre, string letraParaMover);
    
    //Pone un lugar en el vector de punteros a lugar.
    virtual void conocerLugar (Lugar* nuevoLugar);

    /*Lee el teclado para recibir las órdenes del usuario y llama al método this->jugar();*/
    virtual void leerTeclado();
    
    /*Mueve a un individuo del lugar donde está, al lugar vecino*/ 
	virtual void moverIndividuo(Individuo*);

	/*o mueve	a la barca de una orilla a la otra del río y revisa si ya se ganó o perdió la partida.*/
	virtual void moverBarca();

    /*Compara la letra recibida de leerTeclado con las letras correspondientes a cada individuo y a la barca y al encontrar una 
	coincidencia, hace que se se mueva a su lugar vecino. */
    virtual void jugar (string tecla);

    //Muestra el estado del juego en pantalla.
    void estado();
};
#else
class Jugador;
#endif
