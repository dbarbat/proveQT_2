#ifndef GIOCO_H
#define GIOCO_H

#include <string>
#include "dado.h"

class Gioco
{
     std::string nome;
     double costo;
     int etaMinimaConsigliata;

     Dado dg1, dg2;   // queste due istanze sono inzializzate nella lista di
                    // inizializzazione del costruttore di "gioco".
                    // In questo modo vengono create anche senza
                    // il costruttore di default di Dado


     public:
       Gioco(std::string _nome, double _costo, int _etaMinimaConsigliata);
       Gioco(std::string _nome, double _costo, int _etaMinimaConsigliata, Dado primoDado,
                    Dado secondoDado);

};

#endif // GIOCO_H
