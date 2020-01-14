//============================================================================
// Name        : CosineSimilarity.cpp
// Author      : Yash Chulki
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================
/*
#include <iostream>
#include <cmath>

using namespace std;

void similarity() {

	int num, denom; // numerator and denominator
	int wordCountDoc, wordCountQuery; //words in document or query
	int A = 2; //A, tf-idf for each word in document
	int B = 4; //B, tf-idf for each word in query
	double squareA, squareB; //square of A and B
	double squareRootA, squareRootB; //sqaure root of A and B
	double cosineSimilarity; //cosine similarity


	num = A * B; //numerator = A * B
	cout << "Numerator: A * B = " << num;

	//for each word in the document, add the squares of the tf-idf of each
	for (int i = 0; i < wordCountDoc; i++)
	{
		squareA += (A * A);
	}

	//for each word in the query, add the squares of the tf-idf of each
	for (int j = 0; j < wordCountDoc; j++)
	{
		squareB += (B * B);
	}

	//sqaure roots of A and B
	squareRootA = (sqrt(squareA));
	squareRootB = (sqrt(squareB));

	denom = squareRootA * squareRootB; //denominator = square of sums of A and B

	cosineSimilarity = num / denom; //cosine similarity = numerator / denominator

	cout << "Cosine similarity is " << cosineSimilarity << endl;

	cout << "Turn on the radio" << endl; // prints !!!Hello World!!!
	



}
*/
