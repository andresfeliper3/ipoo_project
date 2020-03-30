/*
  Archivo: Individuo.h
  Autor: Andrés Rincón
  Fecha creación: 2020-03-30
  Fecha última modificación: 2020-03-30
*/

#ifndef INDIVIDUO_HH
#define INDIVIDUO_HH

#include <vector>
#include <string>
using namespace std;

class Individuo 
{
    private:
        string nombre;
        string letraParaMover; //Letra asociada al movimiento
        vector <Individuo *> puedeComer; //Bichos que puede comer

    public:
        //Constructor
        Individuo(string nombre, string letraParaMover);

        //Agrega posibles presas para el Individuo, añadiendo punteros al vector puedeComer
        virtual void agregarPresa(Individuo *);  

        //Añadir función "crearBichos" 
};
#else
class Individuo;
#endif