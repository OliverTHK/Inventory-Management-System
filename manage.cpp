/*
 * manage.cpp
 *
 *  Created on: Feb 8, 2016
 *      Author: Taylor Hoss, X432Z869
 *  Assignment: 1
 *
 *  Description: C++ program that includes a class named Product to be used for an inventory management system
 *               The program has a item ID, name, category, and stock all of which can be accessed, but only
 *               the name and category can be changed directly, and the stock changed indirectly via the
 *               ship and receive functions. The class has checks to make sure the stock is never less than
 *               0. The management interface uses these commands to showcase some uses of the Product class.
 *
 */

#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_

#include "product.hpp"

#endif /* PRODUCT_HPP_ */

#ifndef STRING_
#define STRING_

#include <string>

#endif /* STRING_ */

#ifndef IOSTREAM_
#define IOSTREAM_

#include <iostream>

#endif /* IOSTREAM_ */

//prints out the information within the object
void product_info(Product p);

int main(void)
{
	//boolean used to check pass/fail status of functions called
	bool done;

	/*
	* AUTOMATICALLY-ALLOCATED CLASS OBJECT
	*/

	//creating auto-allocated product
	Product prod1(1, "Apple", PERISHABLE);

	//output current status of product after creation
	std::cout<<"Automatically-allocated Product Created:\n";
	product_info(prod1);

	//changing name, if fails output error
	done = prod1.set_name("Canned Beans");
	if (!done)
		std::cout<<"ERROR: Couldn't change name\n";

	//changing category, if fails output error
	done = prod1.set_category(NONPERISHABLE);
	if (!done)
		std::cout<<"Error: Couldn't change category\n";

	//output current status of product after name and category change
	std::cout<<"Product name and category changed:\n";
	product_info(prod1);

	//receiving stock
	done = prod1.receive(500);
	if (!done)
		std::cout<<"Error: Couldn't add stock\n";

	//output current status of product after receiving stock
	std::cout<<"Stock received:\n";
	product_info(prod1);

	//shipping stock
	done = prod1.ship(300);
	if (!done)
		std::cout<<"Error: Not enough product to ship\n";

	//output current status of product after shipping stock
	std::cout<<"Stock shipped:\n";
	product_info(prod1);

	//testing an invalid shipment
	std::cout<<"Testing an invalid shipment...\n";
	done = prod1.ship(1200);
	if (!done)
		std::cout<<"Error: Not enough product to ship\n";

	//output current status of product after failing to ship stock
	std::cout<<"\nAfter stock failing to ship:\n";
	product_info(prod1);

	/*
	* DYNAMICALLY ALLOCATED CLASS OBJECT
	*/

	//creating dynamically-allocated product
	Product *ptr_prod2 = new Product(2, "Orange", PERISHABLE);

	//output current status of product after creation
	std::cout<<"Dynamically-allocated product Created:\n";
	product_info(*ptr_prod2);

	//changing name, if fails output error
	done = ptr_prod2->set_name("Chicken Noodle Soup");
	if (!done)
		std::cout<<"ERROR: Couldn't change name\n";

	//changing category, if fails output error
	done = ptr_prod2->set_category(NONPERISHABLE);
	if (!done)
		std::cout<<"Error: Couldn't change category\n";

	//output current status of product after name and category change
	std::cout<<"Product name and category changed:\n";
	product_info(*ptr_prod2);

	//receiving stock
	done = ptr_prod2->receive(678);
	if (!done)
		std::cout<<"Error: Couldn't add stock\n";

	//output current status of product after receiving stock
	std::cout<<"Stock received:\n";
	product_info(*ptr_prod2);

	//shipping stock
	done = ptr_prod2->ship(249);
	if (!done)
		std::cout<<"Error: Not enough product to ship\n";

	//output current status of product after shipping stock
	std::cout<<"Stock shipped:\n";
	product_info(*ptr_prod2);

	//testing an invalid shipment
	std::cout<<"Testing an invalid shipment...\n";
	done = ptr_prod2->ship(20000);
	if (!done)
		std::cout<<"Error: Not enough product to ship\n";

	//output current status of product after failing to ship stock
	std::cout<<"\nAfter stock failing to ship:\n";
	product_info(*ptr_prod2);

	//deleting dynamically-allocated memory
	delete ptr_prod2;

	//end program
	return 0;
}

//prints out the information within the object
void product_info(Product p)
{
	std::cout<<"Product ID: "<<p.product_id()<<", Name: "<<p.product_name()<<", Category: ";

	//using text strings in place of numerical enum categories
	if(p.category() == 0)
		std::cout<<"PERISHABLE\n";
	else
		std::cout<<"NONPERISHABLE\n";

	std::cout<<"Number in stock: "<<p.num_in_stock()<<"\n\n";
}
