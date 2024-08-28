/*
	Rafiq, Omar

	CS A250
	Project (Part A)
*/

#include "Cookie.h"

#include <iostream>
using namespace std;

string Cookie::getName() const
{
	return name;
}

size_t Cookie::getCalories() const
{
	return calories;
}

size_t Cookie::getServings() const
{
	return servings;
}

std::set<std::string> Cookie::getIngredients() const
{
	return ingredients;
}

Cookie Cookie::getCookie() const
{
	return *this; 
}

void Cookie::setName(const std::string& newName)
{
	name = newName;
}

void Cookie::setCalories(size_t newCalories)
{
	calories = newCalories;
}

void Cookie::setServings(size_t newServings)
{
	servings = newServings;
}

void Cookie::setIngredients(const std::vector<std::string>& newIngredients)
{
	if (ingredients.size() > 0)
	{
		ingredients.clear();
	}
	for (auto &elem : newIngredients)
	{
		ingredients.insert(elem);
	}
}

void Cookie::printRecipe() const
{
	cout << "    Recipe for " << name << "\n"
		<< "        Servings: " << servings << "\n"
		<< "        Ingredients: ";
	printIngredients();
}

void Cookie::printIngredients() const
{
	auto iter = ingredients.begin();
	auto iterEnd = ingredients.end();
	cout << *iter++;
	
	while (iter != iterEnd)
	{
		cout << ", " << *iter;
		iter++;
	}
	cout << endl;
}

void Cookie::printCalories() const
{
	cout << "    " << name << " " << "(calories: " 
		<< calories << ")" << endl;
}