/*
  Archivo: Barca.h
  Autores: Andrés Rincón "andres.rincon.lopez@correounivalle.edu.co"
  		   Jos� David Barona Hern�ndez "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creación: 2020-03-30
  Fecha última modificación: 2020-03-30
*/

#ifndef BARCA_HH
#define BARCA_HH

#include "Lugar.h"

/*
Nombre: Barca
Es parecido a un lugar
Relaciones: Conoce a Orilla.
*/
class Barca : public Lugar 
{
    protected:
    
    Lugar *LugarVecino;
    vector <Lugar*> orillas;

    string nombreLugar;
    string letraAsociada;
    
    public:
    //Constructor
    Barca(string nombreLugar, Lugar *lugarVecino, string letraAsociada); //Al crear un lugar, se especifica cuál es el vecino inicial

    //Destructor
    virtual ~Barca();

    //Cambia de orilla (cambia de vecino)
    virtual void cambiarDeVecino(Lugar *nuevoLugarVecino);
    
    //Recibe un individuo
    virtual void agregarIndividuo(Individuo *recibirIndividuo);

    //Retorna la letra asociada
    virtual string mostrarLetraAsociada();

    //Agrega las orillas a conocer en el vector de orillas
    virtual void conocerOrillas(Lugar *orilla);


};
#else
class Barca;
#endif
