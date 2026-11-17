#include "raylib.h"
#include <vector>
#include "./itens/Items.h"

class Inventario
{
    private:
        std::vector<Item> slots;
        int capacidade;

    public:
        Inventario(int capacidade = 20);

        bool addItem(Item item);
        void removerItem(int slot, int qtd = 1);
        int getCapacidade();
        bool isFull();
};