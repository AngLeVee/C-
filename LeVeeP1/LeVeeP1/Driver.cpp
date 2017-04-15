/**************************************
*Program: LeVeeP1
*Programmer: Angela LeVee (alevee@cnm.edu)
*Date: 20140910
*Purpose: Calculate and display information about an order of water bottles.
**************************************/

#include <iostream>
#include <iomanip> //for setprecision to properly display results
using namespace std;

int main()
{
	//Declare conversions
	const float LiterToGallon = 3.785f; //conversion rate to divide by
	const float GallonToPound = 8.33f;  //conversion to multiply by
	const int   OunceToPound  = 16;     //conversion to divide by
	//Declare constants
	const int Pallet1Liter     = 2;
	const int PalletHalfLiter  = 4;
	const int CasesPerPallet   = 80;
	const int BottlePerCase    = 24;
	const float OunceOfBottle  = 0.5;
	//Declare variables to use
	int Cases1Liter;
	int CasesHalfLiter;
	int Servings1Liter;
	int ServingsHalfLiter;
	int TotalLiters;
	float USGallons;
	float PoundsOfWater;
	int   PoundsOfBottles;
	float TotalPounds;

	//Course header
	cout<< "Name: Angela LeVee"<< endl<< "Program: LeVeeP1"<< endl
		<< "Objective: Calculate and display information about an order of water bottles."<< endl<< endl;

	//Start calculations
	Cases1Liter       = Pallet1Liter * CasesPerPallet;
	CasesHalfLiter    = PalletHalfLiter * CasesPerPallet;
	Servings1Liter    = Cases1Liter * BottlePerCase;
	ServingsHalfLiter = CasesHalfLiter * BottlePerCase;
	TotalLiters       = Servings1Liter + (ServingsHalfLiter / 2);
	USGallons         = TotalLiters / LiterToGallon;
	PoundsOfWater     = USGallons * GallonToPound;            
	PoundsOfBottles   = (Servings1Liter + ServingsHalfLiter) * OunceOfBottle / OunceToPound;
	TotalPounds       = PoundsOfBottles + PoundsOfWater;

	//Display Liter type specific info
	cout<< setw (27)<< "One Liter Bottles"<< setw (27)<< "Half Liter Bottles"<< endl;
	cout<< "Cases"<< setw (14)<< Cases1Liter<< setw (27)<< CasesHalfLiter<< endl;
	cout<< "Servings"<< setw (11)<< Servings1Liter<< setw (27)<< ServingsHalfLiter
		<< endl<< endl<< endl;

	//Display Totals information
	cout<< setw (20)<< "Liters"<< setw (29)<< "US Gallons"<< setw (23)<< "Weight"<< endl;
	cout<< "Totals"<< setw (13)<< TotalLiters<< setprecision (3)<< fixed<< setw (29)<< USGallons
		<< setw (25)<< TotalPounds<< " lbs"<< endl<< endl<< endl;

	cout << "Press any key to exit... ";
	getchar();

	return 0; //execution ok
}