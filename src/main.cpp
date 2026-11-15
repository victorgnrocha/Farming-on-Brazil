//There's a nice day to farm on brazil :)

#include <iostream>
#include <stdlib.h>
#include "raylib.h"

int main()
{

    const int  larguraTela = 1920;
    const int alturaTela = 1080;

    Vector2 playerPosition = {(float)larguraTela/2, float(alturaTela/2)};


    InitWindow(larguraTela, alturaTela,"Farming on Brazil"); //Aceita apenas strings, se tentarmos definir como std::string ele não vai aceitar, 
                                                            // pois no c, string é um ponteiro char * que aponta pro primeiro caractere.

    SetTargetFPS(60);

    //LoopPrincipal

    while(!WindowShouldClose())
    {
        //Mapeando movimentacao
        if (IsKeyDown(KEY_A)) playerPosition.x += 1.5;



        BeginDrawing();                         //Iniciando a tela
            ClearBackground(RAYWHITE);

            DrawCircle(playerPosition.x, playerPosition.y , 50, MAROON);


        EndDrawing();
    }

    CloseWindow();


    std::cout << "Oi" << std::endl;
}