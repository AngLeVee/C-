/**************************************
*File: Functions.cpp
*Programmer: Angela LeVee (alevee@cnm.edu)
*Date: 20141027
*Purpose: Define functions.
**************************************/

#include <iostream>
#include <string>
using namespace std;

void Header () //Course Header
{
	cout<< "Name: Angela LeVee"<< endl<< "Program: LeVeeP4"<< endl;
	cout<< "Objective: Display safe combination made from user given 8 letter phrase."<< endl;
}

string askForPhrase() //Ask for input phrase for code
{
	string characts = "";
	cout<< endl<< "Please enter an 8 letter phrase, only letters, no spaces: ";
	getline(cin,characts);
	return characts;
}
bool validatePhrase(string input, string &desc) //Validate phrase (length, no spaces, digits, or special chars)
{
	//create string used for validation
	string Alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	//Validate length
	if (input.length()>8)
	{
		desc = "Your phrase has too many characters.";
		return false;
	}
	else if (input.length()<8)
	{
		desc = "Your phrase has too few characters.";
		return false;
	}

	//Validate for digits or special characters
	else if (input.find(",")<=8)
	{
		desc = "Your phrase includes a special character.";
		return false;
	}
	else if (input.find(" ")<=8)
	{
		desc = "Your phrase includes a space.";
		return false;
	}
	else if (input.find_first_of("1234567890") <= 8)
	{
		desc = "Your phrase includes a digit.";
		return false;
	}
	else if (input.find_first_not_of(Alph) <= 8)
	{
		desc = "Your phrase includes a special character.";
		return false;
	}
	else //If nothing is wrong
	{
		desc = "Your phrase is valid";
		return true;
	}
}
int twoCharsToInt(char a, char b) //Convert chars into combination #s
{
	//Initialize ints for temp code #s
	int A = 0;
	int B = 0;

	//Convert first char into code number
	if (a=='a' || a=='A' || a=='B' || a=='b' || a=='C' || a=='c')
	{
		A = 20;
	}
	else if(a=='D' || a=='d' || a=='E' || a=='e' || a=='F' || a=='f')
	{
		A = 30;
	}
	else if (a=='G' || a=='g' || a=='H' || a=='h' || a=='I' || a=='i')
	{
		A = 40;
	}
	else if (a=='J' || a=='j' || a=='K' || a=='k' || a=='L' || a=='l')
	{
		A = 50;
	}
	else if (a=='M' || a=='m' || a=='N' || a=='n' || a=='O' || a=='o')
	{
		A = 60;
	}
	else if (a=='P' || a=='p' || a=='Q' || a=='q' || a=='R' || a=='r' || a=='S' || a=='s')
	{
		A = 70;
	}
	else if (a=='T' || a=='t' || a=='U' || a=='u' || a=='V' || a=='v')
	{
		A = 80;
	}
	else if (a=='W' || a=='w' || a=='X' || a=='x' || a=='Y' || a=='y' || a=='Z' || a=='z')
	{
		A = 90;
	}


	//Convert second char into code number
	if (b=='a' || b=='A' || b=='B' || b=='b' || b=='C' || b=='c')
	{
		B = 2;
	}
	else if (b=='D' || b=='d' || b=='E' || b=='e' || b=='F' || b=='f')
	{
		B = 3;
	}
	else if (b=='G' || b=='g' || b=='H' || b=='h' || b=='I' || b=='i')
	{
		B = 4;
	}
	else if (b=='J' || b=='j' || b=='K' || b=='k' || b=='L' || b=='l')
	{
		B = 5;
	}
	else if (b=='M' || b=='m' || b=='N' || b=='n' || b=='O' || b=='o')
	{
		B = 6;
	}
	else if (b=='P' || b=='p' || b=='Q' || b=='q' || b=='R' || b=='r' || b=='S' || b=='s')
	{
		B = 7;
	}
	else if (b=='T' || b=='t' || b=='U' || b=='u' || b=='V' || b=='v')
	{
		B = 8;
	}
	else if (b=='W' || b=='w' || b=='X' || b=='x' || b=='Y' || b=='y' || b=='Z' || b=='z')
	{
		B = 9;
	}

	//return result
	int AB = A+B;
	return AB;
}
void createCombo(string input, int *pOne, int *pTwo, int *pThree, int *pFour) //Call twoCharsToInt
{
	*pOne = twoCharsToInt (input.at(0), input.at(1));
	*pTwo = twoCharsToInt (input.at(2), input.at(3));
	*pThree = twoCharsToInt (input.at(4), input.at(5));
	*pFour = twoCharsToInt (input.at(6), input.at (7));
}
bool validateCombo(int one, int two, int three, int four, string &desc) //Validate end combination (within digit tolerance, no repeats)
{
	//Pre-subtract before validation
	int Min12 = abs(one-two),
		Min13 = abs(one-three),
		Min14 = abs(one-four),
		Min23 = abs(two-three),
		Min24 = abs(two-four),
		Min34 = abs(three-four);

	//Validate number combinations
	if (Min12>4 && Min13>4 && Min14>4 && Min23>4 && Min24>4 && Min34>4 
		&& one!=two && one!=three && one!=four && two!=three && two!=four && three!=four) //All correct
	{
		desc = "Your safe combination is valid.";
		return true;
	}
	else if (Min12<=4 || Min13<=4 || Min14<=4 || Min23<=4 || Min24<=4 || Min34<=4 
		&& one!=two && one!=three && one!=four && two!=three && two!=four && three!=four) //Digit Tolerance
	{
		desc = "Some numbers are too close together.";
		return false;
	}
	else //Repeated values
	{
		desc = "Some number combinations are repeated.";
		return false;
	}
}