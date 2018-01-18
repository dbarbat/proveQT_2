#include "dadotruccato.h"



dadoTruccato::dadoTruccato() : Dado(), provaGraffa{5}
{
    //ctor
}


dadoTruccato::dadoTruccato(int quanteFacce, int facciaDaTruccare, int livelloTrucco) : Dado( quanteFacce )
{
    facciaTruccata=facciaDaTruccare;
    this->livelloTrucco=livelloTrucco;


}


int dadoTruccato::lancioDado()
{
    int lancioNormale = Dado::lancioDado();

    int r = valore;

    return lancioNormale > 3 ? facciaTruccata : lancioNormale;

}


dadoTruccato::~dadoTruccato()
{
    //dtor
}

dadoTruccato::dadoTruccato(const dadoTruccato& other)
{
    //copy ctor
}

dadoTruccato& dadoTruccato::operator=(const dadoTruccato& rhs)
{

}



