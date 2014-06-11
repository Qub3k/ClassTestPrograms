#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


int main()
{
	vector <string> vFromFile;

	ifstream fin("file.txt");

	if(!fin)
		cout << "Couldn't open a file!" << endl;

	string sFromFile;

	while(getline(fin, sFromFile))
		vFromFile.push_back(sFromFile);

	for(int i = 0; i < vFromFile.size(); i++)
		cout << vFromFile[i] << ' ';

	cout << endl;

	fin.close();
	
	return 0;
}