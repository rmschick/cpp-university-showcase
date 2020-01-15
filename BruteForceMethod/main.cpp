#include "BruteForce.h"


using namespace std;

int main()
{
	
	string T;
	cout << "Enter a string to preform Brute force tree. \n";
	cin >> T;
	
	T = T + "$"; //assigns symbol which concludes the tree
	high = T.length() - 1;
	bruteTree *RootValue = new bruteTree(-1, 1);

	for (int i = T.length() - 1; i >=0; i--)
	{
		RootValue = Build(RootValue, T, i);
		DisplayBruteForceBruteTree(RootValue, T);
		cout << "\n";
	}
	system("pause");
	return 0;
}