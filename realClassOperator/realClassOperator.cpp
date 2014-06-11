#include <iostream>
#include <algorithm>

#define SIZE	10

using namespace std;

int index = 0;	// ustalami globalna zmienna przechowujace ilosc elementow juz wpisanych do tabeli dValue

int compare (const void* a, const void* b)	// funkcja sluzaca do porownywania dwoch kolejnych elementow w tablicy
{
	return(*(double*)a > (*(double*)b));
}

class Real
{
public:
	Real(double value=0){};
	~Real(){};

	const void Sort() { qsort(dValue, index, sizeof(double), compare);}	// sortowanie qsortem

	double operator << (double number) { dValue[index] = number; index++;} // przeciazanie operatora dla danych typu double

	double operator >> (int howManyEntries) // przeciazanie operator dla naych typu double
	{
		cout << "{ ";
		for(int i = 0; i < howManyEntries; i++)
			cout << dValue[i] << ' ';
		cout << "}" << endl;
	}

private:
	double dValue[SIZE];
};

int main()
{
	Real realArray;

	realArray << 1.2456; // wpisanie liczb do naszej tablicy 
	realArray << 2.1456;
	realArray << 7.5456;
	realArray << 8.2856;

	realArray.Sort();	// sortowanie tablicy

	realArray >> 4;	// wypisanie na ekranie 4 pierwszych elemntow tablicy

	return 0;
}

