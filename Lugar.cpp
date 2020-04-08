/*
  Archivo: Lugar.cpp
  Autores: Andrés Rincón "andres.rincon.lopez@correounivalle.edu.co"
  		   Jos� David Barona Hern�ndez "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creación: 2020-abril-08
  Fecha última modificación: 2020-abril-08
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

//Revisa si el jugador ha ganado o perdido la partida
void Lugar::revisarPartida()
{
 /*Realizar un ciclo que busque por todos los individuos del vector.
 Cada individuo debe ver si se puede comer a los demás.
 */
}

//Anuncia la victoria
string Lugar::victoria()
{
    return "¡Has ganado!";
}
//Anuncia la derrota
string Lugar::derrota()
{
    return "¡Has perdido!";
}
