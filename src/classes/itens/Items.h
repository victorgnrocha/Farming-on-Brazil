#pragma once
#include <raylib.h>
#include <string>

enum tipoItem {FERRAMENTA, SEMENTE, COLHEITA};
enum tipoCultura {SEM_CULTURA, CULTURA_MARACUJA, CULTURA_TANGERINA};      //Qual planta o item vira/vem, usado pra plantar, colher e escolher o sprite

class Item
{
    private:
        std::string nome;
        Color cor;
        int maxStack;
        int quantidade;
        tipoItem tipo;
        tipoCultura cultura;

    public:
        //Construtor vazio, usado pelos slots do inventario
        Item()
        {
            this->nome = "";        //Slot sem nome
            this->cor = BLANK;      //Sem cor
            this->maxStack = 0;
            this->tipo = COLHEITA;
            this->cultura = SEM_CULTURA;
            this->quantidade = 0;       //Quantidade 0 = slot vazio
        }

        Item(std::string nome, Color cor, int maxStack, tipoItem tipo, int quantidade = 1, tipoCultura cultura = SEM_CULTURA)
        {
            this->nome = nome;
            this->cor = cor;
            this->maxStack = maxStack;
            this->tipo = tipo;
            this->quantidade = quantidade;
            this->cultura = cultura;
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

        tipoCultura getCultura();

        bool isEmpty();
};
