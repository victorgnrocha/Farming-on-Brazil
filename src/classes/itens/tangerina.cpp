#include "tangerina.h"

//Nome "Tangerina", cor laranja, stack de 64 e tipo colheita
Tangerina::Tangerina(int quantidade) : Item("Tangerina", ORANGE, 64, COLHEITA, quantidade, CULTURA_TANGERINA)
{
}

SementeTangerina::SementeTangerina(int quantidade) : Item("Sem. Tangerina", BEIGE, 64, SEMENTE, quantidade, CULTURA_TANGERINA)
{
}
