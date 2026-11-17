#include "Items.h"
#include <iostream>

//Item tipo
void Item::setType(tipoItem tipoRef)
{
    this->tipo = tipoRef;
}

tipoItem Item::getType()
{
    return this->tipo;
}
//Nome
std::string Item::getNome()
{
    return this->nome;
}

void Item::setNome(std::string nomeRef)
{
    this->nome = nome;
}
//Cor
Color Item::getCor()
{
    return this->cor;
}

void Item::setCor(Color corRef)
{
    this->cor = corRef;
}
//quantidade dos Itens

int Item::getQuantidade()
{
    return this->quantidade;
}

void Item::setQuantidade(int quantidadeRef)
{
    this->quantidade = quantidade;
    if(quantidade >= this->maxStack)
    {
        std::cout << "Quantidade máxima" << std::endl;
    }
}

//max stack

int Item::setMaxStack(int stackRef)
{
    this->maxStack = stackRef;
}

void Item::getMaxStack()
{
    return this->maxStack;
}

//vazio

bool Item::isEmpty()
{
    return quantidade <=0;
}

