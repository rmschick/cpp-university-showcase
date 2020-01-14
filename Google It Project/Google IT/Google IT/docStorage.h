#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class docStorage {	//document class. This stores documents and stopwords, as well as printing and removing stopwords and punctuation
public:
	vector<string> ID;
	vector<string> Title;
	vector<string> Author;
	vector<string> Abstract;
	docStorage() {};
	docStorage(vector<string>, vector<string>, vector<string>, vector<string>) { vector<string> ID; vector<string>  Title; vector<string>  Author; vector<string>  Abstract; }
	void storeDocs(vector<docStorage> &docVector);
	void stopWordDocs(vector<string> &Stopwords);
	void printDocs(vector<docStorage> docVector);
	void printStopWords(vector<string> &Stopwords);
	void vectorCompare(vector<string> &Stopwords, vector<string> &Abstract);
	void remPunct(vector<string>& Abstract);
	void remTitle(vector<string>& Abstract, vector<string> & Title);
};