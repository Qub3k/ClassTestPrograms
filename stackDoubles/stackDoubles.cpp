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

using namespace std;
	
int main()
{
	cout << "Stack with random numbers: ";

	double holder = .0;

	stack <int> stackDoubles;

	for(int i = 0 ; i < 10; ++i)
	{
		stackDoubles.push((rand() % 100 ));	
		cout << stackDoubles.top() << ' ';
	}

	stack <double> stackHelper;

	while(!stackDoubles.empty())	// Algorytm sortowania stosu z uzyciem drugiego stosu
	{
		holder = stackDoubles.top();	// zrzucamy najwyzszy element oryginalnego stosu
		stackDoubles.pop();				// zapisujemy go sobie do schowka

		while(!stackHelper.empty() && stackHelper.top() > holder)	// Jesi stos pomocniczy nie jest pusty a jego najwzyszy element jest wiekszy
		{															// od naszego elementu w schowku (z gory oryginalnego stostu)
			stackDoubles.push(stackHelper.top());	// to przeloz go na gore oryginalnego stosu
			stackHelper.pop();						// i usun ten najwyzszy ze stosu pomocniczego
		}
		stackHelper.push(holder);	// jesli jednak stos pomocniczy jest pusty lub jego najwyzszy element nie jest wiekszy od tego w schowku
	}								// to poloz na sama gore element ze schowka

	stackHelper.pop();	// stos pomocniczy jest teraz posortowany rosnaca wiec po prostu wyrzucamy najwyzszy element, zeby pozbyc sie 
						// najwyzszej wartosci

	cout << endl << "Stack without the highest vale: ";

	while(!stackHelper.empty())	// dopoki stos pomocniczy nie bedzie pusty
	{
		cout << stackHelper.top() << ' ';	// wypisujemy sobie na ekranie najwyzszy element z pomocniczego stsotu
		stackHelper.pop();					// usuwamy najwyszy elemen na stosie pomocniczym
	}

	cout << endl;

	return 0;
}