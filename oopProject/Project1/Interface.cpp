/*
	Rafiq, Omar

	CS A250
	Project (Part C, D)

	1. SELECTION NAME: Print random cookie recipe
	2. This selection will ask the user to choose a random number
	then print a random cookie recipe for the user. It will print 
	the servings and ingredients for a random cookie for users who
	are unsure of what cookie to choose. 
	3. EXPECTED OUTPUT:
--------------------------------------------------------------
    RANDOM COOKIE
--------------------------------------------------------------

Choose a random number: 2

Your random recipe is...

    Recipe for Snickerdoodles
	    Servings: 36
		Ingredients: butter, cinnamon, cream of tartar, flour, sugar
	
	4. TEST CASES:
			Choose a random number: 21 (first) 
			Choose a random number: 20  (middle)
			Choose a random number: 2 (last)
*/

#include "Interface.h"


#include <iostream>
#include <string>


using namespace std;

// Definition function displayMenu
void displayMenu()
{
	cout << "**************************************************************"
		<< "\n                      COOKIE RECIPES"
		<< "\n**************************************************************" << endl
		<< "\nSelect one of the following:" << endl
		<< "\n    a. Print all recipes"
		<< "\n    b. Print cookie recipe"
		<< "\n    c. Print cookie calories"
		<< "\n    d. Print limited calories"
		<< "\n    e. Print random cookie recipe"
		<< "\n    f. To exit" << endl;
}


// Definition function processChoice
void processChoice(CookieList& cookieList)
{
	// Your code here...
	
	char userInput = 'a';
	char yesOrNo = 'y';
	size_t userChoice = 0;
	while (userInput != 'f' && yesOrNo != 'n')
	{
		cout << "\nEnter your choice: ";
		cin >> userInput;
		cout << endl;

		switch (userInput) {
			case 'a':
				cout << "--------------------------------------------------------------" << endl
					<< "    COOKIE RECIPES" << endl
					<< "--------------------------------------------------------------" << endl;
				cout << endl;
				cookieList.printAllCookies();
				cout << "\n==============================================================" << endl
					<< "\nWould you like to continue (y/n)? ";
				cin >> yesOrNo;
				if (yesOrNo == 'y')
				{
					cout << endl;
					displayMenu();
				}
				else
				{
					cout << "\nThank you for using our software. Good bye!";
					userInput = 'f';
					break;
				}

				break;
			case 'b':
				cout << "--------------------------------------------------------------" << endl
					<< "    COOKIE RECIPE" << endl
					<< "--------------------------------------------------------------" << endl
					<< "\nChoose a cookie to view the recipe." << endl;
				cout << endl; 
				cookieList.printCookiesSelection();

				cout << "Your choice: ";
				cin >> userChoice; 
				cout << endl;

				cookieList.printRecipe(userChoice);

				cout << "\n==============================================================" << endl
					<< "\nWould you like to continue (y/n)? ";

				cin >> yesOrNo;

				if (yesOrNo == 'y')
				{
					cout << endl;
					displayMenu();
				}
				else
				{
					cout << "\nThank you for using our software. Good bye!";
					userInput = 'f';
					break;
				}
				break;

			case 'c':
				cout << "--------------------------------------------------------------" << endl
					<< "    COOKIE CALORIES" << endl
					<< "--------------------------------------------------------------" << endl
					<< "\nChoose a cookie # to view number of calories." << endl;

				cout << endl;
				cookieList.printCookiesSelection();
				cout << "Your choice: ";
				cin >> userChoice;
				cout << endl;
				cookieList.printCalories(userChoice);

				cout << "\n==============================================================" << endl
					<< "\nWould you like to continue (y/n)? ";
				cin >> yesOrNo;
				if (yesOrNo == 'y')
				{
					cout << endl;
					displayMenu();
				}
				else
				{
					cout << "\nThank you for using our software. Good bye!";
					userInput = 'f';
					break;
				}
				
				break;

			case 'd':
				cout << "--------------------------------------------------------------" << endl
					<< "    MAXIMUM CALORIES" << endl
					<< "--------------------------------------------------------------" << endl
					<< "\nWhat is the maximum # of calories (100-200)? ";
				cin >> userChoice;
				cout << endl;

				cookieList.printLimitedCalories(userChoice);

				cout << "\n==============================================================" << endl
					<< "\nWould you like to continue (y/n)? ";

				cin >> yesOrNo;

				if (yesOrNo == 'y')
				{
					cout << endl;
					displayMenu();
				}
				else
				{
					cout << "\nThank you for using our software. Good bye!";
					userInput = 'f';
					break;
				}
				break;
			case 'e':
				cout << "--------------------------------------------------------------" << endl
					<< "    RANDOM COOKIE" << endl
					<< "--------------------------------------------------------------" << endl
					<< "\nChoose a random number: ";

				cin >> userChoice;
				
				cout << "\nYour random recipe is..." << endl;
				cout << endl;
				cookieList.printRandomCookie(userChoice);

				cout << "\n==============================================================" << endl
					<< "\nWould you like to continue (y/n)? ";

				cin >> yesOrNo;
				if (yesOrNo == 'y')
				{
					cout << endl;
					displayMenu();
				}
				else
				{
					cout << "\nThank you for using our software. Good bye!";
					userInput = 'f';
					break;
				}
				break;
			case 'f':
				cout << "Thank you for using our software. Good bye!";
				break;
			default:
				cout << "  => Sorry. That is not a selection." << endl
					<< "\n==============================================================" << endl
					<< "\nWould you like to try again (y/n)? ";

				cin >> yesOrNo;

				if (yesOrNo == 'y')
				{
					cout << endl;
					displayMenu();
				}
				else
				{
					cout << "\nThank you for using our software. Good bye!";
					userInput = 'f';
					break;
				}
		}
	}

}
