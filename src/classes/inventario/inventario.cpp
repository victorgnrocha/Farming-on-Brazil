#include "inventario.h"
#include <iostream>

Inventario::Inventario(int capacidade)
{
    this->capacidade = capacidade;
    slots.resize(capacidade);
}

bool Inventario::addItem(Item itemRef)
{
    int restante = itemRef.getQuantidade();

    for(Item& s : slots)
    {
        if(!s.isEmpty() && s.getNome() == itemRef.getNome() && s.getQuantidade() < s.getMaxStack())
        {
            int espaco = s.getMaxStack() - s.getQuantidade();
            int qtd = (restante < espaco) ? restante : espaco;
            s.setQuantidade(s.getQuantidade() + qtd);
            restante -= qtd;
            if(restante ==0) return true;
        }
    }

    for(Item& s :slots)
    {
        if(s.isEmpty())
        {
            int qtd = (restante < itemRef.getMaxStack()) ? restante : itemRef.getMaxStack();
            s = itemRef;
            s.setQuantidade(qtd);
            restante -= qtd;
            if(restante ==0) return true;
        }
    }
    return false;
}
