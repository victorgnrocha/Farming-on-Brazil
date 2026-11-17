#include "terreno.h"
#include <cmath>

Terreno::Terreno(int colunas, int linhas, float tamTile)
{
    this->colunas = colunas;
    this->linhas = linhas;
    this->tamTile = tamTile;
    solos.resize(colunas * linhas);     //Todo solo comeca NORMAL
}

Solo* Terreno::getSolo(int col, int lin)
{
    if(col < 0 || col >= this->colunas || lin < 0 || lin >= this->linhas) return nullptr;       //Fora da grade
    return &solos[lin * this->colunas + col];
}

int Terreno::getColuna(float x)
{
    return (int)std::floor(x / this->tamTile);      //floor pra posicao negativa nao cair no tile 0
}

int Terreno::getLinha(float y)
{
    return (int)std::floor(y / this->tamTile);
}

float Terreno::getTamTile()
{
    return this->tamTile;
}

void Terreno::atualizar(float dt)
{
    for(Solo& s : solos) s.atualizar(dt);
}

void Terreno::desenhar()
{
    for(int lin = 0; lin < this->linhas; lin++)
    {
        for(int col = 0; col < this->colunas; col++)
        {
            solos[lin * this->colunas + col].desenhar(col * this->tamTile, lin * this->tamTile, this->tamTile);
        }
    }
}
