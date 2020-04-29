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
        string letraAsociada; //Letra asociada al movimiento
        vector <Individuo *> individuosQuePuedeComer; //Bichos que puede comer

    public:
        //Constructor
        Individuo(string nombre, string letraParaMover);

        //Destructor
        virtual ~Individuo();

        //Retorna el nombre del individuo
        virtual string mostrarNombre();

        //Agrega posibles presas para el Individuo, a�adiendo punteros al vector puedeComer
        virtual void agregarPresa(Individuo *presa);  

        //Retorna la letra asociada al individuo
        virtual string mostrarLetraAsociada();

        //Revisa si puede comerse a otro individuo, es decir, si está en el vector de individuos que puede comer
        virtual bool puedeComer(Individuo *posiblePresa);

};
#else
class Individuo;
#endif
