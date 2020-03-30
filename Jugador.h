/*
  Archivo: Jugador.h
  Autor: Andrés Rincón
  Fecha creación: 2020-03-30
  Fecha última modificación: 2020-03-30
*/

#ifndef JUGADOR__HH
#define JUGADOR__HH

#include "Individuo.h"
#include "Lugar.h"

class Jugador
{
  Protected:
    vector <Lugar*>;
    Vector < pair <Individuo*, string> >;

  Public:
    crearIndividuo(nombre, letraMover);




};
#else
class Jugador;
#endif
