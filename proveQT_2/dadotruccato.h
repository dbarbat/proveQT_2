#ifndef DADOTRUCCATO_H
#define DADOTRUCCATO_H

#include "dado.h"

class dadoTruccato : public Dado
{

    int facciaTruccata;
    int livelloTrucco;
    int provaGraffa=0;

public:
    dadoTruccato(); //ATTENZIONE. Nella classe madre (Dado) deve OBBLIGATORIAMENTE
                    // esserci il costruttore senza parametri. E' necessario in
                    // quanto questa classe eredita da Dado, quindi il primo
                    // costruttore ad essere richiesto è proprio quello di Dado
                    // per costruire tutti i membri di base che verranno ereditati

    dadoTruccato(int quanteFacce, int facciaDaTruccare, int livelloTrucco);
    ~dadoTruccato();
    dadoTruccato(const dadoTruccato& other);
    dadoTruccato& operator =(const dadoTruccato& other);
    int GetfacciaTruccata() { return facciaTruccata; }
    void SetfacciaTruccata(int val) { facciaTruccata = val; }
    int GetlivelloTrucco() { return livelloTrucco; }
    void SetlivelloTrucco(int val) { livelloTrucco = val; }
    int GetprovaGraffa() { return provaGraffa; }


    int lancioDado();   // La classe madre (Dado) ha una funzione con lo stesso nome,
                        // ma è possibile crearne una versione "personalizzata"
                        // per la classe figlia dadoTruccato


};

#endif // DADOTRUCCATO_H
