/**************************************
*Program: Variable Declarations
*Programmer: Angela LeVee (alevee@cnm.edu)
*Date: 20140917
*Purpose: Calculate surface area of the illuminated area of selected planet.
**************************************/

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	//Course Header
	cout<< "Name: Angela LeVee"<< endl<< "Program: LeVeeP2"<< endl
		<< "Objective: Calculate surface area of the illuminated area of the selected planet"<< endl<< endl;

	//Ask user for name
	string Name;
	cout<< "What is your name?"<< endl;
	cin>> Name;

	//Declare Planets vector
	vector <string> Planets;
	Planets.push_back("Mercury");
	Planets.push_back("Mars");
	Planets.push_back("Venus");
	Planets.push_back("Saturn");
	Planets.push_back("Jupiter");
	Planets.push_back("Moon");

	//Declare Radius vector
	vector <int> Radius;
	Radius.push_back(2440);
	Radius.push_back(3397);
	Radius.push_back(6052);
	Radius.push_back(60268);
	Radius.push_back(71492);
	Radius.push_back(1738);

	//Declare ints for use in planet menu
	int A = 1;
	int B = 0;

	//Display planet menu
	cout<< endl<< endl<< setw(10)<< "Planet"<< setw (15)<< "Radius"<< endl;
	for (int n=6; n>0; n--)
	{
	cout<< A<< ".  "<< setw(15)<< left<< Planets.at(B)<< Radius.at(B)<< " km"<<endl;
	A++;
	B++;
	}

	//Get number for planet
	short Planet;
	cout<< "Please enter number of desired planet:"<< endl;
	cin>> Planet;
	Planet--;

	//Get decimal form of percent illuminated
	float Illuminated;
	cout<< endl<< "Please enter the percentage of the face, in decimal format, that is illuminated."
		<< endl<< "(example: 100% = 1.0, 90% = 0.9):"<< endl;
	cin>> Illuminated;
	cin.ignore();

	//Calculate 2*(r^2)*Theta
	double EndResult;
	EndResult = 2*(Radius.at(Planet)*Radius.at(Planet))*(Illuminated*M_PI);

	//Output to file
	Name = Name + ".txt";
	ofstream File;
	File.open (Name);
	File<< setprecision(3)<< fixed<< EndResult<< " sq km";
	File.close();

	//Display file name and goodbye message
	cout<< endl<< endl<< "Your result can be found in "<< Name<< endl<< endl;
	cout<< "Goodbye, have a nice day!"<< endl<< endl;
	cout << "Press any key to exit...";
	getchar();

	return 0; //execution ok
}