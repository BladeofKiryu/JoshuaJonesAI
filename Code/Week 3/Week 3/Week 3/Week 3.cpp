#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <sstream>

using namespace std;

class student

{
	string studentFName;
	string studentMName;
	string studentLName;
	double grade;
};



int main()

{

	ifstream in;

	in.open("example.txt");

	if (in.fail())

	{

		cout << "file could not be opened\n";

		system("pause");

		system("exit");

	}

	student sList[20];

	lgetData(in, sList, 6);

	lprintResult(sList, 6);

	in.close();

	system("pause");

	return 0;

}

void lgetData(ifstream& inFile, student sList[], int listSize)
{


	int n = 0;


	while (n < listSize)

	{
		string lineOfFile = "";
		getline(inFile, lineOfFile);
		istringstream iss(lineOfFile);
		if (lineOfFile != "") {
			int numWord = 1;
			do
			{
				std::string sub;
				iss >> sub;
				if (numWord == 1)
					sList[n].studentFName = sub;
				else if (numWord == 2)
					sList[n].studentMName = sub;
				else if (numWord == 3)
					sList[n].studentLName = sub;
				numWord++;

			} while (!iss.eof());


			if (numWord == 3) {
				sList[n].studentLName = sList[n].studentMName;
				sList[n].studentMName = "";
			}

			inFile >> sList[n].grade;

			n++;
		}

	}

}

int lhighestScore(const student sList[], int listSize)

{

	int high = 0, i;


	for (i = 0; i < listSize; i++)


		if (high < sList[i].grade)


			high = sList[i].grade;


	return high;

}


void lprintResult(const student sList[], int listSize)

{

	cout << left << setw(30) << "Student Name" << right << setw(10) << "TestScore" << right << setw(7) << "Grade" << endl;


	string name;

	int high, i;


	for (i = 0; i < listSize; i++)

	{


		name = sList[i].studentLName + " " + sList[i].studentMName + " " + sList[i].studentFName;


		cout << left << setw(30) << name << right << setw(10) << sList[i].grade << right << setw(7) << endl;

	}


	cout << endl;


	high = lhighestScore(sList, listSize);

	cout << "High Test Scores: " << endl;


	for (int i = 0; i < listSize; i++)


		if (sList[i].grade == high)


			cout << sList[i].studentLName << " " << sList[i].studentMName << " " << sList[i].studentFName << endl;

}