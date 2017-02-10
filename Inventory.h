#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <vector>
#include "Item.h"
using namespace std;


class Inventory{
    public:
        Inventory();
        void addToInventory(const Item& item);
        void inventoryList();
        double checkPrice(string thing);
    private:
        vector<Item> storage;
};

#endif // INVENTORY_H
