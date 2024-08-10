/*
	Rafiq, Omar

	CS A250
	Project (Part B)
*/

#include "CookieList.h"

#include <iostream>
using namespace std;

void CookieList::addCookie(const Cookie& newCookie)
{
	Node* newNode = new Node(newCookie, nullptr);
	if (!first)
	{
		first = newNode;
	}
	else
	{
		last->setNext(newNode);
	}
	last = newNode;
	count++;
}

void CookieList::addCookie(const string& cookieName, size_t calories,
	size_t servings, const set<string>& ingredients)
{
	Cookie myCookie(cookieName, calories, servings, ingredients);
	addCookie(myCookie);
}

size_t CookieList::getCount() const
{
	return count;
}

bool CookieList::isEmpty() const
{
	return count == 0;
}

bool CookieList::searchCookie(const string& cookieName) const
{
	Node* current = first;
	while (current)
	{
		if (current->getCookie().getName() == cookieName)
		{
			return true;
		}
		current = current->getNext();
	}
	return false;
}

void CookieList::printAllCookies() const
{
	Node* current = first;
	while (current)
	{
		cout << "    " << current->getCookie().getName() << endl;
		current = current->getNext();
	}
}

void CookieList::printCookiesSelection() const
{
	Node* current = first;
	for (int i = 1; i <= count; i++)
	{
		cout << "    " << i << ": " << current->getCookie().getName()
			<< endl;
		current = current->getNext();
	}
	cout << endl;
}

void CookieList::printRecipe(size_t cookieSelection)
{
	getCookieLocation(cookieSelection)->getCookie().printRecipe();
}

void CookieList::printCalories(size_t cookieSelection)
{
	getCookieLocation(cookieSelection)->getCookie().printCalories();
}

void CookieList::printLimitedCalories(size_t maxNumOfCals)
{
	Node* current = first;
	while (current)
	{
		if (current->getCookie().getCalories() <= maxNumOfCals)
		{
			current->getCookie().printCalories();
		}
		current = current->getNext();
	}
}

void CookieList::printRandomCookie(size_t number)
{
	size_t multiplier = 16807;
	size_t constant = 12345;
	size_t modulus = 2147483647;

	number = (multiplier * number + constant) % modulus;
	printRecipe((number % 12) + 1);
}

Node* CookieList::getCookieLocation(size_t cookieSelection)
{
	Node* current = first;

	for (size_t i = 1; i < cookieSelection; i++)
	{
		current = current->getNext();
	}
	return current;
}

void CookieList::clearList()
{
	Node* current = first;
	Node* trailCurrent = nullptr;
	while (current)
	{
		trailCurrent = current;
		current = current->getNext();
		delete trailCurrent;
	}
	first = nullptr;
	last = nullptr;
	count = 0;
}

CookieList::CookieList(const CookieList& otherCookieList) 
	: first(nullptr), last(nullptr), count(0)
{
	Node* current = otherCookieList.first;
	while (current)
	{
		addCookie(current->getCookie());
		current = current->getNext();
	}
}

CookieList& CookieList::operator=(const CookieList& otherCookieList)
{
	if (&otherCookieList == this)
	{
		cerr << "Attempted assignment to itself.";
	}
	else
	{
		if (count != 0)
		{
			clearList();
		}

		Node* current = otherCookieList.first;
		while (current)
		{
			addCookie(current->getCookie());
			current = current->getNext();
		}
		count = otherCookieList.count;
	}
	return *this;
}

CookieList::~CookieList()
{
	if (count > 0)
	{
		clearList();
	}
}