#pragma once
#include "raylib.h"
#include "../itens/Items.h"

enum estadoSolo {NORMAL, ARADO};

//Um tile de solo da fazenda
class Solo
{
    private:
        estadoSolo estado;
        bool regado;
        float tempoRegado;      //Quanto tempo falta pro solo secar
        bool plantado;
        float crescimento;      //Tempo que a planta ja cresceu
        Item fruta;     //Fruta que foi plantada, vazio se nao tem planta

    public:
        static constexpr float tempoSecar = 20.0f;      //Segundos que o solo fica regado
        static constexpr float tempoCrescer = 30.0f;        //Segundos regados que a fruta precisa pra ficar madura

        //Construtor da Classe
        Solo();

        bool arar();        //Retorna false se nao deu pra arar
        bool regar();
        bool plantar(Item frutaRef);        //Planta qualquer fruta que vier
        bool colher();
        void atualizar(float dt);       //Seca o solo e cresce a planta

        bool isArado();
        bool isRegado();
        bool isPlantado();
        bool isMaduro();
        Item getFruta();        //Retorna a fruta plantada
        int getEstagio();       //-1 sem planta, 0 a 3 conforme cresce

        void desenhar(float x, float y, float tam);
};
