#ifndef ShoppingCart_H
#define ShoppingCart_H

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class ShoppingCart{
	public:
		ShoppingCart();
		void addItem(const Item& item);
		double grandTotal();
		int numItems();
		friend ostream& operator<<(ostream& os, const ShoppingCart& sc);

	private:
		vector<Item> cart;
};
ostream& operator<<(ostream& os, const ShoppingCart& sc);

#endif // ShoppingCart_H
