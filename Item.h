#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Item{
	public:
	    Item(const string& name, double price);
	    Item();
		string getName() const;//this is const because it is a read-only function and to overload the ITEM object the compiler needs to know this is safe to use
		double getPrice() const;//"same as getName"
		friend ostream& operator<< (ostream& os, const Item& item);

	private:
		string itemName;
		double itemPrice;
};

//inline is used to create the functions in the same file as its header file
inline Item::Item():itemName("empty"),itemPrice(0.0){}//default values

//the item name and priicethat is passed in i
inline Item::Item(const string& name, double price){
	itemName = name;
	itemPrice = price;
}


inline string Item::getName() const{
	return itemName;
}


inline double Item::getPrice() const{
	return itemPrice;
}


inline ostream& operator<< (ostream& os, const Item& item){
	os << item.itemName << " - $" << item.itemPrice;
	return os;
}
#endif // ITEM_H

