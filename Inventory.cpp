#include "Inventory.h"
#include "Item.h"
#include <iostream>
#include <vector>

using namespace std;

//the inventory is a vector of ITEM objects
Inventory::Inventory(){
        vector<Item> storage;
}

//push_back to add to inventory
void Inventory::addToInventory(const Item& item){
    storage.push_back(item);
}

//go through vector of ITEMS and output each item and it's price
void Inventory::inventoryList(){
    for(int i=0;i<storage.size();i++){//looping through each item in them vector and printing it out
        cout << "ITEM: " << storage[i].getName() << " | PRICE: $" << storage[i].getPrice() << endl;
    }
    cout << endl;
}

//this function looks if this item exists in the vector for an item we passed in through the events file and finds its price
double Inventory::checkPrice(string thing){
    double price;
    string name;
    for(int i=0;i<storage.size();i++){
            name = storage[i].getName();
            price = storage[i].getPrice();
            if(name==thing) return price;
            //else{cout << "This item does not exist in out inventory" << endl;}
    }
}

