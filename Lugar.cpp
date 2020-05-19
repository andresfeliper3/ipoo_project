/*
  Archivo: Lugar.cpp
  Autores: Andrés Rincón "andres.rincon.lopez@correounivalle.edu.co"
  		   Jos� David Barona Hern�ndez "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creación: 2020-abril-08
  Fecha última modificación: 2020-abril-12
*/

#include "Lugar.h"
#include <iostream>

//Constructor
Lugar::Lugar(string nombre, Lugar *lugarVecino, string letraAsociada) : nombre(nombre), lugarVecino(lugarVecino), letraAsociada(letraAsociada)
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


//Quita un individuo del vector de individuo, si está presente
void Lugar::quitarIndividuo(Individuo *individuo)
{
    if(individuoPresente(individuo) >= 0) //Si el individuo está presente
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
    for(int cualIndividuo=0; cualIndividuo < this->cantidadDeIndividuos(); cualIndividuo++)
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
    if(individuoPresente(individuo) >=0  && tieneVecino()) //Si el individuo está presente. Si el robot está presente fue quitado para la jugabilidad
    {
        //cerr << "4.2 El individuo está presente en " << this-> mostrarNombre() << " y va para " << lugarVecino->mostrarNombre() <<endl;
        lugarVecino->agregarIndividuo(individuo); 
        //cerr << "4.3 El individuo ha sido agregado al lugar vecino, que es " << lugarVecino->mostrarNombre() << endl;
        this->quitarIndividuo(individuo);     
        //cerr << "4.4 El individuo fue quitado del vector" <<endl;
        return true;
    }   
    return false; 
}

//Retorna true si el lugar tiene un lugar vecino, false en caso contrario
bool Lugar::tieneVecino()
{
    if(lugarVecino) 
        return true;
    return false;
}


//Retorna true si hay un robot presente en el lugar, false en caso contrario
bool Lugar::robotPresente()
{
    //cerr << "Entró a robotPresente" <<endl;
    for(int cualIndividuo = 0; cualIndividuo < cantidadDeIndividuos(); cualIndividuo++)
    {
        if(individuosPresentes[cualIndividuo]->esUnRobot())
        {
             return true;
        }     
    }      
    return false;
}

//Revisa si el jugador pierde cuando la barca se aleja de una orilla. Retorna true si pierde, y false si sigue jugando.
bool Lugar::revisarSiPierde()
{
    //cerr << "Entró al revisarSiPierde de " << this->mostrarNombre() << endl;
 /*Realizar un ciclo que busque por todos los individuos del vector.
 Cada individuo debe ver si se puede comer a los demás.
 */
    if(not robotPresente()) //Si el robot no está presente 
    {
        //cerr << "Lugar: robot no está presente" <<endl;
        for(int cualPredador = 0; cualPredador < cantidadDeIndividuos(); cualPredador++)
        {
            for(int cualPresa = 0; cualPresa < cantidadDeIndividuos(); cualPresa++)
            {
                if(individuosPresentes[cualPredador]->puedeComer(individuosPresentes[cualPresa]))
                {
                    return true;      
                }
            }
        }
    }       
    return false;
}





