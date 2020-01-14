//class definition file for termFrequency.h 
//Ryan Schick
//9/16/2019
#include "termFrequency.h"

void termFrequency::setAbstract(vector<docStorage> abs)		//Populates a vector of vector strings with the abstracts of all documents
{	
	for (int k = 0; k < abs.size(); k++)
	{
		DocAbstracts.push_back(abs[k].Abstract);					//setting abstract vector to equal all abstracts of the documents
		sort(DocAbstracts[k].begin(), DocAbstracts[k].end());		//sorts abstract words in alphabetical order for easier and efficent comparing
	}
	TFAbstract.resize(DocAbstracts.size());
	for (int i = 0; i < DocAbstracts.size(); i++)				//calculates the TF of current word in current document
	{
		for (int j = 0; j < DocAbstracts[i].size(); j++)
		{
			int count = 1;
			for (int t = j+1; t <DocAbstracts[i].size(); t++)
			if (DocAbstracts[i][j] == DocAbstracts[i][t]) {		//deletes reaccuring words so that output only has one word for abstract
				DocAbstracts[i].erase(DocAbstracts[i].begin() + t);
				count++;
				if (t > 0)
					t--;
			}
			TFAbstract[i].push_back(count);						//pushes the term frequency of the word to TFAbstract vector
		}
			
	}

}


void termFrequency::setidfAbstract()				//calculates the idf for the abstracts for each document
{
	idfAbstract.resize(DocAbstracts.size());
	double N = DocAbstracts.size();
	double result = 0;
	double count = 1;
	for (int i = 0; i < DocAbstracts.size(); i++)		// [i] denotes the current document that is being compared to the others
	{
		sort(DocAbstracts[i].begin(), DocAbstracts[i].end());
		for (int j = 0; j < DocAbstracts[i].size(); j++)	// [j] denotes the current word in current document that is being compared
		{
			count = 1;
			for (int k = (i+1); k < DocAbstracts.size(); k ++) // [k] denotes the document that the current word is being compared into
			{
				for (int z = 0; z < DocAbstracts[k].size(); z++)	// [z] denotes the word that the current word is being compared to
				{
					if (DocAbstracts[i][j] == DocAbstracts[k][z])
					{
						count++;
						break;
					}
					
				}
				
			}
			result = abs(log(N / count));
			idfAbstract[i].push_back(result);
		}
			
	}

}

void termFrequency::setTFIDFAbstract()			//puts all the tfidf numbers in a vector of vectors [i] denoting which document
{												//while [j] denotes the associated word
	tfIDFAbstract.resize(idfAbstract.size());
	for (int i = 0; i < idfAbstract.size(); i++)
	{
		for (int j = 0; j < idfAbstract[i].size(); j++)
			tfIDFAbstract[i].push_back(TFAbstract[i][j]*(idfAbstract[i][j]));
	}
}

void termFrequency::setTFIDFQuery()			//calculates and puts the tfidf of the query into a vector
{

	double N = DocAbstracts.size();
	double result = 0;
	double count = 0;
	for (int que = 0; que < tfQuery.size(); que++)			//loops through query and each document to compare words to see how many times 
	{														//the current word in query is in current document
		
		count = 0;
		for (int doc = 0; doc < DocAbstracts.size(); doc++)
		{
			for (int word = 0; word < DocAbstracts[doc].size(); word++)
			{
				if (tfQuery[que] == DocAbstracts[doc][word])
				{
					count++;
					break;
				}
			}
		}
		if (count == 0.0)
			result = 0.0;
		else 
			result = abs(log(N / count));		//calculates tf-idf of query since there is no tf 
		tfidfQuery.push_back(result);			//pushes to tfIDF Query vector to stay in order
	}
}

void termFrequency::printTF()			//printing tf-IDF "chart" that displays the first document's words and tfIDF in correct formating
{
	for (int k = 1; k < DocAbstracts[0].size(); k++)
	{
		cout << setprecision(0) << "Word:" << setw(22) << DocAbstracts[0][k] << setw(2) << "  TF:   " << TFAbstract[0][k];
		cout << setprecision(5) << fixed << setw(2) << " IDF:  " << idfAbstract[0][k] << setw(2) << "  TFIDF:  " << tfIDFAbstract[0][k] << endl;
	}
}

void termFrequency::printTFQuery()		//printing out if any of the words in the query don't show up documetns
{
	for (int i = 0; i < tfQuery.size(); i++)
	{
		if (tfidfQuery[i] == 0.0) {
			cout << tfQuery[i] << " is not in any of the documents." << endl;
			tfQuery.erase(tfQuery.begin() + i);
			tfidfQuery.erase(tfidfQuery.begin() + i);
		}

	}
}

