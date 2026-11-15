//There's a nice day to farm on brazil :)

#include <iostream>
#include <stdlib.h>
#include "raylib.h"

int main()
{
    const int  larguraTela = 1920;
    const int alturaTela = 1080;

    Vector2 playerPosition = {(float)larguraTela/2, float(alturaTela/2)};
    float baseVelocity = 200.0f; // Declaro a velocidade base do personagem

    InitWindow(larguraTela, alturaTela,"Farming on Brazil"); //Aceita apenas strings, se tentarmos definir como std::string ele não vai aceitar, 
                                                            // pois no c, string é um ponteiro char * que aponta pro primeiro caractere
    Camera2D charCam = {0};
    charCam.target = (Vector2){playerPosition.x, playerPosition.y};
    charCam.offset = (Vector2){GetRenderWidth()/2.0f, GetRenderHeight()/2.0f};
    charCam.rotation = 0.0f;
    charCam.zoom = 1.0f;

    SetTargetFPS(60);

    //LoopPrincipal
    //-----------------------------------------------------------------
    while(!WindowShouldClose())
    {
        float velocity = baseVelocity;
        if(IsKeyDown(KEY_LEFT_SHIFT)) velocity *= 2.0;

        charCam.target = (Vector2){playerPosition.x, playerPosition.y};

        //Mapeando movimentacao
        if (IsKeyDown(KEY_A)) playerPosition.x -= GetFrameTime()*velocity;      //Movimetação esquerda
        if (IsKeyDown(KEY_D)) playerPosition.x += GetFrameTime()*velocity;      //Movimentação direita
        if (IsKeyDown(KEY_W)) playerPosition.y -= GetFrameTime()*velocity;      //Movimentação cima
        if (IsKeyDown(KEY_S)) playerPosition.y += GetFrameTime()*velocity;      //Movimentação baixo

        BeginDrawing();                         //Iniciando a tela
            ClearBackground(RAYWHITE);          //Mantém o Bg sempre branco

            BeginMode2D(charCam);

            DrawCircle(playerPosition.x, playerPosition.y , 50, MAROON); //Desenha o placeholder do personagem;

            EndMode2D();

        EndDrawing(); //Encerra o Desenho da Tela
    }
    //----------------------------------------------------------------------
    //Fim do Loop Principal


    CloseWindow();      //Fecha a Janela
}