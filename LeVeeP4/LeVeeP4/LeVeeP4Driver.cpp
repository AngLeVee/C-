/**************************************
*Program: LeVeeP4
*Programmer: Angela LeVee (alevee@cnm.edu)
*Date: 20141012
*Purpose: Calculate windchill and time to frostbite based on numbers given by the user.
**************************************/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

//Function headers
void   CourseHeader();
double AskForTemperature();
double AskForWindSpeed();
int    ValidateTempWS(double temp, double windsp);
void   TryAgain ();
double CalcWindchill(double temp, double windsp);
int    DetermineFrostbiteTimes(double temp, double windsp);

int main()
{
	//Variables
double Temp;
double WindSpeed;
int Valid = 0;
double WindChill;
int T2Frost;
	CourseHeader();
	do
	{
	do
	{
	//Get data
	Temp = AskForTemperature();
	WindSpeed = AskForWindSpeed();
	Valid = ValidateTempWS(Temp, WindSpeed);

	//use validation
	switch (Valid)
		{
		case 0:
			cout<< endl<< "Both values are invalid. ";
			TryAgain();
			break;
		case 2:
			cout<< endl<< "Wind speed was too low. ";
			TryAgain();
			break;
		case 3:
			cout<< endl<< "Temperature was too high. ";
			TryAgain();
		}
	} while (Valid!=1);

	//Calculate values
	WindChill = CalcWindchill(Temp, WindSpeed);
	T2Frost = DetermineFrostbiteTimes(Temp, WindSpeed);

	//Give results
	cout<< endl<< "While the temperature is "<< Temp<< " degrees and the wind speed is "
		<< WindSpeed<< " mph:"<< endl;
	cout<< setprecision(0)<< fixed<< "*It will feel like "<< WindChill<< " degrees and"<< endl;
	if (WindSpeed<60 && Temp>15)
	{
		cout<< "*There is no immediate threat of frostbite."<< endl;
	}
	else
	{
		cout<< "*it will take "<< T2Frost<< " minutes for frostbite to occur."<< endl<< endl;
	}
	TryAgain();
	} while (1);
	return 0;
}

//CourseHeader
void CourseHeader()
{
	cout<< "Name: Angela LeVee"<< endl<< "Program: LeVeeP4"<< endl;
	cout<< "Objective: Calculate wind chill and time to frostbite based on numbers given by the user."<< endl<< endl;
}

//function to ask for the temperature
double AskForTemperature()
{
	int temp;
	cout<< "Please enter a temperature 40 degrees Fahrenheit or below: ";
	cin>> temp;
	return temp;
}

//function to ask for the windspeed
double AskForWindSpeed()
{
	int wind;
	cout<< "Please enter a wind speed 5 mph or above: ";
	cin>> wind;
	return wind;
}

//Function to validate the data
int ValidateTempWS(double temp, double windsp)
{
	if (temp>40 && windsp<5)
	{
		return 0;
	}
	else if (temp<=40 && windsp>=5)
	{
		return 1;
	}
	else if (temp<=40 && windsp<5)
	{
		return 2;
	}
	else if (temp>40 && windsp>=5)
	{
		return 3;
	}
	return 0;
}

//Function to try entering values again
void TryAgain ()
{
	char YorN;
	cout<< "Would you like to try again? Y or N"<< endl;
	cin>> YorN;
	if (YorN!='Y' && YorN!='y')
	{
		cout<< endl<< "Thank you, good bye!"<< endl<< endl;
		cin.ignore();
		cout << "Press any key to exit...";
		getchar();
		exit (0);
	}
	cout<< endl;
}

//Function to calculate wind chill
double CalcWindchill(double temp, double windsp)
{
	double Intermed1;
	double Intermed2;
	double WindPow;
	WindPow = pow (windsp, .16);
	Intermed1 = 0.6215 * temp + 35.74;
	Intermed2 = 35.75 * WindPow;
	Intermed2 = Intermed1 - Intermed2;
	return (0.4275*temp)*WindPow + Intermed2;
	}

//Function to calculate time to frostbite
int  DetermineFrostbiteTimes(double temp, double windsp)
{
	double Intermed1;
	double Intermed2;
	Intermed1 = (((windsp*8)/5)*0.667 + 4.8)*-24.5 + 2111;
	Intermed2 = ((temp - 32)*5)/9;
	Intermed2 = -4.8 - Intermed2;
	Intermed2 = pow(Intermed2, -1.668);
	return (Intermed1*Intermed2)+0.5; //Add 0.5 for rounding
}