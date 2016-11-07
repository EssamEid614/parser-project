#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <map>

using namespace std;
//need function here to clear spaces from string for case 2 

void main()
{
	string reservedWords[8] = { "if", "then","else","end","repeat","until","read","write" };
	map<string,string> symbols;
	symbols["+"] = "plus";
	symbols["-"] = "minus";
	symbols["*"] = "mul";
	symbols["/"] = "div";
	symbols["=="] = "equal";
	symbols["("] = "bracket";
	symbols[")"] = "bracket";
	symbols[";"] = "colon";
	symbols[":="] = "assign";
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
	while (i < numberOfLines)
	{
		begin:
		pos = 0;
		//case 1 it is an identifier or number or reserved word
		if (isalnum(lineOfCode[i][0]) && lineOfCode[i] != "")
		{
			while (isalnum(lineOfCode[i][pos]))
			{
				pos++;
			}
			//string erasing the part that we want to test on is taken out
			testString = lineOfCode[i].substr(0, pos);
			if(lineOfCode[i][pos]==' ')
			{
				lineOfCode[i].erase(0, pos + 1);
			}
			else
			{
				lineOfCode[i].erase(0, pos);
			}
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
				goto begin;
			}
			else
			{
				cout << testString << "     " << "identifier";
				goto begin;
			}
		}
		//case 2 is a symbol 
		else if(lineOfCode[i] != "")
		{
			while (!isalnum(lineOfCode[i][pos]))
			{
				pos++;
			}
			//
			testString = lineOfCode[i].substr(0, pos);
			lineOfCode[i].erase(0, pos + 1);
			map<string, string>::iterator it = symbols.find(testString.substr(0,pos));
			if (it != symbols.end())
			{		
				cout << testString << "     " << it->second;
			}
		}
		
		if(lineOfCode[i]=="")
		{
		i++;
		}
	}
}