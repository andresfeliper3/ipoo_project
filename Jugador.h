/*
  Archivo: Jugador.h
  Autor: AndrÃ©s RincÃ³n "andres.rincon.lopez@correounivalle.edu.co"
  		   José David Barona Hernández "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creaciÃ³n: 2020-03-30
<<<<<<< HEAD
  Fecha Ãºltima modificaciÃ³n: 2020-05-07
=======
  Fecha Ãºltima modificaciÃ³n: 2020-04-20
>>>>>>> 682690fb11dd7477341813e31d2ab9f8064a0d99
*/

#ifndef JUGADOR__HH
#define JUGADOR__HH

#include "Individuo.h"
#include "Orilla.h"
#include "Lugar.h"
#include "Barca.h"
#include <string>



/*
  Clase: Jugador
  Atributos: Vector de punteros que apuntan a Lugar.
            Vector de punteros que contiene los individuos.
            variable que guarda la letra que recibiï¿½.
            Variable que indica si la partida sigue en curso.
  Funcionalidades:
    - Puede crear individuos.
    - Puede conocer un nuevo lugar y lo agrega a su vector de punteors a Lugar. La barca siempre debe quedar en la �ltima posición (Posición 2).
    - Puede agregarle posibles presas a un individuo.
    - Puede leer el teclado.
    - Puede mover un individuo al lugar vecino a su lugar actual. 
	- Puede mover la barca de una orilla a otra del r�o, y al mismo tiempo 
		revisar si ya se gan� o perdi� la partida.
    - Puede jugar: comparar cada letra de cada individuo con la letra que recibió del usuario para mover al individuo correspondiente.
    - Puede mostrar el estado del juego en la pantalla.
  Relaciones: Conoce a Individuo, conoce a Lugar.
*/
class Jugador
{
  protected:
    vector <Lugar*> lugares; /*Vector con todos los lugares existentes, �stos deben ponerse en el siguiente orden: 
    							Orilla izquierda, barca, orilla derecha.*/
    vector <Individuo*> individuos; //Vector de punteros a individuo.
	  string tecla;
    Barca *barca;
	  bool partidaEnCurso; //Mientras este booleano est� en true, la partida seguir� su curso.

  public:
    //Constructor.
    Jugador(bool partidaEnCurso, Barca* barca);

    //Destructor.
    virtual ~Jugador();

    //Crea un objeto de la clase Individuo y le asocia una letraParaMover.
    virtual Individuo* crearIndividuo(string nombre, string letraParaMover, bool esRobot);
    
    //Pone un lugar en el vector de punteros a lugar.
    virtual void conocerLugar (Lugar* nuevoLugar);

    //Le agrega un individuo al predador a su vector de presas //POSIBLEMENTE NO NECESARIA
    virtual void agregarPresa(Individuo* predador, Individuo* presa);

    /*Lee el teclado para recibir las �rdenes del usuario y llama al m�todo this->jugar();*/
    virtual void leerTeclado();
    
    /*Mueve a un individuo del lugar donde est�, al lugar vecino. Retorna true si logra hacerlo, false en caso contrario.*/ 
	  virtual bool moverIndividuo(Individuo* individuo);

	  /* revisa si ya se gan� o perdi� la partida.*/
	  virtual void revisarPartida();

    //Mostrar tecla oprimida
    virtual string mostrarTecla();

    //Mostrar si la partida está en curso
    virtual bool mostrarSiPartidaEnCurso();

    /*Compara la letra recibida de leerTeclado con las letras correspondientes a cada individuo y a la barca y al encontrar una coincidencia, hace que se se mueva a su lugar vecino. */
    virtual void jugar();

    //Muestra el estado del juego en pantalla.
    virtual void estado();

    //Cuenta los espacios necesarios para que quede estético el estado del juego
    virtual string diseño(string palabra, int dondeInicia);

    //Se encarga de que las palabras aparezcan centradas en cada columna de la tabla.
    virtual string centrarPalabra(string palabra);


};
#else
class Jugador;
#endif
