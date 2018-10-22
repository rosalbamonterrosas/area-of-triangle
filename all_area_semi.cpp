/************************************************************************************************************************

Name: Rosalba Monterrosas             Z#: 23361820
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 09/20/2018           Due Time: 11:59pm
Total Points: 100
Assignment #4: all_area_semi.cpp

Description:
This program is a calculator that determines the area and semiperimter of a triangle with side lengths of a, b, c.
The user can continue calculating the areas and semiperimeters as many times as they would like. If the user enters
invalid lengths, the calculator lets the user know by printing a message stating that the lengths are invalid, and 
then prompts the user if he/she would like to continue computing area and semiperimeters. The output is printed out 
on the screen after each calculation.
*************************************************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void Banner();
void Input(double & a, double & b, double & c);
int Validate(double a, double b, double c);
void Compute(double a, double b, double c, double & area, double & semiperimeter);
void Output(double area, double semiperimeter);
void Repeat(char & user_response);


///*************************************************************************************
//Name:  Banner
//Precondition: There is no banner at the start of the program.
//Postcondition: There is a banner at the start of the program.
//Description:  Print out a banner at the start of the program.
//*************************************************************************************

void Banner() {
	cout << "Welcome to the Calculator of the Area and Semiperimeter of a Triangle!\n";
	cout << "**********************************************************************\n";
}

///*************************************************************************************
//Name: Validate
//Precondition: The variables (double & a, double & b, double & c) have been initialized.
//Postcondition: Return 1 if the values of the variables (double & a, double & b, double & c) are valid.
//Return 0 if the values of the variables (double & a, double & b, double & c) are not valid.
//Description: Determines whether the lengths of the sides are able to form a triangle.
//*************************************************************************************

int Validate(double a, double b, double c) {
	if ((a + b) > c && (a + c) > b && (b + c) > a)
		return 1;
	else
		return 0;
}

///*************************************************************************************
//Name:  Repeat
//Precondition: The variable user_response has not been initialized by the user.
//Postcondition: The variable user_response has been initialized by the user.
//Description:  Ask user if they would like to continue computing areas and semiperimeters 
//and store the response in the variable char & user_response.
//*************************************************************************************

void Repeat(char & user_response)
{
	cout << "\nWould you like to do continue computing areas and semiperimeters?\n";
	cin >> user_response;
	if ((user_response == 'n') || (user_response == 'N')) {
		cout << "\nYou have exited the calculator.\n"
			<< "Thank you for using the Calculator of the Area and Perimeter of a Triangle!\n\n";
		exit(0);
	}
}

///*************************************************************************************
//Name:  Input
//Precondition: The variables (double & a, double & b, double & c) have not been initialized.
//Postcondition: The variables (double & a, double & b, double & c) have been initialized.
//Description: Get input (values of double & a, double & b, double & c) from the user. If 
//the values of the variables are invlaid, the user has the option to try again.
//*************************************************************************************

void Input(double & a, double & b, double & c) {
	int val = 0;
	char user_response = 'y';

	while ((val == 0) && (user_response == 'y' || user_response == 'Y')) {
		do {
			cout << "\nPlease enter the length of side a.\n";
			cin >> a;
			if (a <= 0) {
				cout << "\nYou entered an incorrect value. Please try again.\n";
			}
		} while (a <= 0);

		do {
			cout << "\nPlease enter the length of side b.\n";
			cin >> b;
			if (b <= 0) {
				cout << "\nYou entered an incorrect value. Please try again.\n";
			}
		} while (b <= 0);


		do {
			cout << "\nPlease enter the length of side c.\n";
			cin >> c;
			if (c <= 0) {
				cout << "\nYou entered an incorrect value. Please try again.\n";
			}
		} while (c <= 0);

		val = Validate(a, b, c);
		if (val == 0) {
			cout << "\nThe lengths are invlaid.";
			Repeat(user_response);
		}
		
	}
}

///*************************************************************************************
//Name: Compute
//Precondition: The variables (double & a, double & b, double & c) have been initialized.
//The variables (double & area, double & semiperimeter) have not been initialized.
//Postcondition: The variables (double & area, double & semiperimeter) have been initialized.
//Description:  Compute the semiperimeter and area of a triangle using the variables 
//(double & a, double & b, double & c).
//*************************************************************************************

void Compute(double a, double b, double c, double & area, double & semiperimeter) {
	double s;

	s = (a + b + c) / 2.0;
	semiperimeter = s;
	
	area = sqrt(s*(s-a)*(s-b)*(s-c));
}

///*************************************************************************************
//Name:  Output
//Precondition: The variables (double area, double semiperimeter) 
//have been initialized.
//Postcondition: The variables (double area, double semiperimeter)
//have been printed out.
//Description:  Print output (values of double area, double semiperimeter) to the user.
//*************************************************************************************

void Output(double area, double semiperimeter) {
	cout.setf(ios::fixed); 
	cout.setf(ios::showpoint); 
	cout.precision(2);

	cout << "\nArea:\t\t" << area << endl;
	cout << "Seimperimeter:\t" << semiperimeter << endl;
}


//Driver to test the program

int main() {
	double a, b, c, area, semiperimeter;
	char user_response = 'y';
	
	Banner();

	while (user_response == 'y' || user_response == 'Y') {
		Input(a, b, c);
		Compute(a, b, c, area, semiperimeter);
		Output(area, semiperimeter);
		Repeat(user_response);
	}

	return 0;
}