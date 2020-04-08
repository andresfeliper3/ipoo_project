/*
  Archivo: Individuo.cpp
  Autores: Andrés Rincón "andres.rincon.lopez@correounivalle.edu.co"
  		   Jose David Barona Hernandez "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creación: 2020-abril-07
  Fecha última modificación: 2020-abril-07
*/
#include "Individuo.h"

//Constructor
Individuo::Individuo(string nombre, string letraParaMover) : nombre(nombre), letraParaMover(letraParaMover)
{
    
}

//Destructor
Individuo::~Individuo()
{

}

//Agrega posibles presas para el Individuo, añadiendo punteros al vector puedeComer
void Individuo::agregarPresa(Individuo *presa)
{
    individuosQuePuedeComer.push_back(presa);
}

//Retorna la letra asociada al individuo
string Individuo::mostrarLetraAsociada()
{
    return letraParaMover;
}