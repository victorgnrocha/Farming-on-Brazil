//There's a nice day to farm on brazil :)

#include <iostream>
#include <stdlib.h>
#include "raylib.h"

#define RAYTMX_IMPLEMENTATION
#include "libs/raytmx/raytmx.h"

#include "./classes/character/char.h"

int main()
{
    const int  larguraTela = 1920;
    const int alturaTela = 1080;

    Vector2 playerPosition = {(float)larguraTela/2, float(alturaTela/2)};
    float baseVelocity = 150.0f; // Declaro a velocidade base do personagem

    ChangeDirectory(GetApplicationDirectory());

    InitWindow(larguraTela, alturaTela,"Farming on Brazil"); //Aceita apenas strings, se tentarmos definir como std::string ele não vai aceitar, 
                                                            // pois no c, string é um ponteiro char * que aponta pro primeiro caractere
    Camera2D charCam = {0};
    charCam.target = (Vector2){playerPosition.x, playerPosition.y};
    charCam.offset = (Vector2){GetRenderWidth()/2.0f, GetRenderHeight()/2.0f};
    charCam.rotation = 0.0f;
    charCam.zoom = 5.0f;

    TmxMap* mapa = LoadTMX("assets/maps/FarmingOnBrazil.tmx");
    if(mapa == nullptr)
    {
        CloseWindow();
        std::cout << "Erro! Ponteiro nulo." << std::endl;
        return 1;
    }

    Personagem farmer = Personagem("Victor");

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


        charCam.target = (Vector2){playerPosition.x, playerPosition.y};

        BeginDrawing();                         //Iniciando a tela
            ClearBackground(RAYWHITE);          //Mantém o Bg sempre branco

            BeginMode2D(charCam);

            DrawTMX(mapa, &charCam, nullptr, 0, 0, WHITE);
            DrawCircleV(playerPosition , 5, MAROON); //Desenha o placeholder do personagem;

            EndMode2D();        //Encera o modo da câmera

        EndDrawing(); //Encerra o Desenho da Tela
    }
    //----------------------------------------------------------------------
    //Fim do Loop Principal

    UnloadTMX(mapa);
    CloseWindow();      //Fecha a Janela
}