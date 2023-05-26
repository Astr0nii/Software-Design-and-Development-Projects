#include <iostream>
using namespace std;

int main() {
	float annualSalary;

	cout << "Please enter your yearly salary: ";
	cin >> annualSalary;

	float monthlySalary = annualSalary / 12;
	float dailySalary = annualSalary / 365;

	cout << "Your monthly salary is " << monthlySalary << endl
		<< "Therefore your daily salary is " << dailySalary <<endl
		<< "In 10 years you'll earn " << annualSalary*10;

	system("pause>0");
}
