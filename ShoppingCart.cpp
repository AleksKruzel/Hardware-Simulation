#include <iostream>
#include <string>
#include <vector>
#include "ShoppingCart.h"
using namespace std;

//the shopping cart has a vector of Item objects
ShoppingCart::ShoppingCart (){
	vector<Item> cart;
}

//to add to the cart we pushback to the vector
void ShoppingCart::addItem(const Item& item){
	cart.push_back(item);
}

//loop through every item in the cart and add each item's 2nd value(the price) to total
double ShoppingCart::grandTotal(){
	int total = 0;
	for(int i=0;i<cart.size();i++){
		total+=cart[i].getPrice();
	}
	return total;
}

//each shoppers cart size is returned
int ShoppingCart::numItems(){
	return cart.size();
}

//overload the << operator
ostream& operator<<(ostream& os, const ShoppingCart& sc){
        for(int i=0;i<sc.cart.size();i++){
			os <<  sc.cart[i].getName() << sc.cart[i].getPrice() << endl;
			}
	return os;
}
