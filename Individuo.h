/*
  Archivo: Individuo.h
  Autores: Andrés Rincón "andres.rincon.lopez@correounivalle.edu.co"
  		   Jos� David Barona Hern�ndez "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creación: 2020-03-30
  Fecha última modificación: 2020-03-30
*/

#ifndef INDIVIDUO_HH
#define INDIVIDUO_HH

#include <vector>
#include <string>
using namespace std;

/*
  Clase: Individuo
  Posee un nombre y una letra asociada al movimiento
  Relaciones: Conoce a los individuos que se puede comer
*/
class Individuo 
{
    protected:
        string nombre;
        string letraParaMover; //Letra asociada al movimiento
        vector <Individuo *> puedeComer; //Bichos que puede comer

    public:
        //Constructor
        Individuo(string nombre, string letraParaMover);

        //Destructor
        virtual ~Individuo();

        //Agrega posibles presas para el Individuo, a�adiendo punteros al vector puedeComer
        virtual void agregarPresa(Individuo *presa);  

        //Retorna la letra asociada al individuo
        virtual string mostrarLetraAsociada();

        //A�adir funci�n "crearBichos" 
};
#else
class Individuo;
#endif
