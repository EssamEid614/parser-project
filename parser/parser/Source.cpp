#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
using namespace std;


void main()
{
	string reservedWords[8] = { "if", "then","else","end","repeat","until","read","write" };
	string test;
	ifstream inputFile ("InputCode.txt");
	int numberOfLines = 0;
	//find out how many lines inside file
	while (getline(inputFile, test))
	{
		numberOfLines++;
	}
	inputFile.close();
	string *lineOfCode = new string[numberOfLines]; 
	//read data inside the array with each line in a seprate element of the array
	inputFile.open("InputCode.txt");
	int i = 0;
	string testString;
	while (getline(inputFile, lineOfCode[i]))
	{
		i++;
	}
	i = 0;
	int pos=0;
	while (i <= numberOfLines)
	{
		begin:
		pos = 0;
		if(isalnum(lineOfCode[i][0]))
		{
			while (isalnum(lineOfCode[i][pos]))
			{
				pos++;
			}
			//string erasing the part that we want to test on is taken out
			testString = lineOfCode[i].substr(0, pos);
			lineOfCode[i].erase(0, pos+1);
			
			for (int j = 0; j < 8; j++)
			{
				if (testString == reservedWords[j])
				{
					cout << testString << "    " << "Reserved Word";
					goto begin;
				}
			}
			//not a reserver worder > either an identifier or a number
			//check if it is starts with a number then its a number otherwise its an identifier
			if (isdigit(testString[0]))
			{
				cout << testString << "     " << "number";
			}
			else
			{
				cout << testString << "     " << "identifier";
			}
		}
		i++;
	}
}