#pragma once
#include <raylib.h>
#include <string>

enum tipoItem {FERRAMENTA, SEMENTE, COLHEITA};

class Item
{
    private:
        std::string nome;
        Color cor;
        int maxStack;
        int quantidade;
        tipoItem tipo;

    public:

        Item(std::string nome, Color cor, int maxStack, tipoItem tipo, int quantidade = 1)
        {
            this->nome = nome;
            this->cor = cor;
            this->maxStack = maxStack;
            this->tipo = tipo;
            this->quantidade = quantidade;
        }

        std::string getNome();
        void setNome(std::string nomeRef);

        Color getCor();
        void setCor(Color colorRef);

        int getQuantidade();
        void setQuantidade(int quantidadeRef);

        tipoItem getType();
        void setType(tipoItem tipoRef);

        int getMaxStack();
        void setMaxStack(int maxRef);

        bool isEmpty();
};