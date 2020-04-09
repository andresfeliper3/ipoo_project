/*
  Archivo: Jugador.h
  Autor: AndrÃ©s RincÃ³n "andres.rincon.lopez@correounivalle.edu.co"
  		   José David Barona Hernández "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creaciÃ³n: 2020-03-30
  Fecha Ãºltima modificaciÃ³n: 2020-04-03
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
    - Puede mover un individuo al lugar vecino a su lugar actual. 
	- Puede mover la barca de una orilla a otra del río.
    - Puede jugar: comparar cada letra de cada individuo con la letra que recibió del usuario para mover al individuo correspondiente.
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
    virtual void crearIndividuo(string nombre, string letraParaMover);
    
    //Pone un lugar en el vector de punteros a lugar.
    virtual void conocerLugar (Lugar* nuevoLugar);

    /*Lee el teclado para recibir las �rdenes del usuario y llama al m�todo this->jugar();*/
    virtual void leerTeclado();
    
    /*Mueve a un individuo del lugar donde est�, al lugar vecino*/ 
	virtual void moverIndividuo(Individuo*);

	/*o mueve	a la barca de una orilla a la otra del r�o*/
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
