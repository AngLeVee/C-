/**************************************
*File: Functions.h
*Programmer: Angela LeVee (alevee@cnm.edu)
*Date: 20141027
*Purpose: List function prototypes.
**************************************/

#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H
#include <iostream>
#include <string>
using namespace std;

void     Header ();                                                                //Course Header
string   askForPhrase();                                                           //Ask for input phrase for code
bool     validatePhrase(string input, string &desc);                               //Validate phrase (length, no spaces, digits, or special chars)
int      twoCharsToInt(char a, char b);                                            //Convert chars into combination #s
void     createCombo(string input, int *pOne, int *pTwo, int *pThree, int *pFour); //Call twoCharsToInt
bool     validateCombo(int one, int two, int three, int four, string &desc);       //Validate end combination (within digit tolerance, no repeats)

#endif;