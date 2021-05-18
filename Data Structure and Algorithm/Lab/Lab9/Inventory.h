#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory{
	private:
		char itemName[20];
		char itemKod[20];
		float itemPrice;
		int qttyInStock;
		float totalEarned;
		
	public:
		Inventory();
		void getData();
		void buy(int);
		void addStock();
		void discountPrice(int);
		void printDetail();
		~Inventory(){};
};

#endif
