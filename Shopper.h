#ifndef SHOPPER_H
#define SHOPPER_H

#include <iostream>
#include <string>
#include "Item.h"
#include "ShoppingCart.h"

using namespace std;

class Shopper{
	public:
		Shopper(const string& firstName, const string& lastName);
		void addItemToCart(const Item& item, int numItems=1);
		double amountOwed();
		friend ostream& operator<<(ostream& os, const Shopper& shopper);
        ShoppingCart S;
	private:
        string fName;
        string lName;

};
#endif
