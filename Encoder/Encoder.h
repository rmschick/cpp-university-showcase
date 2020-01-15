#pragma once
#include <string>
#include <iostream>


using namespace std;

//Encoding class

class Encoder {
private:
	string compStr;			//string that will be holding compressed value
	string deStr;			//string that holds decompressed value

public:
	Encoder() {				//empty constructor
		compStr = "";
		deStr = "";
	}
	string RunEncoder(string getComp);		//fuction that compresses string
	string RunDecoder(string getDecomp);	//function that decompresses string

};