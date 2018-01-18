#include "gioco.h"

/* Esempio di lista di inizializzazione. Con questa tecnica puoi inizializzare le
 * variabili al momento della loro creazione
 */

Gioco::Gioco(std::string _nome, double _costo, int _etaMinimaConsigliata)
    : nome(_nome), costo(_costo), etaMinimaConsigliata(_etaMinimaConsigliata),
      dg1(6),dg2(6)
{
    /* Senza lista di inizializzazione, le tre variabili private di seguito, non vengono
     * create nella memoria, ma MODIFICATE in quanto il compilatore prima
     * invoca prima i costruttori dei membri della classe, variabili incluse.

     // Se inizializzi le varibili private in questo punto, sono GIA' state create
       //dal compilatore !!! Le stai solo modificando !!!
    nome=_nome;
    costo=_costo;
    etaMinimaConsigliata=_etaMinimaConsigliata;
    */

}


Gioco::Gioco(std::string _nome, double _costo, int _etaMinimaConsigliata, Dado primoDado,
             Dado secondoDado)
    : nome(_nome), costo(_costo), etaMinimaConsigliata(_etaMinimaConsigliata),
      dg1(primoDado),dg2(secondoDado)
{

    dg1.StampaDati();

    //dg1.dati[0]=100;

}
