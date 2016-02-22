/*
 * product.cpp
 *
 *  Created on: Feb 8, 2016
 *      Author: Taylor Hoss, X432Z869
 *  Assignment: 1
 */

#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_

#include "product.hpp"

#endif /* PRODUCT_HPP_ */

#ifndef STRING_
#define STRING_

#include <string>

#endif /* STRING_ */

//constuctor: set the 3 identifying characteristics to their input values and set the stock to 0
Product::Product( int i, std::string n, Category c) :
									m_product_id(i), m_product_name(n), m_category(c), m_num_in_stock(0)
{}

//destructor: nothing is dynamically allocated so this function does nothing
Product::~Product()
{}

//transfer of products
//receive simply adds to the count
bool Product::receive(unsigned long amount)
{
	m_num_in_stock += amount;

	return true;
}

//ship subtracts from the count unless doing so would make the number in stock negative
bool Product::ship(unsigned long amount)
{

	//if num in stock after subtracting amount to ship is less than 0 or greater than a million, error
	if( (m_num_in_stock - amount) >= 0 && (m_num_in_stock - amount) <= 1000000)
	{
		m_num_in_stock -= amount;

		return true;
	}
	else
		return false;
}

// accessors: each returns its specified value
int Product::product_id(void) const
{
	return m_product_id;
}

std::string Product::product_name(void) const
{
	return m_product_name;
}

Category Product::category(void) const
{
	return m_category;
}

unsigned long Product::num_in_stock(void) const
{
	return m_num_in_stock;
}

// mutators: changing name or category, but not id
bool Product::set_name(std::string new_name)
{
	m_product_name = new_name;

	return true;
}

bool Product::set_category(Category new_category)
{
	m_category = new_category;

	return true;
}
