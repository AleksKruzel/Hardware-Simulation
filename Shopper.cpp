#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "Shopper.h"
#include "ShoppingCart.h"
using namespace std;
//identify the shopper from the user's input
Shopper::Shopper (const string& firstName, const string& lastName){
    fName = firstName;
    lName = lastName;
}

//add an ITEM object to the shopping cart vector
void Shopper::addItemToCart(const Item& item, int numItems){
    while(numItems>0){
        S.addItem(item);
        numItems--;
    }
}
//is there a benefit to having the tax percentage in the header file as a
//private variable or should it be implemented in the cpp
double Shopper::amountOwed(){
    double sum, total;
    double tax = (S.grandTotal()*(.08875));//tax
    sum = S.grandTotal() + tax; //+tax
    total = ceil(sum * 100) / 100; //2 decimal amounts
    return total;
}

ostream& operator<<(ostream& os, const Shopper& shopper){
    os << "Name: " << shopper.fName;
    return os;
}
