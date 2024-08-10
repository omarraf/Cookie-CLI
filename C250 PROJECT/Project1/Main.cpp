/*
	Rafiq, Omar

	CS A250
	Project (Part A, B)
*/

#include "Cookie.h"
#include "CookieList.h"
#include "CookieDB.h"
#include "Testing.h"
#include "Interface.h"
#include <iostream>
using namespace std;

int main()
{
	CookieList myList;
	createCookieList(myList);
	displayMenu();
	processChoice(myList);
	
	cout << endl;

	system("Pause");
	return 0;
}