//Descriptions / Learning Outcomes
//	Ask the user to enter a positive integer.
//	Read the user's input and make sure it is a positive integer. 
//	One input validation function will check for both and print the appropriate custom error message.
//	Report if that input was Perfect / Deficient or Abundant as well prime or composite.
//Practice Program
//Programmer: P. Ban
//Last Modified: November 11th, 2023

#include <iostream>
#include <string>
using namespace std;

void bannerTitle();
void bannerRepeat();

double getPos();
string PADclassification(int);
int PADcalculation(int);
bool isPrime(int);

int main() {

	system("color e1");
	system("title All function types in one program by P. Ban");
	bannerTitle();

	int userInput; 

	while (true) {
	bannerRepeat();
	userInput = getPos();

	cout << "\nYou gave me "<< userInput << " which is a " << PADclassification(userInput) 
		<< " " << (isPrime(userInput) ? "prime" : "composite") << " number." << endl << endl;
	cout << "\t\t****************************\n\n";
	}
	
	system("pause");
	return 0;
}

void bannerTitle() {
	cout << "\n"
		<< "\t   A program that demonstrates functions that  \n"
		<< "\t  calculate, classify, test, validate and print\n"
		<< "\t                   by P. Ban                   \n";
}

void bannerRepeat(){
	cout << "\n"
		<< "I can classify positive integers as Perfect Abandant or Deficient.\n"
		<< "I am also able to tell you if they are prime or not.              \n"
		<< "        Give me a positive integer : ";
}

double getPos() {
	double x;
	cin >> x;
	cin.ignore(1000, '\n');

	while (x < 0 || x - static_cast<int>(x) != 0) {
		while (x < 0 && x - static_cast<int>(x) != 0) {
			cout << "\t" << x << " is not a POSITIVE WHOLE number.Try again : ";
			cin >> x;
		}
		while (x < 0) {
			cout << "\t" << x << " is not a POSITIVE number.Try again : ";
			cin >> x;
		}
		while (x - static_cast<int>(x) != 0) {
			cout << "\t" << x << " is not a WHOLE number.Try again : ";
			cin >> x;
		}
	}
	return x;
}

int PADcalculation(int userInput) {
	int sum = 0;

	for (int i = 1; i < userInput - 1; i++) {  
		if (userInput % i == 0)
			sum += i;
	}

	return sum;
}

string PADclassification(int userInput) {
	int x = PADcalculation(userInput);

	if (x == userInput)
		return "perfect";
	else if (x > userInput)
		return "abundant";
	else
		return "deficent";
}

bool isPrime(int userInput) {
	for (int i = 2; i < userInput; i++) {
		if (userInput % i == 0) {
			return false;
			break;
		}
	}

	return true;
}
