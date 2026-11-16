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
                                                            // pois no c, string é um ponteiro char * que aponta pro primeiro caractere.

    SetTargetFPS(60);

    Texture2D playerTexture = LoadTexture("assets/player.png"); // Carrego a skin do player
    SetTextureFilter(playerTexture, TEXTURE_FILTER_POINT);

    float frameWidth = (float)(playerTexture.width);
    float frameHeight = (float)(playerTexture.height);

    // Retângulo que recorta qual parte da imagem será desenhada
    Rectangle frameRec = { 0.0f, 0.0f, frameWidth, frameHeight };

    // Controle de tempo da animação
    int currentFrame = 0;
    float framesCounter = 0.0f;
    float framesSpeed = 8.0f; // Quantos frames por segundo a animação roda

    
    //LoopPrincipal
    //-----------------------------------------------------------------
    while(!WindowShouldClose())
    {
        float velocity = baseVelocity;
        if(IsKeyDown(KEY_LEFT_SHIFT)) velocity *= 2.0;

        bool isMoving = false;

        //Mapeando movimentacao
        if (IsKeyDown(KEY_A)) { playerPosition.x -= GetFrameTime()*velocity; isMoving = true; }      //Movimetação esquerda
        if (IsKeyDown(KEY_D)) { playerPosition.x += GetFrameTime()*velocity; isMoving = true; }      //Movimentação direita
        if (IsKeyDown(KEY_W)) { playerPosition.y -= GetFrameTime()*velocity; isMoving = true; }      //Movimentação cima
        if (IsKeyDown(KEY_S)) { playerPosition.y += GetFrameTime()*velocity; isMoving = true; }      //Movimentação baixo


        BeginDrawing();                         //Iniciando a tela
            ClearBackground(RAYWHITE);          //Mantém o Bg sempre branco

            float scale = 4.0f;
            Rectangle destRec = {
                playerPosition.x,
                playerPosition.y,
                frameWidth * scale,
                frameHeight * scale
            };
            Vector2 origin = { (frameWidth * scale) / 2.0f, (frameHeight * scale) / 2.0f };

            DrawTexturePro(playerTexture, frameRec, destRec, origin, 0.0f, WHITE);

        EndDrawing(); //Encerra o Desenho da Tela
    }
    //----------------------------------------------------------------------
    //Fim do Loop Principal


    UnloadTexture(playerTexture); // Libero a memória da GPU
    CloseWindow();      //Fecha a Janela
}