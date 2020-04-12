/*
  Archivo: Lugar.cpp
  Autores: Andrés Rincón "andres.rincon.lopez@correounivalle.edu.co"
  		   Jos� David Barona Hern�ndez "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creación: 2020-abril-08
  Fecha última modificación: 2020-abril-12
*/

#include "Lugar.h"

//Constructor
Lugar::Lugar(string nombre, Lugar *lugarVecino) : nombre(nombre), lugarVecino(lugarVecino)
{

}

//Destructor
Lugar::~Lugar()
{

}

//Retornar nombre del Lugar
string Lugar::mostrarNombre()
{
    return nombre;
}
//Agrega un individuo al vector de individuos, si ya no está presente
void Lugar::agregarIndividuo(Individuo *individuo)
{
    if(individuoPresente(individuo) == -1) //Si el individuo no está presente
    {
        individuosPresentes.push_back(individuo);
    }
}

//DUDA, SI USAR ERASE
//Quita un individuo del vector de individuo, si está presente
void Lugar::quitarIndividuo(Individuo *individuo)
{
    if(individuoPresente(individuo) != -1)
    {
        individuosPresentes.erase(individuosPresentes.begin()+individuoPresente(individuo)); 
    }
}

 //Retorna la cantidad de individuos presentes
int Lugar::cantidadDeIndividuos()
{
    return individuosPresentes.size();
}

//Retorna la posición si el individuo ingresado está presente en el vector de individuos de la parte privada, retorna -1 en caso en contrario
int Lugar::individuoPresente(Individuo *individuo)
{
    for(int cualIndividuo=0; cualIndividuo < individuosPresentes.size(); cualIndividuo++)
    {
        if(individuosPresentes[cualIndividuo] == individuo) 
        {
            
            return cualIndividuo;
        }
    }
    return -1;
}

//Hace que un individuo se mueva de este lugar al lugar vecino. Retorna true si logra hacerlo, false en caso contrario
bool Lugar::moverIndividuo(Individuo *individuo)
{
    //AGREGAR DESPUÉS QUE SÓLO SI EL ROBOT ESTÁ PRESENTE, SE PUEDE MOVER UN INDIVIDUO
    if(individuoPresente(individuo) != -1) //Si el individuo está presente
    {
        quitarIndividuo(individuo);
        lugarVecino->agregarIndividuo(individuo);
        return true;
    }
    return false; 
}

//Revisa si el jugador pierde cuando la barca se aleja de una orilla. Retorna true si pierde, y false si sigue jugando.
bool Lugar::revisarSiPierde()
{
 /*Realizar un ciclo que busque por todos los individuos del vector.
 Cada individuo debe ver si se puede comer a los demás.
 */
    //AUMENTAR LA CONDICIÓN, PARA QUE SEA CUANDO EL ROBOT NO ESTÉ PRESENTE
    for(int cualPredador = 0; cualPredador < individuosPresentes.size(); cualPredador++)
    {
        for(int cualPresa = 0; cualPresa < individuosPresentes.size(); cualPresa++)
        {
            if(individuosPresentes[cualPredador]->puedeComer(individuosPresentes[cualPresa]))
            {
                return true; 
            }
        }
    }
    return false;
}


