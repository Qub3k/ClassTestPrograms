#include <iostream>
#include <vector>

#define YES	1
#define NO	0
using namespace std;

int main()
{
	vector <string> vUserInput; // Tworzymy kontener na stringi

	string sUserInput;

	bool moveOn = YES;	// ustawiamy wartosc logiczna na tak

	int numberOfLines = 0;

	cout << "Please write the line of text, after each line hit enter. Write empty line to finish and print the output" << endl;
	do
	{
		cout << ">";
		getline(cin, sUserInput);	// pobieramy linijke tekstu ze standordowego wyjscia z POMINIECIEM ZNAKU KONCA LINIA
		vUserInput.push_back(sUserInput);
		if(sUserInput=="\0")	// jesli string jest pusty czyli rowny 'NULL' character to zmieniamy wartosc logiczna na NIE
			moveOn = NO;

		numberOfLines++;
	}while(moveOn);	// petla wykonuje sie dopoki wartosc logiczna jest na tak


	for(int i = 0; i < numberOfLines; i++)
		cout << vUserInput[i] << ' ';

	cout << endl;
	return 0;	
}