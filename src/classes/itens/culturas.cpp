#include "culturas.h"
#include "maracuja.h"
#include "tangerina.h"

namespace
{
    Texture2D tileset{};        //id 0 = textura nao carregada

    const float tamSprite = 16.0f;
    const float linhaY = 43.0f;
    const float xTangerina = 128.0f;        //Estagios 0..3 em x = 128, 144, 160, 176
    const float xMaracuja = 192.0f;         //Estagios 0..3 em x = 192, 208, 224, 240

    bool posicaoNoTileset(tipoCultura cultura, float& x)
    {
        switch(cultura)
        {
            case CULTURA_TANGERINA: x = xTangerina; return true;
            case CULTURA_MARACUJA:  x = xMaracuja;  return true;
            default:                return false;
        }
    }
}

void Culturas::carregarTexturas()
{
    tileset = LoadTexture(ASSETS_PATH "vectoraith_tileset_farmingsims_details_summer.png");
    SetTextureFilter(tileset, TEXTURE_FILTER_POINT);        //Pixel art sem borrar
}

void Culturas::descarregarTexturas()
{
    if(tileset.id != 0) UnloadTexture(tileset);
    tileset = Texture2D{};
}

bool Culturas::temSprite(tipoCultura cultura)
{
    float x;
    return tileset.id != 0 && posicaoNoTileset(cultura, x);
}

void Culturas::desenharEstagio(tipoCultura cultura, int estagio, Rectangle destino)
{
    float x;
    if(tileset.id == 0 || !posicaoNoTileset(cultura, x)) return;
    if(estagio < 0) return;
    if(estagio > 3) estagio = 3;

    Rectangle origem = {x + estagio * tamSprite, linhaY, tamSprite, tamSprite};
    DrawTexturePro(tileset, origem, destino, (Vector2){0, 0}, 0.0f, WHITE);
}

void Culturas::desenharIcone(Item& item, Rectangle destino)
{
    int estagio = (item.getType() == SEMENTE) ? 1 : 3;
    desenharEstagio(item.getCultura(), estagio, destino);
}

Item Culturas::criarColheita(tipoCultura cultura, int quantidade)
{
    switch(cultura)
    {
        case CULTURA_MARACUJA:  return Maracuja(quantidade);
        case CULTURA_TANGERINA: return Tangerina(quantidade);
        default:                return Item();      //Cultura desconhecida, nao da nada
    }
}
