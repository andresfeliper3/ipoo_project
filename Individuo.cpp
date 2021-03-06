/*
  Archivo: Individuo.cpp
  Autores: Andrés Rincón "andres.rincon.lopez@correounivalle.edu.co"
  		   Jose David Barona Hernandez "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creación: 2020-abril-07
  Fecha última modificación: 2020-abril-12
*/
#include "Individuo.h"

//Constructor
Individuo::Individuo(string nombre, string letraParaMover, bool esRobot) : nombre(nombre), letraAsociada(letraParaMover), esRobot(esRobot)
{
    
}

//Destructor
Individuo::~Individuo()
{

}

//Retornar nombre del individuo
string Individuo::mostrarNombre()
{
  return nombre;
}

//Agrega posibles presas para el Individuo, añadiendo punteros al vector puedeComer
void Individuo::agregarPresa(Individuo *presa)
{
  if(this != presa) //Evita que el individuo se pueda comer a sí mismo
  {
    individuosQuePuedeComer.push_back(presa);
  }
    
}

//Retorna la letra asociada al individuo
string Individuo::mostrarLetraAsociada()
{
  return this->letraAsociada;
}

//Retorna true si es un robot y false en caso contrario
bool Individuo::esUnRobot()
{
  return this->esRobot;
}

//Retorna true si puede comerse a otro individuo, es decir, si está en el vector de individuos que puede comer. Retorna false en caso contrario
bool Individuo::puedeComer(Individuo *posiblePresa)
{
  //Retorna false, pues un individuo no puede comerse a sí mismo
  if(this == posiblePresa)
    return false;

  //Revisa los individuos que puede comer
  for(int cualPresa = 0; cualPresa < individuosQuePuedeComer.size(); cualPresa++)
  {
    if(individuosQuePuedeComer[cualPresa] == posiblePresa)
    {
      return true;
    }
  }
  return false;
}

