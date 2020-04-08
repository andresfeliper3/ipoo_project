/*
  Archivo: Individuo.h
  Autores: Andrés Rincón "andres.rincon.lopez@correounivalle.edu.co"
  		   Jos� David Barona Hern�ndez "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creación: 2020-03-30
  Fecha última modificación: 2020-03-30
*/
#ifndef LUGAR_HH
#define LUGAR_HH

#include <vector>
#include "Individuo.h"
using namespace std;

/*
Nombre: Lugar
Posee un vector de individuos
Relaciones: Conoce a Lugar.
*/
class Lugar 
{
    protected:
        vector <Individuo *> individuosPresentes; //Vector de individuos presentes en el lugar
        Lugar *lugarVecino; //Apunta al lugar vecino
    
    public:
    //Constructor
    Lugar(Lugar *lugarVecino); //Al crear un lugar, se especifica cuál es el vecino inicial

    //Destructor
    virtual ~Lugar();

    //Agrega un individuo al vector de individuos
    virtual void agregarIndividuo(Individuo *individuo);

    //Quita un individuo del vector de individuos
    virtual void quitarIndividuo(Individuo *individuo);

    //Quita el lugar vecino debido al movimiento
    virtual void quitarLugarVecino();

    //Pone un lugar vecino debido al movimiento
    virtual void agregarLugarVecino(Lugar *nuevoLugarVecino);

    //Pregunta si un individuo está presente en este lugar o no. Si está, retorna su posición, si no retorna -1
    virtual int individuoPresente(Individuo *individuo);

    //Hace que un individuo se mueva de este lugar, al lugar vecino.
    virtual bool moverIndividuo(Individuo *individuo);

    //Revisa si se ganó o se perdio la partida
    virtual void revisarPartida();

    //Anuncia la victoria del jugador
    virtual string victoria();

    //Anuncia la derrota del jugador
    virtual string derrota();
};
#else
class Lugar;
#endif
