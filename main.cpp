/*
  Archivo: Barca.cpp
  Autores: Andrés Rincón "andres.rincon.lopez@correounivalle.edu.co"
  		   José David Barona Hernández "jose.david.barona@correounivalle.edu.co"
  		   Diego Ledesema "diego.ledesma@correounivalle.edu.co"
  Fecha creación: 2020-03-30
  Fecha última modificación: 2020-03-30

  HISTORIA:

hay un robot que debe transportar un zorro, un conejo y una lechuga desde un lado del río 
hasta la otra orilla, usando una barca. En la barca solo cabe uno de los tres individuos,
además del robot. El problema es que si el robot deja solos al zorro y el conejo, 
el zorro se comerá el conejo. Y si deja solos al conejo y la lechuga, el conejo se comerá la lechuga.
El jugador debe controlar que órdenes dar, para lograr que el robot transporte los tres individuos a la otra orilla, sanos y salvos.

*/
#include <iostream>
#include "Jugador.h"

#include <vector>


using namespace std;

int main() 
{
  /*
    CREAR LA BARCA Y LAS ORILLAS
  */
  Orilla orillaIzquierda("IZQUIERDA",nullptr); //CREA ORILLA IZQ, VECINO NULO
  Barca barca("BARCA", &orillaIzquierda,"B"); //CREAR BARCA,VECINO INICIAL, LETRA ASOCIADA
  orillaIzquierda.cambiarDeVecino(&barca);

  Orilla orillaDerecha("DERECHA", nullptr); //CREAR ORILLA DER, VECINO NULO

  /***********************************************************************
  CREAR JUGADOR
  con los respectivos lugares creados anteriormente (Orilla izquierda, Barca, Orilla Derecha)
  El usuario va añadiendo los individuos que desee.

  PD: Por lo pronto hay mucho desorden, pero es fácil de reubicar para que quede bonito xd
  ***********************************************************************/
 //Creación de Jugador

  Jugador player(true);

  //Jugador conoce a los lugares
  player.conocerLugar(&orillaIzquierda);
  player.conocerLugar(&barca);
  player.conocerLugar(&orillaDerecha);
  //Jugador conoce a la barca por aparte
  player.conocerBarca(&barca);
  //La barca conoce a las orillas
  barca.conocerOrillas(&orillaIzquierda);
  barca.conocerOrillas(&orillaDerecha);

  //Jugador crea a los individuos
  Individuo* robot = player.crearIndividuo("Robot", "R");
  Individuo* zorro = player.crearIndividuo("Zorro", "Z");
  Individuo* conejo = player.crearIndividuo("Conejo", "C");
  Individuo* lechuga = player.crearIndividuo("Lechuga", "L");
  //Jugador conoce al robot
  player.conocerRobot(robot);

  //Se le asignan las posibles presas a los individuos
  player.agregarPresa(zorro, conejo);
  player.agregarPresa(conejo, lechuga);

  

while(player.mostrarSiPartidaEnCurso()) //Mientras la partida esté en curso
{
  cerr << ".2 orilla izquierda tiene vecino " << orillaIzquierda.tieneVecino() << endl;
  player.estado();
  player.leerTeclado();
  player.jugar(player.mostrarTecla());
  player.revisarPartida(robot);
}


  return 0;
  
}


