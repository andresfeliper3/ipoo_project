/*
  Archivo: Individuo.h
  Autores: Andrés Rincón "andres.rincon.lopez@correounivalle.edu.co"
  		   Jos� David Barona Hern�ndez "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creación: 2020-03-30
  Fecha última modificación: 2020-03-30
*/

#ifndef ORILLA_HH
#define ORILLA_HH

#include <vector>
#include "Lugar.h"

using namespace std;

/*
Nombre: Orilla
Posee un vector de individuos
Relaciones: Conoce Individuos
*/
class Orilla : public Lugar 
{
    protected:
    
    Lugar *LugarVecino;
    
    public:
    //Constructor
    Orilla(Lugar *lugarVecino); //Al crear una Orilla, se especifica cuál es el vecino inicial

    //Destructor
    virtual ~Orilla();
	    
    //Suelta un individuo al lugar vecino
    virtual void soltarALugarVecino(Individuo *individuo);

    //Recibe un individuo del lugar vecino
    virtual void recibirDelLugarVecino(Individuo *individuo);
};
#else
class Orilla;
#endif
