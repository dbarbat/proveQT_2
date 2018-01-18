#include <QApplication>

#include "dado.h"
#include <ctime>
#include <cstdlib>

int Dado::numDadi=0; //Le variabili statiche (numDadi) vanno inizializzate nel .cpp
                     // Essendo numDadi uno Static, sarà visibile a tutte le istanze
                     // di Dado (non avranno una copia "personale" di numDadi)

// COSTRUTTORI

// DI DEFAULT (senza parametri)

// Costruttore senza delega
/*
Dado::Dado()

{
    numeroFacce=6;
    srand(time(0));
}
*/

// Costruttore con delega: sfrutta il codice già implementato per il costruttore
// con parametro. Inoltre se servono modifiche al costruttore, è sufficiente farle
// a quello che accetta parametri, visto che questo è una sua estensione
Dado::Dado() :Dado(6)
{
    // qui si possono aggiungere delle proprietà specifiche di un
    //dado a 6 facce...
}



// CON PARAMETRO
Dado::Dado(int nFacce)
{
    // Verifica numero facce (se <=0, assegna 6 di defualt)
    numeroFacce= nFacce>0 ? nFacce:6;
    srand( time(0));
    valore=0;

    dati = new int[10]; //dati = d.dati;
            for (int i=0;i<10;i++) dati[i]=i;



    numDadi++;


}


// Copy-Constructor NON di default
Dado::Dado(const Dado& d)
{
   numeroFacce=d.numeroFacce;
   valore=d.valore;

   dati = new int[10]; // il copy-constructor di defaul farebbe questo: dati = d.dati;
                        // In questo modo però passi il riferimento alla variabile
                        // dati dell'oggetto che vuoi compiare. Col new invece crei
                        // uno spazio separato in cui copiare il contenuto di dati

   for (int i=0;i<10;i++) dati[i]=d.dati[i];
   numDadi++;

}


// DISTRUTTORE

Dado::~Dado()
{
    numDadi--;
    delete[] dati;
}

//****************************************************************************
// RIDEFINIZIONE OPERATORE DI ASSEGNAZIONE


Dado& Dado::operator=(const Dado& altro)
{
   numeroFacce=altro.numeroFacce;
   valore=altro.valore;

   for (int i=0;i<10;i++) dati[i]=altro.dati[i];

   return *this;

}



//****************************************************************************

// FUNZIONI DI UTILITA'

Dado* Dado::Clona()
{
    // Nel seguente modo, creando l'istanza "copia" di Dado, stai creando una copia sullo
    // stack. Non appena si esce dalla funzione Clona(), lo spazio in memoria utilizzato
    // per le sue variabili, viene restituito e di fatto si perde l'informazione di
    // "copia" (all'indirizzo &copia non ci saranno più le informazioni di "copia")

    // ATTENZIONE: Questo crasha !!
    /*
    Dado copia(numeroFacce);
    copia.setValore(valore);
    return &copia;
    */


    /* Qui allochi spazio nella memoria heap, la cui durata di estende fino al termine
     * del processo che l'ha generata. Quindi quando si esce da Clona, lo spazio in
     * memoria con tutte le informazioni continua ad esistere
     */

    //Quando un'istanza di Dado chiama Clona() per creare un copia di se stesso, passa il numero di facce
    //di cui è composto e il valore uscito
    Dado* copia= new Dado(numeroFacce);
    copia->setValore(valore);
    return copia;

}


int Dado::getNumDadi()
{
    return numDadi;
}

// Generazione di un numero casuale
int Dado::lancioDado()
{
    valore= rand() % numeroFacce + 1;
    return valore;
}

int Dado::getValore()
{
    return valore;
}

void Dado::setValore(int nuovoValore)
{
    if(nuovoValore>=0 && nuovoValore<= numeroFacce)
        valore=nuovoValore;
}

void Dado::Help()
{
    qDebug("Help... under construction.");
}

/*
 * - srand(time(0)) : inizializza la generazione di numeri casuali che altrimenti
 *  si ripeterebbero in una sequenza sempre uguale. Con l'argomento time(0) sceglie
 *  l'istante presente come "seme" per l'inizializzazione
*/

void Dado::StampaDati()
   {
       for (int i=0;i<10;i++) qDebug("%d",dati[i]);
   }

int Dado::getNumeroFacce() {return numeroFacce;}
