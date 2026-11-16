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
        std::string setNome(std::string nomeRef);      //Declaracao setNome

        Vector2 getPosition();      //Declaracao getPosition
        Vector2 setPosition(Vector2 positionRef);      //Declaracao setPosition

        int setStamina(int staminaRef);           //Declaracao setStamina
        int getStamina();           //Declaracao getStamina

    private:
        std::string nome;       //String nome
        Vector2 playerPosition;     //PosicaoPlano
        int stamina;            //Stamina
        int vida;               //Vida

};