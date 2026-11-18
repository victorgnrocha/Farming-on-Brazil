//There's a nice day to farm on brazil :)

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "raylib.h"

#define RAYTMX_IMPLEMENTATION
#include "libs/raytmx/raytmx.h"

#include "./classes/character/char.h"
#include "./classes/itens/tangerina.h"
#include "./classes/itens/maracuja.h"
#include "./classes/terreno/terreno.h"

int main()
{
    const int  larguraTela = 1360;
    const int alturaTela = 765;
    float tempoDecorrido = 0.0f;
    int diasEstacao = 31;
    int contadorDias = 0;

    float scale = 1.0f;

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

    //Ferramentas iniciais do personagem
    farmer.getInventario().addItem(Item("Enxada", BROWN, 1, FERRAMENTA));
    farmer.getInventario().addItem(Item("Regador", SKYBLUE, 1, FERRAMENTA));
    farmer.getInventario().addItem(Item("Machado", GRAY, 1, FERRAMENTA));
    farmer.getInventario().addItem(Item("Foice", LIGHTGRAY, 1, FERRAMENTA));
    bool inventarioAberto = true;       //Inventario comeca aberto na tela

    Terreno terreno = Terreno(120, 68, 16.0f);      //Grade de 120x68 tiles de 16px, cobre a area inicial
    const int alcanceFerramenta = 4;        //Distancia maxima em tiles pra usar ferramenta

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
        tempoDecorrido += GetFrameTime() * 144.0f;
        if(tempoDecorrido >= 86400.0f)
        {
            tempoDecorrido = 0;
            contadorDias ++;
        }
        std::cout << "Horas:" << tempoDecorrido/3600 << std::endl;
        std::cout << "Hoje eh o dia:" << contadorDias << std::endl;

        float velocity = baseVelocity;
        if(IsKeyDown(KEY_LEFT_SHIFT)) velocity *= 2.0;

        bool isMoving = false;

        //Mapeando movimentacao
        if (IsKeyDown(KEY_A)) { playerPosition.x -= GetFrameTime()*velocity; isMoving = true; }      //Movimetação esquerda
        if (IsKeyDown(KEY_D)) { playerPosition.x += GetFrameTime()*velocity; isMoving = true; }      //Movimentação direita
        if (IsKeyDown(KEY_W)) { playerPosition.y -= GetFrameTime()*velocity; isMoving = true; }      //Movimentação cima
        if (IsKeyDown(KEY_S)) { playerPosition.y += GetFrameTime()*velocity; isMoving = true; }      //Movimentação baixo
        if (isMoving) farmer.setMovimento(1);   //Gasta stamina andando em qualquer direção
        farmer.setPosition(playerPosition);    //Movimentação baixo
        farmer.setPosition(playerPosition);
        farmer.getPosition();

        if(farmer.getMovimento() == 1)
        {
            farmer.setStamina(-0.3);
        }
        else if (farmer.getMovimento() == 0)
        {
            farmer.setStamina(0.02);
        }
        if(farmer.getStamina() == 0)
        {
            velocity = velocity * 0.25;
        } 
        std::cout << std::setprecision(3) << farmer.getStamina() << std::endl;
        farmer.setMovimento(0);

        std::cout << farmer.getPosition().x << std::endl;
        std::cout << farmer.getPosition().y << std::endl;

        //Inventario
        if(IsKeyPressed(KEY_E))     //Colhe uma tangerina
        {
            if(!farmer.getInventario().addItem(Maracuja(1))) std::cout << "Inventario cheio!" << std::endl;
        }
        if(IsKeyPressed(KEY_I)) inventarioAberto = !inventarioAberto;     //Abre e fecha o inventario

        //Selecao de slot, de 1 a 0 (primeira linha do inventario)
        if(IsKeyPressed(KEY_ONE)) farmer.getInventario().setSlotSelecionado(0);
        if(IsKeyPressed(KEY_TWO)) farmer.getInventario().setSlotSelecionado(1);
        if(IsKeyPressed(KEY_THREE)) farmer.getInventario().setSlotSelecionado(2);
        if(IsKeyPressed(KEY_FOUR)) farmer.getInventario().setSlotSelecionado(3);
        if(IsKeyPressed(KEY_FIVE)) farmer.getInventario().setSlotSelecionado(4);
        if(IsKeyPressed(KEY_SIX)) farmer.getInventario().setSlotSelecionado(5);
        if(IsKeyPressed(KEY_SEVEN)) farmer.getInventario().setSlotSelecionado(6);
        if(IsKeyPressed(KEY_EIGHT)) farmer.getInventario().setSlotSelecionado(7);
        if(IsKeyPressed(KEY_NINE)) farmer.getInventario().setSlotSelecionado(8);
        if(IsKeyPressed(KEY_ZERO)) farmer.getInventario().setSlotSelecionado(9);


        charCam.target = (Vector2){playerPosition.x, playerPosition.y};

        //Tile embaixo do mouse e tile do player
        Vector2 mouseMundo = GetScreenToWorld2D(GetMousePosition(), charCam);       //Mouse na tela -> posicao no mundo
        int colMouse = terreno.getColuna(mouseMundo.x);
        int linMouse = terreno.getLinha(mouseMundo.y);
        int colPlayer = terreno.getColuna(playerPosition.x);
        int linPlayer = terreno.getLinha(playerPosition.y);
        int distancia = std::max(std::abs(colMouse - colPlayer), std::abs(linMouse - linPlayer));       //Distancia em tiles, conta diagonal
        bool noAlcance = distancia <= alcanceFerramenta;
        bool mouseNaInterface = inventarioAberto && farmer.getInventario().mouseEmCima();
        Solo* soloMouse = terreno.getSolo(colMouse, linMouse);

        //Usar ferramenta
        if(soloMouse != nullptr && noAlcance && !mouseNaInterface)
        {
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                std::string ferramenta = farmer.getInventario().getItemSelecionado().getNome();
                if(ferramenta == "Enxada")
                {
                    if(!soloMouse->arar()) std::cout << "Tem planta aqui!" << std::endl;
                }
                else if(ferramenta == "Regador")
                {
                    if(!soloMouse->regar()) std::cout << "Precisa arar antes de regar!" << std::endl;
                }
                else if(ferramenta == "Foice")
                {
                    Item colheita = soloMouse->getFruta();      //Pega a fruta antes, colher limpa o solo
                    if(soloMouse->colher())
                    {
                        colheita.setQuantidade(3);
                        farmer.getInventario().addItem(colheita);       //Colheita da 3 da mesma fruta plantada
                    }
                    else std::cout << "Nada maduro pra colher!" << std::endl;
                }
                else if(ferramenta == "Machado")
                {
                    std::cout << "Nada pra cortar aqui!" << std::endl;
                }
            }

            //Plantar a fruta selecionada com o botao direito
            if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
            {
                Item& fruta = farmer.getInventario().getItemSelecionado();
                if(fruta.isEmpty() || fruta.getType() != COLHEITA)
                {
                    std::cout << "Selecione uma fruta pra plantar!" << std::endl;
                }
                else if(soloMouse->plantar(fruta))
                {
                    farmer.getInventario().removerItem(farmer.getInventario().getSlotSelecionado(), 1);      //Gasta uma fruta do slot selecionado
                }
                else
                {
                    std::cout << "O solo precisa estar arado e vazio!" << std::endl;
                }
            }
        }

        terreno.atualizar(GetFrameTime());      //Seca o solo e cresce as plantas regadas

        BeginDrawing();                         //Iniciando a tela
            ClearBackground(RAYWHITE);          //Mantém o Bg sempre branco

            BeginMode2D(charCam);

            DrawTMX(mapa, &charCam, nullptr, 0, 0, WHITE);
            terreno.desenhar();

            //Contorno do tile do mouse, verde se alcanca e vermelho se ta longe
            if(soloMouse != nullptr && !mouseNaInterface)
            {
                float tam = terreno.getTamTile();
                DrawRectangleLinesEx((Rectangle){colMouse * tam, linMouse * tam, tam, tam}, 0.5f, noAlcance ? GREEN : RED);
            }

            DrawCircleV(playerPosition , 5, MAROON); //Desenha o placeholder do personagem;
            Vector2 origem = { frameWidth / 2.0f, frameHeight / 2.0f };
            Rectangle destRec = {playerPosition.x, playerPosition.y, frameWidth, frameHeight};     //Sem escala: o zoom da camera ja aumenta o sprite
            DrawTexturePro(playerTexture, frameRec, destRec, origem, 0.0f, WHITE);

            EndMode2D();        //Encera o modo da câmera

            //Interface fica fora da camera, senao ela anda junto com o mapa

            if(inventarioAberto) farmer.getInventario().desenharInventario();

        EndDrawing(); //Encerra o Desenho da Tela
    }
    //----------------------------------------------------------------------
    //Fim do Loop Principal
    UnloadTMX(mapa);


    UnloadTexture(playerTexture); // Libero a memória da GPU
    CloseWindow();      //Fecha a Janela
}