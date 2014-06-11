#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
	for( int i = 6; i < 10; i++) // Sprawdzam rok
	{	
		if(a[i]!=b[i])
			return (a<b);	
	}
	for( int i = 3; i < 5; i++) // Sprawdzam miesiac
	{	
		if(a[i]!=b[i])
			return (a<b);
	}	
	for( int i = 0; i < 2; i++) // Sprawdzam dzien
	{	
		if(a[i]!=b[i])
			return (a<b);
	}	
}

int main()
{
	vector <string> vDate;

	string sUserDate;

	cout << "Please insert few dates in the format DD-MM-YEAR" << endl;
	for(int i = 0; i<3; i++)
	{
		cout << ">";
		getline(cin, sUserDate);
		vDate.push_back(sUserDate);
	}

	sort(vDate.begin(), vDate.end(), compare);

	for(int i = 0; i<3; i++)
		cout << vDate[i] << ' ';

	cout << endl;

}