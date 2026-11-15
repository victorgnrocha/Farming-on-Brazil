//There's a nice day to farm on brazil :)

#include <iostream>
#include <stdlib.h>
#include "raylib.h"

int main()
{

    const int  larguraTela = 1920;
    const int alturaTela = 1080;


    InitWindow(larguraTela, alturaTela,"Farming on Brazil"); //Aceita apenas strings, se tentarmos definir como std::string ele não vai aceitar, 
                                                            // pois no c, string é um ponteiro char * que aponta pro primeiro caractere.

    SetTargetFPS(60);

    //LoopPrincipal

    while(!WindowShouldClose())
    {
        //Iniciando a tela
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Farming on Brazil", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();


    std::cout << "Oi" << std::endl;
}