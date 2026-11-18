#pragma once
#include "raylib.h"
#include "Items.h"

namespace Culturas
{
    void carregarTexturas();        //Chamar DEPOIS do InitWindow, senao a textura nao carrega
    void descarregarTexturas();     //Chamar ANTES do CloseWindow

    bool temSprite(tipoCultura cultura);        //false se a textura nao carregou ou a cultura nao tem sprite
    void desenharEstagio(tipoCultura cultura, int estagio, Rectangle destino);      //estagio de 0 a 3
    void desenharIcone(Item& item, Rectangle destino);      //Semente mostra a muda, fruta mostra a planta madura

    Item criarColheita(tipoCultura cultura, int quantidade);        //Fruta que a planta da quando colhe
}
