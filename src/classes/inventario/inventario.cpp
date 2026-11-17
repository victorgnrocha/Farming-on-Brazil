#include "inventario.h"
#include <iostream>

Inventario::Inventario(int capacidade)
{
    this->capacidade = capacidade;
    this->slotSelecionado = 0;      //Comeca no slot 1
    this->areaTela = {0, 0, 0, 0};
    slots.resize(capacidade);
}

bool Inventario::addItem(Item itemRef)
{
    int restante = itemRef.getQuantidade();

    //Primeiro tenta completar os stacks que ja existem
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

    //Depois coloca o que sobrou nos slots vazios
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
    return false;       //Inventario cheio, o que sobrou fica de fora
}

void Inventario::removerItem(int slot, int qtd)
{
    if(slot < 0 || slot >= this->capacidade) return;        //Slot invalido
    if(slots[slot].isEmpty()) return;       //Nada pra remover

    int novaQtd = slots[slot].getQuantidade() - qtd;
    if(novaQtd <= 0)
    {
        slots[slot] = Item();       //Zera o slot
    }
    else
    {
        slots[slot].setQuantidade(novaQtd);
    }
}

Item& Inventario::getItem(int slot)
{
    if(slot < 0 || slot >= this->capacidade) slot = 0;      //Evita acessar fora do vector
    return slots[slot];
}

int Inventario::contarItem(std::string nomeRef)
{
    int total = 0;
    for(Item& s : slots)
    {
        if(!s.isEmpty() && s.getNome() == nomeRef) total += s.getQuantidade();
    }
    return total;
}

int Inventario::getCapacidade()
{
    return this->capacidade;
}

bool Inventario::isFull()
{
    //Cheio = nenhum slot vazio e todos os stacks no maximo
    for(Item& s : slots)
    {
        if(s.isEmpty() || s.getQuantidade() < s.getMaxStack()) return false;
    }
    return true;
}

void Inventario::mostrarInventario()
{
    std::cout << "----- Inventario -----" << std::endl;
    for(int i = 0; i < this->capacidade; i++)
    {
        if(!slots[i].isEmpty())
        {
            std::cout << "Slot " << i << ": " << slots[i].getNome() << " x" << slots[i].getQuantidade() << std::endl;
        }
    }
    std::cout << "----------------------" << std::endl;
}

void Inventario::desenharInventario()
{
    const int tamSlot = 90;         //Tamanho de cada slot em pixels
    const int espaco = 8;           //Espaco entre os slots
    const int porLinha = 10;        //Slots por linha
    int linhas = (this->capacidade + porLinha - 1) / porLinha;

    int largura = porLinha * (tamSlot + espaco) + espaco;
    int altura = linhas * (tamSlot + espaco) + espaco + 30;     //+30 pro titulo
    int posX = (GetScreenWidth() - largura) / 2;        //Centraliza na horizontal
    int posY = GetScreenHeight() - altura - 20;     //Cola embaixo da tela

    //Fundo do inventario
    DrawRectangle(posX, posY, largura, altura, Fade(BLACK, 0.7f));
    DrawRectangleLines(posX, posY, largura, altura, RAYWHITE);
    this->areaTela = {(float)posX, (float)posY, (float)largura, (float)altura};     //Guarda pra checar o mouse
    DrawText("Inventario  [1-4] ferramenta  [Esq] usa  [Dir] planta  [E] pega tangerina  [I] fecha", posX + espaco, posY + 6, 20, RAYWHITE);

    for(int i = 0; i < this->capacidade; i++)
    {
        int x = posX + espaco + (i % porLinha) * (tamSlot + espaco);
        int y = posY + 30 + espaco + (i / porLinha) * (tamSlot + espaco);

        DrawRectangle(x, y, tamSlot, tamSlot, Fade(DARKGRAY, 0.8f));     //Slot

        //Numero da tecla nos slots selecionaveis
        if(i < maxSelecionavel) DrawText(std::to_string(i + 1).c_str(), x + 4, y + 4, 16, LIGHTGRAY);

        Item& s = slots[i];
        if(s.isEmpty())
        {
            DrawRectangleLines(x, y, tamSlot, tamSlot, GRAY);
            continue;       //Slot vazio, so desenha a borda
        }

        //Ferramenta fica com borda amarela pra destacar
        Color borda = (s.getType() == FERRAMENTA) ? GOLD : RAYWHITE;
        DrawRectangleLines(x, y, tamSlot, tamSlot, borda);

        DrawRectangle(x + 25, y + 12, tamSlot - 50, tamSlot - 50, s.getCor());       //Icone placeholder com a cor do item

        //Nome centralizado embaixo do icone
        int larguraNome = MeasureText(s.getNome().c_str(), 14);
        DrawText(s.getNome().c_str(), x + (tamSlot - larguraNome) / 2, y + tamSlot - 26, 14, RAYWHITE);

        //Quantidade so aparece se o item empilha
        if(s.getMaxStack() > 1)
        {
            std::string qtd = std::to_string(s.getQuantidade());
            DrawText(qtd.c_str(), x + tamSlot - MeasureText(qtd.c_str(), 16) - 4, y + 4, 16, YELLOW);
        }
    }

    //Destaque do slot selecionado, desenhado por ultimo pra ficar por cima
    int selX = posX + espaco + (this->slotSelecionado % porLinha) * (tamSlot + espaco);
    int selY = posY + 30 + espaco + (this->slotSelecionado / porLinha) * (tamSlot + espaco);
    DrawRectangleLinesEx((Rectangle){(float)selX - 3, (float)selY - 3, (float)tamSlot + 6, (float)tamSlot + 6}, 4, YELLOW);
}

void Inventario::setSlotSelecionado(int slotRef)
{
    if(slotRef < 0 || slotRef >= maxSelecionavel) return;       //So aceita 1 a 4
    this->slotSelecionado = slotRef;
}

int Inventario::getSlotSelecionado()
{
    return this->slotSelecionado;
}

Item& Inventario::getItemSelecionado()
{
    return slots[this->slotSelecionado];
}

bool Inventario::removerItemPorNome(std::string nomeRef, int qtd)
{
    if(contarItem(nomeRef) < qtd) return false;     //Nao tem o suficiente, nao remove nada

    for(int i = 0; i < this->capacidade && qtd > 0; i++)
    {
        if(!slots[i].isEmpty() && slots[i].getNome() == nomeRef)
        {
            int tirar = (qtd < slots[i].getQuantidade()) ? qtd : slots[i].getQuantidade();
            removerItem(i, tirar);
            qtd -= tirar;
        }
    }
    return true;
}

bool Inventario::mouseEmCima()
{
    return CheckCollisionPointRec(GetMousePosition(), this->areaTela);
}
