#ifndef DADO_H
#define DADO_H


class Dado
{

    int numeroFacce;

    int* dati;  // rendila public per le prove sui copy-constructor e ridefinizione
                // operatore di assegnamento
protected:
    int valore=0;

public:

    Dado();
    Dado(int nFacce);

    //copy constructor, costruttore copia
    Dado(const Dado& d);  //Dado d

    //ridefinizione operatore di assegnamento '='
    Dado& operator=(const Dado& altro);

    //Dado (Dado d); // Il costruttore di copia non puo essere scritto cosi: è ricorsivo

    ~Dado();

    int lancioDado();
    int getValore();
    void setValore(int nuovoValore);

    static void Help();
    static int numDadi; //Il compilatore non permette di inizializzare
                        //le variabili statiche nei .h perchè essendo inclusi in più
                        // file .cpp richiederebbero di volta in volta la creazione
                        // di un simbolo.
    int getNumDadi();   // piu sensato come STATIC
    Dado* Clona();
    void StampaDati();
    int getNumeroFacce();

};

#endif // DADO_H
