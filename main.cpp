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
#include "Barca.h"
#include "Individuo.h"
#include "Lugar.h"
#include "Orilla.h"
#include <vector>


using namespace std;

int main() 
{
  /*
    CREAR LA BARCA Y LAS ORILLAS
  */
  Orilla orillaIzquierda("Orilla",nullptr); //CREA ORILLA IZQ, VECINO NULO
  Barca barca("Barca", &orillaIzquierda,"B"); //CREAR BARCA,VECINO INICIAL, LETRA ASOCIADA
  Orilla orillaDerecha("Orilla Derecha", nullptr); //CREAR ORILLA DER, VECINO NULO

  /***********************************************************************
  CREAR JUGADOR
  con los respectivos lugares creados anteriormente (Orilla izquierda, Barca, Orilla Derecha)
  El usuario va añadiendo los individuos que desee.

  PD: Por lo pronto hay mucho desorden, pero es fácil de reubicar para que quede bonito xd
  ***********************************************************************/

  Jugador player(true);
  player.conocerLugar(&orillaIzquierda);
  player.conocerLugar(&barca);
  player.conocerLugar(&orillaDerecha);
  

  string tipoDeIndividuo, id, interaccion = "s";

     cout << "Cree los individuos que sean necesarios, tenga encuenta que entre más individuos cree, mayor será la dificultad" << endl << "Los individuos que puedes crear son los siguientes:" << endl << endl << "Robot" << endl << endl << "Zorro"<< endl << endl << "Conejo" << endl << endl << "Lechuga" << endl << endl;

  while(interaccion == "s" || interaccion == "S")
  {
    cout << "Por favor escriba el tipo de individuo que desea crear" << endl;
    getline(cin,tipoDeIndividuo);

    cout << "Asígnele una letra al individuo que creó anteriormente: " <<endl;
    getline(cin,id);
    
    player.crearIndividuo(tipoDeIndividuo,id); //Aqui se agrega el individuo al vector de individuos de jugador

    cout << "Usted ha creado un individuo tipo: " << tipoDeIndividuo << ", y será identificado con la letra: " << id << endl << "¿Desea crear otro individuo? teclee S para crear otro individuo y cualquier otra cosa para no crear más individuos" << endl << endl;
    getline(cin,interaccion);

  }

  cout << "\x1B[2J\x1B[H";//Limpia la consola para dar inicio a juego



  string orden = "";
  while(orden != "parar")
  {
    cout << endl << "meta tecla" << endl;
    getline(cin,orden);
    player.jugar(orden);
  }


  return 0;
  

  /*
  JUEGO COMO TAL  xddd lo anterior es solo establecer el juego, cantidad de individuos y sus respectivas teclas, a partir de aqui es el juego.
  OF KORS AQUÍ VA EL JUEGO :V
  */
}


