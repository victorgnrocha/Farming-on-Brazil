#pragma once
#include "Items.h"

//Tangerina, fruta de colheita. Herda tudo de Item
class Tangerina : public Item
{
    public:
        //Construtor da Classe
        Tangerina(int quantidade = 1);      //Recebe so a quantidade, o resto e fixo

        static const int recuperaStamina = 15;      //Quanto de stamina a fruta devolve quando come
};
