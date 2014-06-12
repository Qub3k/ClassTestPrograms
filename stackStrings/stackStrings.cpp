/*****************************************************************************************************

	Zanim w ogole zaczniesz przegladac ten program musisz zapamietac
	kilka wlascnosci stosu:
	1. Element moze zostac dodany tylko na gore stosu
	2. Masz dostep tylko do ostatniego elementu stostu, ktory zostal dodany (First in = Last out
	3. Ostatni punkt wynika z dwoch poprzednich -> Jesli chcesz przegladnac stos, musisz po kolei
	zrzucic z niego wszystkie elemeny!

*****************************************************************************************************/

#include <iostream>
#include <algorithm>
#include <stack>
#include <fstream>

using namespace std;
	
int main()
{
	cout << "Stack with strings from the file: ";

	string holder;

	stack <string> stackStrings;

	ifstream fin("sourceFile.txt");

	if(!fin)
		cout << "Couldn't open a file!" << endl;

	while(getline(fin, holder))
	{
		stackStrings.push(holder);
		cout << stackStrings.top() << ' ';
	}

	fin.close();

	stack <string> stackHelper;

	while(!stackStrings.empty())	// Algorytm sortowania stosu z uzyciem drugiego stosu
	{
		holder = stackStrings.top();	// zrzucamy najwyzszy element oryginalnego stosu i zapisujemy go do schowka
		stackStrings.pop();				

		while(!stackHelper.empty() && (stackHelper.top()).length() > holder.length())	// Jesi stos pomocniczy nie jest pusty a jego najwzyszy
		{											//  element jest dluzszy od naszego elementu w schowku (z gory oryginalnego stostu)
			stackStrings.push(stackHelper.top());	// to przeloz go na gore oryginalnego stosu
			stackHelper.pop();						// i usun ten najwyzszy ze stosu pomocniczego
		}
		stackHelper.push(holder);	// jesli jednak stos pomocniczy jest pusty lub jego najwyzszy element nie jest dluzszy od tego w schowku
	}								// to poloz na sama gore element ze schowka

	stackHelper.pop();	// stos pomocniczy jest teraz posortowany rosnaca wiec po prostu wyrzucamy najwyzszy element, zeby pozbyc sie 
						// najwyzszej wartosci

	cout << endl << "Stack without the longest string: ";

	while(!stackHelper.empty())	// dopoki stos pomocniczy nie bedzie pusty
	{
		cout << stackHelper.top() << ' ';	// wypisujemy sobie na ekranie najwyzszy element z pomocniczego stsotu
		stackHelper.pop();					// usuwamy najwyszy elemen na stosie pomocniczym
	}

	cout << endl;

	return 0;
}