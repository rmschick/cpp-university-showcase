//This the header file for the Porter stemmer

#include <vector>
#include "docStorage.h"

using namespace std;

#if !defined(PORTER_H)
#define PORTER_H

//main functions
void porterStem(vector<docStorage>&, bool = false);
void porterStem(vector<string>&); //puts query vector into doc and calls porterStem(queryDoc, true)

#endif