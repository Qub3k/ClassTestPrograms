#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare (string a, string b)
{
	return (a < b);
}

int main()
{
	vector <string> vStringArray;

	string sUserInput;

	for(int i = 0; i < 5; i++)
	{
		cout << "Wpisz linijke tekstu" << endl;
		cout << ">";

		getline(cin, sUserInput);
		
		vStringArray.push_back(sUserInput);
	}


	sort(vStringArray.begin(), vStringArray.end(), compare);
	
	for(int i = 0; i < 5; i++)
		cout << vStringArray[i] << "; ";

	cout << endl;

	return 0;
}