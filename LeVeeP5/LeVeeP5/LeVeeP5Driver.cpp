/**************************************
*Program: LeVeeP5
*Programmer: Angela LeVee (alevee@cnm.edu)
*Date: 20141027
*Purpose: Display safe combination made from user given 8 letter phrase.
**************************************/

#include <iostream>
#include <string>
#include "Functions.h"
using namespace std;

int main()
{
	Header ();
//Declare variables
	string Phrase = "";
	string Descrip = "";
	char YorN = ' ';
	bool Valid = true;

	//Start program
	do //outer do loop
	{
		do //inner do loop
		{
			Phrase = askForPhrase ();
			Valid = validatePhrase(Phrase,Descrip);
			if(Valid)
				{
					cout<< Descrip<< endl;
					YorN = 'N'; //Moves to next do loop
				}
			else
				{
					cout<< Descrip<< endl;
					cout<< endl<< "Would you like to try again? Y or N"<< endl;
					cin>> YorN;
					cin.ignore(); //Clear buffer for retry
					if (YorN=='n' || YorN=='N')
						{
							cout << "Goodbye" << endl;
							return 0; //Exit program
						}
				}
		}
		while (YorN=='y' || YorN=='Y');
	//Declare combo variables
	int Comb1 = 0,
		Comb2 = 0,
		Comb3 = 0,
		Comb4 = 0;

	//Creation and combo validation
	createCombo(Phrase, &Comb1, &Comb2, &Comb3, &Comb4);
	Valid = validateCombo(Comb1, Comb2, Comb3, Comb4, Descrip);

	//Display results
	cout<< endl<< Comb1<< '-'<< Comb2<< '-'<< Comb3<< '-'<< Comb4<< endl;
	if (Valid) //Valid code
	{
		cout<< Descrip<< endl<< endl;
	}
	else //Invalid code
	{
		cout<< "Your combination is invalid. "<< Descrip<< endl<< endl;
	}

	cout<< "Would you like to try again? Y or N"<< endl;
	cin>> YorN;
	cin.ignore(); //Clear buffer for retry
	} while (YorN=='y' || YorN=='Y');
	cout << endl<< "Goodbye";
	getchar();
	return 0;
}