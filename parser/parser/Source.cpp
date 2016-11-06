#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void main()
{
	string test;
	ifstream inputFile ("InputCode.txt");
	int numberOfLines = 0;
	//find out how many lines inside file
	if (inputFile.is_open())
	{
		cout << "file opened";
	}
	while (getline(inputFile, test))
	{
		numberOfLines++;
	}
	inputFile.close();
	string *linesOfCode = new string[numberOfLines]; 
	//read data inside the array with each line in a seprate element of the array
	inputFile.open("InputCode.txt");
	int i = 0;
	while (getline(inputFile, linesOfCode[i]))
	{
		i++;
	}

}