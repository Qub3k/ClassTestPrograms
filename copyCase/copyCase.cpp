#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string dataInFile; // String do przechowywania informacji zawartych w pliku zrodlowym

	cout << "Podaj nazwe pliku, ktory chcesz przekopiowac:" << endl;
	cout << ">";

	char fromFile[80];	// zapisanie nazwy pliku zrodlowego
	cin >> fromFile;

	cout << "Podaj nazwe pliku docelowego:" << endl;
	cout << ">";

	char intoFile[80];	// zapisanie nazwy pliku docelowego
	cin >> intoFile;

	ifstream fin(fromFile);	// otwarcie plikue zrodlowego w trybie 'do odczytu'

	if(!fin)
		cout << "Couldn't open a file!" << endl;

	getline(fin, dataInFile);	// pobranie linijki tekstu

	// zeby zeminic na duze litery od nr ascii znaku odejmij 32
	// zeby zmienic na mala litery do nr ascii dodaj 32

	for(int i = 0; i < dataInFile.length(); i++)	
	{
		if(((int)dataInFile[i]) > 96 && ((int)dataInFile[i]) < 123) // sprawdzamy male litery
			dataInFile[i] = (char)((int)dataInFile[i]-32);	// zamieniamy na duze
		else if(((int)dataInFile[i]) > 64 && ((int)dataInFile[i]) < 91 )	// sprawdzamy duze litery
			dataInFile[i] = (char)((int)dataInFile[i]+32);	// zamieniamy na male
	}

	fin.close();	// zamykamy plik zrodlowy

	ofstream fout(intoFile); // otwieramy plik docelowy
	fout << dataInFile << endl; // wpisujemy do niego ciag tekstowy uzywajac strumienia stworzonego linijke wczesniej

	fout.close();

	return 0;
}