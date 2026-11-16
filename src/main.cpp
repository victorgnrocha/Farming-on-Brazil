//There's a nice day to farm on brazil :)

#include <iostream>
#include <stdlib.h>
#include "raylib.h"

int main() 
{

    const int  larguraTela = 960;
    const int alturaTela = 540;

    Vector2 playerPosition = {(float)larguraTela/2, float(alturaTela/2)};
    float baseVelocity = 200.0f; // Declaro a velocidade base do personagem

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI);
    InitWindow(larguraTela, alturaTela,"Farming on Brazil"); //Aceita apenas strings, se tentarmos definir como std::string ele não vai aceitar, 
                                                            // pois no c, string é um ponteiro char * que aponta pro primeiro caractere.

    SetTargetFPS(60);

    //LoopPrincipal
    //-----------------------------------------------------------------
    while(!WindowShouldClose())
    {
        float velocity = baseVelocity;
        if(IsKeyDown(KEY_LEFT_SHIFT)) velocity *= 2.0;

        //Mapeando movimentacao
        if (IsKeyDown(KEY_A)) playerPosition.x -= GetFrameTime()*velocity;      //Movimetação esquerda
        if (IsKeyDown(KEY_D)) playerPosition.x += GetFrameTime()*velocity;      //Movimentação direita
        if (IsKeyDown(KEY_W)) playerPosition.y -= GetFrameTime()*velocity;      //Movimentação cima
        if (IsKeyDown(KEY_S)) playerPosition.y += GetFrameTime()*velocity;      //Movimentação baixo

        BeginDrawing();                         //Iniciando a tela
            ClearBackground(RAYWHITE);          //Mantém o Bg sempre branco

            DrawCircle(playerPosition.x, playerPosition.y , 50, MAROON); //Desenha o placeholder do personagem;

        EndDrawing(); //Encerra o Desenho da Tela
    }
    //----------------------------------------------------------------------
    //Fim do Loop Principal


    CloseWindow();      //Fecha a Janela
}