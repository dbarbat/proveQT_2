#include "mainwindow.h"
#include <QApplication>
#include "gioco.h"
#include "dadotruccato.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Dado d1(6), d2(4), d3;



    dadoTruccato d(8, 5, 2);

    //d.setValore(1);   // Volendo, la classe figlia può interagire con i metodi
                        // pubblici della classe madre per modificare le variabili
                        // private della stessa.

    qDebug("la variabile provaGraffa vale %d.",d.GetprovaGraffa());

    return 0;

    qDebug("Il dado truccato ha %d facce",d.getNumeroFacce());


    for (int i=0; i<10; i++)
        qDebug("E' uscito: %d",d.lancioDado());

    //d.setValore(1);



    //******************************************************************************
    // PROVE COPY-CONSTRUCTOR E RIDEFINIZIONE OPERATORE '='
    //******************************************************************************

    // Nel dado.h:
    //  - rendere public la variabile dati
    //  - Commentare la ridefinizione di '='
    // Nel classeDado.cpp
    //  - Commentare l'implementazione della ridefinizione di '='
    //
    // Verificare che se non si rifedinisce l'operatore '=', l'assegnazione di un
    // oggetto ad un altro già esistente (d1=d2), comporterà la chiamata del
    // costruttore di default a causa del quale d2 punterà agli stessi spazi di
    // memoria di d1

    /*
    d1.setValore(1);
    d2.setValore(2);

    Dado d5(d1);    // Qui stai creando un nuovo oggetto Dado (d5) richiamando il
                    // copy-constructor creato da te (quindi le aree di memoria di d5
                    // saranno distinte da quelle di d1)

    d2=d1;  // Qui si sta modificando un oggetto GIA esistente. Se non ridefinisci
            // l'operatore "=", invocherà il copy-constructor di default

    qDebug("Valore d1: %d",d1.getValore());
    qDebug("Valore d2: %d",d2.getValore());
    qDebug("Valore d5: %d",d5.getValore());

    d1.dati[0]=35;  // Questa modifica si ripercuoterà su tutti gli oggetti creati come
                    // copia di d1 con il copy-constructor di default

    qDebug("Primo elemento dati d1: %d",d1.dati[0]);
    qDebug("Primo elemento dati d2: %d",d2.dati[0]);
    qDebug("Primo elemento dati d5: %d",d5.dati[0]);

    //Dado d5(d3); // Dado d5=d3;   // Modi per richiamare il costruttore-copia

    //Gioco g("Gioco dell'oca",14.5,4,d1,d2);

    */
    //******************************************************************************
    // TEST VARI
    //******************************************************************************

    qDebug("%d, %d, %d",d1.lancioDado(),d2.lancioDado(),d3.lancioDado());


    // Test getValore()
    qDebug("Valore precedente di d1: %d",d1.getValore());
    d1.lancioDado();
    qDebug("Nuovo valore di d1: %d",d1.getValore());

    // Test funzione statica: può essere invocata senza necessità di creare un'istanza
    // di dado
    Dado::Help();

    Dado* d4=d3.Clona();

    qDebug("Numero dadi creati: %d",d3.getNumDadi());

    qDebug("Valore dado d3: %d",d3.getValore());
    qDebug("Valore dado clonato: %d",d4->getValore());

    delete d4;

    qDebug("Ora i dadi creati sono %d",d3.getNumDadi());

    return a.exec();
}

