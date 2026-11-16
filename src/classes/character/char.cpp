#include <char.h>

std::string Personagem::setNome(std::string nomeRef)
{
    this->nome = nomeRef;
    return nome;
}

std::string Personagem::getNome()
{
    std::cout << "O nome:" << nome << std::endl;
    return nome;
}

int Personagem::setStamina(int staminaRef)
{
    this->stamina = staminaRef;
    return stamina;
}

int Personagem::getStamina()
{
    std::cout << stamina << std::endl;
    return stamina;
}

Vector2 Personagem::setPosition(Vector2 positionRef)
{
    this->playerPosition.x = positionRef.x;
    this->playerPosition.y = positionRef.y;
}