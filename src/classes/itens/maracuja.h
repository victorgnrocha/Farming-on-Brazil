#pragma once
#include "Items.h"

class Maracuja : public Item
{
    public:
        Maracuja(int quantidade = 1);
        static const int recuperaStamina = -20;
};

//Semente de maracuja, planta e vira um pe de maracuja
class SementeMaracuja : public Item
{
    public:
        SementeMaracuja(int quantidade = 1);
};
