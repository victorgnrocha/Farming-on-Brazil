#pragma once
#include "Items.h"

class Maracuja : public Item
{
    public:
        Maracuja(int quantidade = 1);
        static const int recuperaStamina = -20;
};