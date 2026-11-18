#pragma once
#include "raylib.h"
#include <vector>
#include "../itens/Items.h"

class Inventario
{
    private:
        std::vector<Item> slots;
        int capacidade;
        int slotSelecionado;        //Slot que ta na mao do personagem
        Rectangle areaTela;     //Onde o inventario foi desenhado, pra saber se o mouse ta em cima

    public:
        Inventario(int capacidade = 20);

        bool addItem(Item item);
        void removerItem(int slot, int qtd = 1);
        Item& getItem(int slot);        //Retorna o item de um slot
        int contarItem(std::string nomeRef);        //Soma a quantidade de um item em todos os slots
        int getCapacidade();
        bool isFull();
        void mostrarInventario();       //Printa o inventario no terminal
        void desenharInventario();      //Desenha o inventario na tela

        static const int maxSelecionavel = 10;       //So a primeira linha (1 a 0) pode ser selecionada
        void setSlotSelecionado(int slotRef);
        int getSlotSelecionado();
        Item& getItemSelecionado();
        bool removerItemPorNome(std::string nomeRef, int qtd = 1);      //Remove de qualquer slot, false se nao tiver o suficiente
        bool mouseEmCima();
};
