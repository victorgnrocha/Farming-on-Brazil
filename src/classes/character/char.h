#include "raylib.h"
#include "raymath.h"
#include <iostream>

class Personagem {
    public:
        //Construtor da Classe
        Personagem(std::string nome)       //Recebe nome e stamina
        {
            this->nome = nome;      //O atributo do objeto se torna o nome passado por referencia no construtor
            this->stamina = 100;        //O atributo do objeto recebe 100 de valor fixo
            this->vida = 100;       //Atribtuto Vida recebe 100
        }

        std::string getNome();      //Declaracao da getNome
        void setNome(std::string nomeRef);      //Declaracao setNome

        Vector2 getPosition();      //Declaracao getPosition
        void setPosition(Vector2 positionRef);      //Declaracao setPosition

        void setStamina(float staminaRef);           //Declaracao setStamina
        float getStamina();           //Declaracao getStamina

        void setMovimento(bool movimentoRef);
        bool getMovimento();

    private:
        std::string nome;       //String nome
        Vector2 playerPosition;     //PosicaoPlano
        float stamina;            //Stamina
        int vida;               //Vida
        bool movimento;

};