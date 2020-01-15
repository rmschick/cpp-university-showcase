#include "Encoder.h"

string Encoder::RunEncoder(string getComp)		//returns compressed string
{
	int len = 0;		//number of char
	int i;				
	for (i = 0; i < getComp.length(); i++)
	{
		compStr += getComp.at(i);		//get char and put it into the compressed string
		len = 1;
		if (i != getComp.length() - 1) {
			while (getComp.at(i) == getComp.at(i+1))	//loops to see if the char at position i is 
			{											//the same as the char in the next position
				i++;
				len++;
			}
		}
		
			compStr += to_string(len);		//add number to stirng
	}
	return compStr;
}

string Encoder::RunDecoder(string getDecomp)		//returns decompressed string
{
	int len = 0;		//number of char
	int a = 0;			//place holder

	while (a < getDecomp.length()-1)		//loops through string to decompress
	{
		char c = getDecomp.at(a);
		deStr += c;
		a++;
		len = int(getDecomp.at(a)) - 48;

		for (int b=1; b < len; b ++)
		{
			deStr += c;		//add char to the string 
		}
		a++;
	}
	return deStr;
}