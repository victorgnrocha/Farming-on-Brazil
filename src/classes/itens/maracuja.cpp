#include "maracuja.h"

Maracuja::Maracuja(int quantidade) : Item("Maracuja", YELLOW, 64, COLHEITA, quantidade, CULTURA_MARACUJA)
{
}

SementeMaracuja::SementeMaracuja(int quantidade) : Item("Sem. Maracuja", DARKBROWN, 64, SEMENTE, quantidade, CULTURA_MARACUJA)
{
}
