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
    this->nome = nomeRef;
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
    this->quantidade = quantidadeRef;
    if(this->quantidade <= 0) this->quantidade = 0;     //Nao deixa ficar negativo
    if(this->quantidade >= this->maxStack)
    {
        this->quantidade = this->maxStack;      //Trava no maximo do stack
        std::cout << "Quantidade máxima" << std::endl;
    }
}

//max stack

void Item::setMaxStack(int stackRef)
{
    this->maxStack = stackRef;
}

int Item::getMaxStack()
{
    return this->maxStack;
}

//cultura

tipoCultura Item::getCultura()
{
    return this->cultura;
}

//vazio

bool Item::isEmpty()
{
    return quantidade <=0;
}
