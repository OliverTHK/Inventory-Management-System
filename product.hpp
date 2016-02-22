/*
 * product.hpp
 *
 *  Created on: Feb 8, 2016
 *      Author: Taylor Hoss, X432Z869
 *  Assignment: 1
 */

#ifndef STRING_
#define STRING_

#include <string>

#endif /* STRING_ */

//creating enum category for perishability
enum Category { PERISHABLE, NONPERISHABLE };

class Product
{
 public:
	//constuctor: set the 3 identifying characteristics to their input values and set the stock to 0
	Product( int product_id, std::string product_name, Category category);

	//destructor: nothing is dynamically allocated so this function does nothing
	~Product();

	//transfer of products
	bool receive(unsigned long amount);
	bool ship(unsigned long amount);

	//accessors: each returns its value
	int product_id(void) const;
	std::string product_name(void) const;
	Category category(void) const;
	unsigned long num_in_stock(void) const;

	//mutators: changing name or category, but not id
	bool set_name(std::string new_name);
	bool set_category(Category new_category);

 private:
	//data members: each holds its corresponding product information
	int m_product_id;
	std::string m_product_name;
	Category m_category;
	unsigned long m_num_in_stock;
};
