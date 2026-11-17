#pragma once
#include "raylib.h"
#include <vector>
#include "solo.h"

//Grade de tiles de solo da fazenda
class Terreno
{
    private:
        int colunas;
        int linhas;
        float tamTile;      //Tamanho de um tile no mundo
        std::vector<Solo> solos;

    public:
        //Construtor da Classe
        Terreno(int colunas, int linhas, float tamTile);

        Solo* getSolo(int col, int lin);        //nullptr se estiver fora da grade
        int getColuna(float x);     //Converte posicao do mundo pra coluna
        int getLinha(float y);      //Converte posicao do mundo pra linha
        float getTamTile();

        void atualizar(float dt);
        void desenhar();
};
