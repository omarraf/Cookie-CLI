/*
	Rafiq, Omar

	CS A250
	Project (Part B)
*/

#ifndef COOKIELIST_H
#define COOKIELIST_H

#include "Cookie.h"

class Node
{
public:
	Node() : cookie(), next(nullptr) {}
	Node(const Cookie& newCookie, Node* newNext)
		: cookie(newCookie), next(newNext) {}
	Cookie& getCookie() { return cookie; }
	Node* getNext() const { return next; }
	void setCookie(const Cookie& newCookie) { cookie = newCookie; }
	void setNext(Node* newNext) { next = newNext; }
	~Node() {}
private:
	Cookie cookie;
	Node* next;
};

class CookieList
{
public:
	CookieList() : first(nullptr), last(nullptr), count(0) {}
	
	void addCookie(const Cookie& newCookie);
	void addCookie(const std::string& cookieName, size_t calories,
		size_t servings, const std::set<std::string>& ingredients);
	
	size_t getCount() const;

	bool isEmpty() const;
	bool searchCookie(const std::string& cookieName) const;
	
	void printAllCookies() const;
	void printCookiesSelection() const;
	void printRecipe(size_t cookieSelection);
	void printCalories(size_t cookieSelection);
	void printLimitedCalories(size_t maxNumOfCals);
	void printRandomCookie(size_t number);

	void clearList();

	CookieList(const CookieList& otherCookieList);
	CookieList& operator=(const CookieList& otherCookieList);
	~CookieList();
private:

	Node* first;
	Node* last;
	size_t count;

	Node* getCookieLocation(size_t cookieSelection);
};

#endif

