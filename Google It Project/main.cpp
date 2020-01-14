#include <iostream>
#include "docStorage.h"
#include "porter.h"
#include "Query.h"
#include "termFrequency.h"


using namespace std;

int main()
{
	vector<docStorage> docVector;//vector of objects
	vector<string> Stopwords;		//vector for stopwords
	docStorage Doc;//object of class

	Doc.storeDocs(docVector);		//stores docs
	Doc.stopWordDocs(Stopwords);//stores stopwords
	Doc.printDocs(docVector);		//prints docs
	Doc.printStopWords(Stopwords);//prints # of stopwords

	for (int i = 0; i < docVector.size(); ++i)
	{
		Doc.remTitle(docVector[i].Abstract, docVector[i].Title);
		for (int j = 0; j < docVector[i].Abstract.size(); ++j)
		{
			Doc.vectorCompare(Stopwords, docVector[i].Abstract);//removes stopwords from every abstract

			Doc.remPunct(docVector[i].Abstract);//removes punctuation marks from every abstract
		}

	}
	cout << endl;
	if (docVector.size() > 1) {
		//Porter stem the docs vector and output the first doc and information
		porterStem(docVector);

		//Creating Query and termFrequency object in order to call fuctions
		Query Google;
		termFrequency Bing;

		Bing.setAbstract(docVector);	//setting termFrequency's vector of vector strings to all document's abstract 
		Bing.setidfAbstract();
		Bing.setTFIDFAbstract();
		Bing.printTF();					//print TF, IDF, TF-IDF
		Google.setQue();

		//Porter stem the query
		porterStem(Google.Que);

		Bing.setQuery(Google.Que);		//set Query after porter stemming
		Bing.setTFIDFQuery();			// get TFIDF for Query
		Bing.printTFQuery();			//print any words in the query that aren't present in any document

		//*****cosine similarity*****
		//CosSimilarity cos; //create CosSimilarity object 
		//cos.similarity(); //call CosSimilarity function
	}
	cout << endl << "Complete!" << endl;

	system("Pause");	//DELETE WHEN SUBMITTING
	return 0;
}