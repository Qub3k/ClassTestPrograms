/******************************************************

	Program tworzacy klasy przechowujaca liczby 
	rzeczywiste z metodami pozwalajaymi na:
	1. dodanie liczby do zbioru
	2. posortowanie liczb
	3. wypisanie zbioru liczb

******************************************************/

#include <iostream>
#include <algorithm>

#define SIZE	5

using namespace std;


int compare (const void* a, const void* b)
{
	return(*(double*)a > (*(double*)b));
}

class Real
{
public:
	Real(double value=0){};
	~Real(){};

	const void Add(double number, int index){ dValue[index-1] = number;}
	const void Sort() { qsort(dValue, SIZE, sizeof(double), compare);}
	const void Printf() 
	{ 
		cout << "{ ";
		for(int i = 0; i < SIZE; i++)
			cout << dValue[i] << ' ';
		cout << "}" << endl;
	}
private:
	double dValue[SIZE];
};

int main()
{
	Real realArray;

	realArray.Add(1.125, 1);
	realArray.Add(5.135, 2);
	realArray.Add(3.129, 3);
	realArray.Add(6.425, 4);
	realArray.Add(7.156, 5);

	realArray.Sort();

	realArray.Printf();

	return 0;
}

