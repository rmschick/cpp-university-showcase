#include "Encoder.h"


int main()
{
	Encoder RLE;
	string getstr;		//holds user input
	string encstr;		//compressed string
	string decstr;		//decompressed string

	cout << "Program to compress messages using RLE" << endl;
	cout << "Enter string to compress: ";
	getline(cin, getstr);
	encstr = RLE.RunEncoder(getstr);		//store compressed string into encstr
	cout << "\nCompressed String: " << encstr;
	decstr = RLE.RunDecoder(encstr);		//store decompressed string into decstr
	cout << "\nDecompressed String: " << decstr << endl;

	system("pause");
	return 0;

}