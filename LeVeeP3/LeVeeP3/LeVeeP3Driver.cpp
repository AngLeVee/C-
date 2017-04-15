/**************************************
*Program: LeVeeP3
*Programmer: Angela LeVee (alevee@cnm.edu)
*Date: 20140930
*Purpose: Record and display votes for various opinion polls.
**************************************/

#include <iostream>
#include <iomanip>
#include <istream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	//Display class header
	cout<< "Name: Angela LeVee"<< endl<< "Program: LeVeeP3"<< endl
		<< "Objective: Record and display votes for various opinion polls."<< endl<< endl
		<< "Please choose a poll topic by number" << endl;
	
	//Declare variables
	char YorN;
	vector <string> FirstPoll(6);
	vector <string> SecondPoll(6);
	vector <string> ThirdPoll(6);
	vector <string> FourthPoll(6);
	vector <int> MenuNum;
	vector <int> PollCount(6);
	int B;
	int Total;
	int Num;
	float Percent;

	//Read from file
		ifstream Polls;
		Polls.open ("poll_topics.txt");
		for(size_t i = 0; i<FirstPoll.size(); ++i)
		{
			getline(Polls, FirstPoll.at(i));
		}
	
		//Second Poll
		for(size_t i = 0; i<SecondPoll.size(); ++i)
		{
			getline(Polls, SecondPoll.at(i));
		}
	
		//Third Poll
		for(size_t i = 0; i<ThirdPoll.size(); ++i)
		{
			getline(Polls, ThirdPoll.at(i));
		}
	
		//Fourth Poll
		for(size_t i = 0; i<FourthPoll.size(); ++i)
		{
			getline(Polls, FourthPoll.at(i));
		}
		Polls.close();

	//Prepare menu set-up
	MenuNum.push_back(1);
	MenuNum.push_back(2);
	MenuNum.push_back(3);
	MenuNum.push_back(4);
	MenuNum.push_back(5);
	
	do
	{
	//Set up menu
		cout<<"************ FAVORITE OPINION POLL ************"<< endl;
		cout<< "1. "<< FirstPoll.at(0)<<endl;
		cout<< "2. "<< SecondPoll.at(0)<<endl;
		cout<< "3. "<< ThirdPoll.at(0)<<endl;
		cout<< "4. "<< FourthPoll.at(0)<<endl<<endl;

	//Choice
		int Input;
		cin>> Input;
	//Voting
		switch(Input)
		{
		case 1: //First Poll menu
				Total = 0;
				cout<< "*******************"<< FirstPoll.at(0)<< "*******************"<< endl;
				B=0;
				for (int i=1; i<6;i++)
				{
					cout<< MenuNum.at(B)<< ". "<< FirstPoll.at(i)<< endl;
					B++;
				} 
				cout<< "6. Finish Voting"<< endl<< endl;
				cout<< "Please enter the corresponding number."<< endl<< endl;
			
				do //Selections
				{
					cout<< "-->";
					cin>> Num;
					switch (Num)
					{
					case 1:
						PollCount.at(0)++;
						Total++;
						break;
					case 2:
						PollCount.at(1)++;
						Total++;
						break;
					case 3:
						PollCount.at(2)++;
						Total++;
						break;
					case 4:
						PollCount.at(3)++;
						Total++;
						break;
					case 5:
						PollCount.at(4)++;
						Total++;
						break;
					case 6:

						break;
					default:
						cout<< "Invalid input, please try again."<< endl;
						PollCount.at(5)++;						
					}
				} while (Num!=6);
				
				// Output of results
				Percent = Total+.0;
				cout<< endl<< "*******************"<< FirstPoll.at(0)<< " POLL RESULTS *******************"<< endl;
				for (int i=1; i<6;i++)
				{
					cout<< setw(20)<< left<< FirstPoll.at(i)<< setw(20)<< left
						<< PollCount.at(i-1)<< setprecision(1)<< fixed<< PollCount.at(i-1)/Percent*100<< "%"<< endl;
				}
				cout<< "Total votes: "<< Total<< endl;
				cout<< "Invalid votes: "<< PollCount.at(5)<< endl;
				cout<< "Total votes: "<< PollCount.at(5)+Total<< endl;
			break;
		
		case 2: //SecondPoll
				Total = 0;
				cout<< "*******************"<< SecondPoll.at(0)<< "*******************"<< endl;
				B=0;
				for (int i=1; i<6;i++)
				{
					cout<< MenuNum.at(B)<< ". "<< SecondPoll.at(i)<< endl;
					B++;
				} 
				cout<< "6. Finish Voting"<< endl<< endl;
				cout<< "Please enter the corresponding number."<< endl<< endl;
				
				do //Selections
				{
					cout<< "-->";
					cin>> Num;
					switch (Num)
					{
					case 1:
						PollCount.at(0)++;
						Total++;
						break;
					case 2:
						PollCount.at(1)++;
						Total++;
						break;
					case 3:
						PollCount.at(2)++;
						Total++;
						break;
					case 4:
						PollCount.at(3)++;
						Total++;
						break;
					case 5:
						PollCount.at(4)++;
						Total++;
						break;
					case 6:

						break;
					default:
						cout<< "Invalid input, please try again."<< endl;
						PollCount.at(5)++;						
					}
				} while (Num!=6);
				
				// Output of results
				Percent = Total+.0;
				cout<< endl<< "*******************"<< SecondPoll.at(0)<< " POLL RESULTS *******************"<< endl;
				for (int i=1; i<6;i++)
				{
					cout<< setw(20)<< left<< SecondPoll.at(i)<< setw(20)<< left
						<< PollCount.at(i-1)<< setprecision(1)<< fixed<< PollCount.at(i-1)/Percent*100<< "%"<< endl;
				}
				cout<< "Total votes: "<< Total<< endl;
				cout<< "Invalid votes: "<< PollCount.at(5)<< endl;
				cout<< "Total votes: "<< PollCount.at(5)+Total<< endl;
			break;
		
		case 3:
			Total = 0;
				cout<< "*******************"<< ThirdPoll.at(0)<< "*******************"<< endl;
				B=0;
				for (int i=1; i<6;i++)
				{
					cout<< MenuNum.at(B)<< ". "<< ThirdPoll.at(i)<< endl;
					B++;
				} 
				cout<< "6. Finish Voting"<< endl<< endl;
				cout<< "Please enter the corresponding number."<< endl<< endl;
				
				do //Selections
				{
					cout<< "-->";
					cin>> Num;
					switch (Num)
					{
					case 1:
						PollCount.at(0)++;
						Total++;
						break;
					case 2:
						PollCount.at(1)++;
						Total++;
						break;
					case 3:
						PollCount.at(2)++;
						Total++;
						break;
					case 4:
						PollCount.at(3)++;
						Total++;
						break;
					case 5:
						PollCount.at(4)++;
						Total++;
						break;
					case 6:

						break;
					default:
						cout<< "Invalid input, please try again."<< endl;
						PollCount.at(5)++;						
					}
				} while (Num!=6);
				
				// Output of results
				Percent = Total+.0;
				cout<< endl<< "*******************"<< ThirdPoll.at(0)<< " POLL RESULTS *******************"<< endl;
				for (int i=1; i<6;i++)
				{
					cout<< setw(20)<< left<< ThirdPoll.at(i)<< setw(20)<< left
						<< PollCount.at(i-1)<< setprecision(1)<< fixed<< PollCount.at(i-1)/Percent*100<< "%"<< endl;
				}
				cout<< "Valid votes: "<< Total<< endl;
				cout<< "Invalid votes: "<< PollCount.at(5)<< endl;
				cout<< "Total votes: "<< PollCount.at(5)+Total<< endl;
			break;
	
		case 4:
			Total = 0;
				cout<< "*******************"<< FourthPoll.at(0)<< "*******************"<< endl;
				B=0;
				for (int i=1; i<6;i++)
				{
					cout<< MenuNum.at(B)<< ". "<< FourthPoll.at(i)<< endl;
					B++;
				} 
				cout<< "6. Finish Voting"<< endl<< endl;
				cout<< "Please enter the corresponding number."<< endl<< endl;
			
				do //Selections
				{
					cout<< "-->";
					cin>> Num;
					switch (Num)
					{
					case 1:
						PollCount.at(0)++;
						Total++;
						break;
					case 2:
						PollCount.at(1)++;
						Total++;
						break;
					case 3:
						PollCount.at(2)++;
						Total++;
						break;
					case 4:
						PollCount.at(3)++;
						Total++;
						break;
					case 5:
						PollCount.at(4)++;
						Total++;
						break;
					case 6:

						break;
					default:
						cout<< "Invalid input, please try again."<< endl;
						PollCount.at(5)++;						
					}
				} while (Num!=6);
			
				// Output of results
				Percent = Total+.0;
				cout<< endl<< "*******************"<< FourthPoll.at(0)<< " POLL RESULTS *******************"<< endl;
				for (int i=1; i<6;i++)
				{
					cout<< setw(20)<< left<< FourthPoll.at(i)<< setw(20)<< left
						<< PollCount.at(i-1)<< setprecision(1)<< fixed<< PollCount.at(i-1)/Percent*100<< "%"<< endl;
				}
				cout<< "Total votes: "<< Total<< endl;
				cout<< "Invalid votes: "<< PollCount.at(5)<< endl;
				cout<< "Total votes: "<< PollCount.at(5)+Total<< endl;
			break;
	
		default:
			cout<< "Invalid choice"<< endl;
			break;
		}
	
	//Repeat option
	cout<< endl<< "Would you like to try another poll, Y or N?"<< endl;
	cin>> YorN;
	cin.ignore();
	
	//reset PollCount vector
	for(int i=0; i<=5; i++)
	{
		PollCount.at(i) = 0;
	}
	} while (YorN=='Y'||YorN=='y');
	
	//Good bye message
	cout<< endl<< "Thank you for voting, good bye!"<< endl<< endl;
	cout << "Press any key to exit...";
	getchar();
	
return 0; //execution ok
}