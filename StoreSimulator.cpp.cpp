//ALEKSANDRA KRUZE
//HW #4
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <stdlib.h>
#include "HardwareStore.h"
#include "Inventory.h"
using namespace std;

int main(){
    HardwareStore store(2);//CREATE A HARDWARE STORE
    fstream file("inventory.txt");//READ IN AN INVENTORY LIST
    string word, name;
    double price;
    int counter=1;//SINCE THERE IS A SPECIFC FORMAT OF THE LIST WE CAN SWITCH BETWEEN THE INPUT BEING ITEMNAME OR ITEMPRICE
    while (file >> word){//LOOP THROUGH WHOLE FILE
        if(counter==1){//COUNTER KEEPS TRACK IF WE ARE LOOKING AT ITEM NAME
            name = word;//STORE THE ITEM NAME
            counter++;//SWITCH COUNTER TO ITEM PRICE
        }
        else if(counter==2){//COUNTER KEEPS TRACK IF WE ARE LOOKING AT ITEM PRICE
            price = atof(word.c_str());//CONVERT THE STRING PRICE TO A double AND STORE THE ITEM PRICE
            counter--;//SWITCH COUNTER BACK TO ITEM NAME
            Item object(name,price);//ONCE BOTH NAME AND PRICE ARE STORED IN THE TEMP VARIABLES, WE CREATE THE ITEM OBJECT
            store.inventory.addToInventory(object); //ADD THIS ITEM TO THE HARDWARE STORE'S VECTOR WE CREATED AT THE TOP
        }

    }
    file.close();

    //OUTPUTS THE STORE'S INVENTORY
    //store.inventory.inventoryList();

    fstream file2("Events.txt");//READ IN THE EVENTS FILE
    //string code is the letters and number from Events.txt
    //string itemName is name of the item we will be searching for in the inventory to find the price
    string code, itemName, shopperFirstName, shopperLastName;
    //totalItems is the number of unique items the shopper will be adding to their cart
    int totalItems, quantity; //quantity is the # of duplicates of the item
    while (file2 >> code){//loop through whole file and take in the first code letter S or P
        if(code=="S"){//if first code is S
            //we keep track of each shopper's shopping cart
            cout << "NEXT SHOPPER! What is your first and last name? " << endl;
            cin >> shopperFirstName >> shopperLastName;
            Shopper shopperName(shopperFirstName,shopperLastName);//CREATE UNIQUE SHOPPER OBJECT
            file2 >> totalItems; //take in next code which is the total # of items the shopper has
            cout << "# of items: " << totalItems << endl;
            for(int i=0;i<totalItems;i++){ //now we loop through all the items
                file2 >> itemName; //take in the item name
                cout << "ITEM: " << itemName << endl;
                file2 >> quantity; //take # of those items being bought
                cout << "QUANTITY: " << quantity << endl;

                //WE LOOK THROUGH THE HARDWARE STORE'S INVENTORY TO SEE IF IT IS IN THE STORE
                //AND WITH THE FUNCTION checkPrice WE RETURN THE
                //PRICE OF THAT SPECIFC ITEM WE READ FROM THE EVENTS FILE
                price = store.inventory.checkPrice(itemName) * quantity; //MULTIPLY BY QUANTITY
                cout << "PRICE: " << price << endl << endl;
                Item object(itemName,price);//CREATE THAT ITEM OBJECT FOR THE SHOPPER
                shopperName.addItemToCart(object); //AND PUT IT IN THEIR SPECIFIC SHOPPING CART

            }
            cout << "Your total is: " << shopperName.amountOwed() << endl; //plus tax
            store.addShopperToLine(shopperName);//ADD THIS SHOPPER WITH ITS COMPLETE CART TO THE HARDWARE STORE SHORTEST QUEUE
            cout << "-------------------" << endl << endl;
        }
        else if(code=="P"){//look for S or P
            cout << "Time to process" << endl;
            store.checkoutAllShoppers();

        }
        //revenue+=store.totalRevenue();//HOW MUCH THE STORE
        cout << "Your revenue: " << store.totalRevenue() << endl;//CALCULATE ALL THE SHOPPERS' grandTotal AND POP THEM OFF THE QUEUE
    }
    file2.close();
//if an item has two words in the name the program is a mess
//txt file templates must be exact
}
