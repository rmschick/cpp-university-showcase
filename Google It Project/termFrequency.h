#pragma once
//header file calculating and outputting the tf-idf for each word in first document of the collection
//Ryan Schick
//9/18/2019
#include "Query.h"
#include "docStorage.h"
#include <cmath>
using namespace std;

class termFrequency : public Query  {
private:
	vector <vector<double>> TFAbstract;
	vector <vector <double>>idfAbstract;
	vector <vector <double>>tfIDFAbstract;
	vector <double> tfidfQuery;
	vector <string> tfQuery;
	vector <vector <string>> DocAbstracts;
	
public:
	void setAbstract(vector<docStorage>);	//sets local query to equal query from Query.h
	void setQuery(vector <string> setQ) {
		tfQuery = setQ;
	}
	void setidfAbstract();		//calc idf of abstract
	void setTFIDFAbstract();	//calc tfidf of abstract
	void setTFIDFQuery();		//calc tfidf of query 
	void printTF();				//prints words, tf, idf, and tfidf 
	void printTFQuery();		//prints query words that dont show in docs
};