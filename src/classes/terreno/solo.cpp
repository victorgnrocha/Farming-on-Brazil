#include "solo.h"

Solo::Solo()
{
    this->estado = NORMAL;
    this->regado = false;
    this->tempoRegado = 0.0f;
    this->plantado = false;
    this->crescimento = 0.0f;
}

//Acoes
bool Solo::arar()
{
    if(this->plantado) return false;        //Nao ara em cima da planta
    this->estado = ARADO;
    return true;
}

bool Solo::regar()
{
    if(this->estado != ARADO) return false;     //So rega solo arado
    this->regado = true;
    this->tempoRegado = tempoSecar;     //Reseta o tempo pra secar
    return true;
}

bool Solo::plantar()
{
    if(this->estado != ARADO || this->plantado) return false;       //Precisa estar arado e vazio
    this->plantado = true;
    this->crescimento = 0.0f;
    return true;
}

bool Solo::colher()
{
    if(!isMaduro()) return false;
    this->plantado = false;     //Solo continua arado depois da colheita
    this->crescimento = 0.0f;
    return true;
}

void Solo::atualizar(float dt)
{
    if(!this->regado) return;       //Solo seco, planta nao cresce

    if(this->plantado && this->crescimento < tempoCrescer) this->crescimento += dt;

    this->tempoRegado -= dt;
    if(this->tempoRegado <= 0)
    {
        this->tempoRegado = 0;
        this->regado = false;       //Secou
    }
}

//Estados
bool Solo::isArado()
{
    return this->estado == ARADO;
}

bool Solo::isRegado()
{
    return this->regado;
}

bool Solo::isPlantado()
{
    return this->plantado;
}

bool Solo::isMaduro()
{
    return this->plantado && this->crescimento >= tempoCrescer;
}

int Solo::getEstagio()
{
    if(!this->plantado) return -1;
    if(isMaduro()) return 3;
    return (int)(this->crescimento / tempoCrescer * 3);     //0, 1 ou 2
}

//Desenho
void Solo::desenhar(float x, float y, float tam)
{
    if(this->estado == NORMAL) return;      //Solo normal fica por conta do mapa

    Color corSolo = this->regado ? (Color){80, 50, 30, 255} : (Color){150, 105, 60, 255};       //Regado fica mais escuro
    DrawRectangleV((Vector2){x, y}, (Vector2){tam, tam}, corSolo);

    //Placeholder da tangerina, cresce conforme o estagio
    Vector2 centro = {x + tam/2, y + tam/2};
    switch(getEstagio())
    {
        case 0:
            DrawCircleV(centro, tam*0.12f, GREEN);      //Broto
            break;
        case 1:
            DrawCircleV(centro, tam*0.25f, GREEN);      //Mudinha
            break;
        case 2:
            DrawCircleV(centro, tam*0.38f, DARKGREEN);      //Arbusto
            break;
        case 3:
            DrawCircleV(centro, tam*0.42f, DARKGREEN);      //Arbusto com fruta
            DrawCircleV((Vector2){centro.x - tam*0.15f, centro.y - tam*0.1f}, tam*0.1f, ORANGE);
            DrawCircleV((Vector2){centro.x + tam*0.15f, centro.y - tam*0.05f}, tam*0.1f, ORANGE);
            DrawCircleV((Vector2){centro.x, centro.y + tam*0.17f}, tam*0.1f, ORANGE);
            break;
        default:
            break;      //Sem planta
    }
}
