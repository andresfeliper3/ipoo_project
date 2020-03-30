/*
  Archivo: Lugar.h
  Autor: Andrés Rincón
  Fecha creación: 2020-03-30
  Fecha última modificación: 2020-03-30
*/

#ifndef BARCA_HH
#define BARCA_HH

#include <vector>
#include "Lugar.h"
using namespace std;

/*
Nombre: Barca
Es parecido a un lugar
Relaciones: Conoce a Orilla.
*/
class Barca : public Lugar 
{
    protected:
    
    public:
    //Constructor
    Barca(Lugar *lugarVecino); //Al crear un lugar, se especifica cuál es el vecino inicial

    //Destructor
    virtual ~Barca();

    //Cambia de orilla (cambia de vecino)
    virtual void moverseDeOrilla();


};
#else
class Barca;
#endif
