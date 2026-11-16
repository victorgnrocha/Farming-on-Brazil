#include "char.h"

void Personagem::setNome(std::string nomeRef)
{
    this->nome = nomeRef;
}

std::string Personagem::getNome()
{
    std::cout << "O nome:" << this->nome << std::endl;
    return nome;
}

void Personagem::setStamina(float staminaRef)
{
    this->stamina += staminaRef;
    if(this->stamina <= 0) this->stamina = 0;
    if(this->stamina >= 100) this->stamina = 100;
}

float Personagem::getStamina()
{
    std::cout << stamina << std::endl;
    return stamina;
}

void Personagem::setPosition(Vector2 positionRef)
{
    this->playerPosition.x = positionRef.x;
    this->playerPosition.y = positionRef.y;
}

Vector2 Personagem::getPosition()
{
    return this->playerPosition;
}

void Personagem::setMovimento(bool movimentoRef)
{
    this->movimento = movimentoRef;
}

bool Personagem::getMovimento()
{
    return this->movimento;
}