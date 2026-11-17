#pragma once
#include "raylib.h"

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

    public:
        static constexpr float tempoSecar = 20.0f;      //Segundos que o solo fica regado
        static constexpr float tempoCrescer = 30.0f;        //Segundos regados que a tangerina precisa pra ficar madura

        //Construtor da Classe
        Solo();

        bool arar();        //Retorna false se nao deu pra arar
        bool regar();
        bool plantar();
        bool colher();
        void atualizar(float dt);       //Seca o solo e cresce a planta

        bool isArado();
        bool isRegado();
        bool isPlantado();
        bool isMaduro();
        int getEstagio();       //-1 sem planta, 0 a 3 conforme cresce

        void desenhar(float x, float y, float tam);
};
