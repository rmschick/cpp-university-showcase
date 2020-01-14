//This is the function definition file for the Porter stemmer

#include <iostream>
#include "porter.h"

using namespace std;

//stemming steps
string step1a(string);
string step1b(string);
string step1bPart2(string);
string step1c(string);
string step2(string);
string step3(string);
string step4(string);
string step5a(string);
string step5b(string);

//helper functions
int numVC(string); //get value of m
bool isVowel(string, int); //check if a character is a vowel
bool containsVowel(string); //rule (*v*) stem word contains vowel
bool ifCVC(string); //rule (*o*) stem word has CVC pattern
void printFirstDoc(vector<string>); //print first doc's abstract
int numUniqueWords(vector<string>); //finds num of unique words in abstract

//main porter stemming function
void porterStem(vector<docStorage>& docs, bool isQuery)
{
    string word;
    int uniqueStemmed = 0;
    int uniqueUnstemmed = 0;

    //outer loop
    for (int i=0; i < docs.size(); i++) //loops through every abstract
    {
        //output info for unstemmed first doc's abstract
        if (i==0 && !isQuery)
        {
            printFirstDoc(docs[0].Abstract); //print abstract
            cout << "Number of unique unstemmed words: " << numUniqueWords(docs[0].Abstract) << endl << endl;
        }

        //inner loop
        for (int j=0; j < docs[i].Abstract.size(); j++) //loops through every word in the abstract
        {
            word = docs[i].Abstract[j]; //get next word in the abstract

            //perform stemming steps
            //Step 1a
            word = step1a(word);            
            //Step 1b
            word = step1b(word);
            //Step 1c       
            word = step1c(word); 
            //Step 2
            word = step2(word);
            //Step 3
            word = step3(word);
            //Step 4      
            word = step4(word);
            //Step 5a
            word = step5a(word);
            //Step 5b
            word = step5b(word);

            docs[i].Abstract[j] = word; //apply stemming changes
        }//end inner loop

        //output info for stemmed first doc's abstract
        if (i==0 && !isQuery)
        {   
            printFirstDoc(docs[0].Abstract); //print abstract
            cout << "Number of unique stemmed words: " << numUniqueWords(docs[0].Abstract) << endl <<endl;
        }
    }//end outer loop
}

//Porter stemming function for the query
void porterStem(vector<string>& query)
{
    vector<docStorage> temp(1); //create a temporary vector of docs of size 1
    temp[0].Abstract = query; //stores the query vector in the Abstract
    porterStem(temp, true); //Porter stems the query
    query = temp[0].Abstract; //apply stemming changes
}

//stemming Step 1a
string step1a(string word)
{
    //ends in "sses"
    if (word.length() > 4 && word.substr(word.length() - 4) == "sses")
        return word.substr(0, word.length() - 2); //remove last 2 letters

    //ends in "ies"
    if (word.length() > 3 && word.substr(word.length() - 3) == "ies")
        return word.substr(0, word.length() - 2); //remove last 2 letters

    //ends in "s" but not "ss"
    if (word.length() > 2 && word[word.length() - 1] == 's'
    && word.substr(word.length() - 2) != "ss")
        return word.substr(0, word.length() - 1); //remove last letter

    return word;
}

//stemming Step 1b
string step1b(string word)
{
    //ends in "eed"
    if (word.length() > 3 && word.substr(word.length() - 3) == "eed"  
        && numVC(word.substr(0, word.length() - 3)) > 0)
        return word.substr(0, word.length() - 1); //remove last letter

    //ends in "ed" but not "eed"
    if (word.length() > 3 && word.substr(word.length() - 2) == "ed"
        && word.substr(word.length() - 3) != "eed" && containsVowel(word.substr(0, word.length() - 2)))
    {
        word = word.substr(0, word.length() - 2); //remove last 2 letters
        return step1bPart2(word); //conduct part 2 of step 1b
    }
    
    //ends in "ing"
    if (word.length() > 3 && word.substr(word.length() - 3) == "ing"
        && containsVowel(word.substr(0, word.length() - 3)))
    {
        word = word.substr(0, word.length() - 3); //remove last 3 letters
        return step1bPart2(word);  //conduct part 2 of step 1b
    }

    return word;
}

//stemming Step 1b part 2
string step1bPart2(string word)
{
    if (word.length() > 2)
    {
        //ends in "at", "bl" or "iz"
        if (word.substr(word.length() - 2) == "at" || word.substr(word.length() - 2) == "bl"
            || word.substr(word.length() - 2) == "iz")
            return word + 'e'; //add an "e" to the end

        //ends in double letters
        else if (word.length() > 2 && word[word.length() - 1] == word[word.length() - 2] 
            && word.substr(word.length() - 2) != "ll" && word.substr(word.length() - 2) != "ss"
            && word.substr(word.length() - 2) != "zz") //except for "tt", "ss" and "zz"
            return word.substr(0, word.length() - 1); //remove last letter

        //ends in consonant-vowel-consonant and m=1
        else if (ifCVC(word.substr(word.length() - 3)) && numVC(word) == 1)
            return word + 'e'; //add an "e" to the end
    }

    return word;
}

//stemming Step 1c
string step1c(string word)
{
    //ends in "y"
    if (word.length() > 4 && word[word.length() - 1] == 'y'
        && containsVowel(word.substr(word.length() - 4, word.length() - 1)))
        return word.substr(0, word.length() - 1) + 'i'; //change "y" to "i"

    return word;
}

//stemming Step 2
string step2(string word)
{
    //ends in "ational"
    if (word.length() > 7 && word.substr(word.length() - 7) == "ational" 
    && numVC(word.substr(0, word.length() - 7)) > 0)
        return word.substr(0, word.length() - 7) + "ate"; //remove last 7 letters add "ate" to end

    //ends in "tional", "alli", "entli", "eli" or "ousli"
    if (word.length() > 6 && numVC(word.substr(0, word.length() - 6)) > 0 && word.substr(word.length() - 6) == "tional" 
        || word.length() > 4 && numVC(word.substr(0, word.length() - 4)) > 0 && word.substr(word.length() - 4) == "alli"
        || word.length() > 5 && numVC(word.substr(0, word.length() - 5)) > 0 && word.substr(word.length() - 5) == "entli"
        || word.length() > 3 && numVC(word.substr(0, word.length() - 3)) > 0 && word.substr(word.length() - 3) == "eli"
        || word.length() > 5 && numVC(word.substr(0, word.length() - 5)) > 0 && word.substr(word.length() - 5) == "ousli")
        return word.substr(0, word.length() - 2); //remove last 2 letters

    //ends in "enci", "anci" or "abli"
    if (word.length() > 4 && numVC(word.substr(0, word.length() - 4)) > 0)
        if (word.substr(word.length() - 4) == "enci" || word.substr(word.length() - 4) == "anci"
            || word.substr(word.length() - 4) == "abli")
            return word.substr(0, word.length() - 1) + 'e'; //remove last letter and add an "e"

    //ends in "izer"
    if (word.length() > 4 && word.substr(word.length() - 4) == "izer"  
        && numVC(word.substr(0, word.length() - 4)) > 0)
        return word.substr(0, word.length() - 1); //remove last letter

    //ends in "entli"
    if (word.length() > 5 && word.substr(word.length() - 5) == "entli"
        && numVC(word.substr(0, word.length() - 5)) > 0)
        return word.substr(0, word.length() - 5) + "ate"; //remove last 4 letters and add "ate" to end

    //ends in "ization"
    if (word.length() > 7 && word.substr(word.length() - 7) == "ization"
        && numVC(word.substr(0, word.length() - 7)) > 0)
        return word.substr(0, word.length() - 5) + "e"; //remove last 5 letters and add "e" to end

    //ends in "ation"
    if (word.length() > 5 && word.substr(word.length() - 5) == "ation"
        && numVC(word.substr(0, word.length() - 5)) > 0)
        return word.substr(0, word.length() - 5) + "ate"; //remove last 5 letters and add "ate" to end

    //ends in "ator"
    if (word.length() > 4 && word.substr(word.length() - 4) == "ator"
        && numVC(word.substr(0, word.length() - 4)) > 0)
        return word.substr(0, word.length() - 4) + "ate"; //remove last 4 letters and add "ate" to end

    //ends in "alism" or "aliti"
    if (word.length() > 5 && numVC(word.substr(0, word.length() - 5)) > 0)
        if (word.substr(word.length() - 5) == "alism" && word.substr(word.length() - 5) == "aliti")
            return word.substr(0, word.length() - 3); //remove last 3 letters

    //ends in "iveness", "fulness" or "ousness"
    if (word.length() > 7 && numVC(word.substr(0, word.length() - 7)))
        if (word.substr(word.length() - 7) == "iveness" || word.substr(word.length() - 7) == "fulness"
            || word.substr(word.length() - 7) == "ousness")
            return word.substr(0, word.length() - 4); //remove last 4 letters

    //ends in "iviti"
    if (word.length() > 5 && word.substr(word.length() - 5) == "iviti"
        && numVC(word.substr(0, word.length() - 5)) > 0)
        return word.substr(0, word.length() - 3) + "e"; //remove last 3 letters and add "e" to end

    //ends in "biliti"
    if (word.length() > 6 && word.substr(word.length() - 6) == "biliti"
        && numVC(word.substr(0, word.length() - 6)) > 0)
        return word.substr(0, word.length() - 5) + "le"; //remove last 5 letters and add "le" to end

    return word;
}

//stemming Step 3
string step3(string word)
{
    //ends in "icate", "alize" or "iciti"
    if (word.length() > 5 && numVC(word.substr(0, word.length() - 5)) > 0)
        if (word.substr(word.length() - 5) == "icate" || word.substr(word.length() - 5) == "alize"
            || word.substr(word.length() - 5) == "iciti")
            return word.substr(0, word.length() - 3); //remove last 3 letters

    //ends in "ative"
    if (word.length() > 5 && word.substr(word.length() - 5) == "ative"
        && numVC(word.substr(0, word.length() - 5)) > 0)
        return word.substr(0, word.length() - 5); //remove last 5 letters

    //ends in "ical"
    if (word.length() > 4 && word.substr(word.length() - 4) == "ical"
        && numVC(word.substr(0, word.length() - 4)) > 0)
        return word.substr(0, word.length() - 2); //remove last 2 letters

    //ends in "ful"
    if (word.length() > 3 && word.substr(word.length() - 3) == "ful"
        && numVC(word.substr(0, word.length() - 3)) > 0)
        return word.substr(0, word.length() - 3); //remove last 3 letters

    //ends in "ness"
    if (word.length() > 4 && word.substr(word.length() - 4) == "ness"
        && numVC(word.substr(0, word.length() - 4)) > 0)
        return word.substr(0, word.length() - 4); //remove last 4 letters

    return word;
}

//stemming Step 4
string step4(string word)
{
    //ends in "al", "er", "ic" or "ou" 
    if (word.length() > 2 && numVC(word.substr(0, word.length() - 2)) > 1)
        if (word.substr(word.length() - 2) == "al" || word.substr(word.length() - 2) == "er"
            || word.substr(word.length() - 2) == "ic" || word.substr(word.length() - 2) == "ou")
            return word.substr(0, word.length() - 2); //remove last 2 letters

    //ends in "ance", "ence", "able", "ible" or "ment"
    if (word.length() > 4 && numVC(word.substr(0, word.length() - 4)) > 1)
        if (word.substr(word.length() - 4) == "ance" || word.substr(word.length() - 4) == "ence"
            || word.substr(word.length() - 4) == "able" || word.substr(word.length() - 4) == "ible"
            || word.substr(word.length() - 4) == "ment")
            return word.substr(0, word.length() - 4); //remove last 4 letters

   // word = "velociti";
    //ends in "ant", "ent", "ism", "ate", "iti", "ous", "ive" or "ize"
    if (word.length() > 3 && numVC(word.substr(0, word.length() - 3)) > 1)
        if (word.substr(word.length() - 3) == "ant" || word.substr(word.length() - 3) == "ent"
            || word.substr(word.length() - 3) == "ism" || word.substr(word.length() - 3) == "ate"
            || word.substr(word.length() - 3) == "iti" || word.substr(word.length() - 3) == "ous"
            || word.substr(word.length() - 3) == "ive" || word.substr(word.length() - 3) == "ize")
            return word.substr(0, word.length() - 3); //remove last 3 letters
    
    //ends in "ion"
    if (word.length() > 4 && numVC(word.substr(0, word.length() - 3)) > 1
        && word.substr(word.length() - 3) == "ion")
        if (word[word.length() - 4] == 't' || word[word.length() - 4] == 's')
            return word.substr(0, word.length() - 3); //remove last 3 letters 

    return word;
}

//stemming Step 5a
string step5a(string word)
{
    //ends in "e"
    if (word.length() > 3 && word[word.length() - 1] == 'e')
        if (numVC(word.substr(0, word.length() - 1)) > 1
            || numVC(word.substr(0, word.length() - 1)) == 1 
            && !ifCVC(word.substr(word.length() - 4, word.length() - 1)))
            return word.substr(0, word.length() - 1); //remove last letter

    return word;
}

//stemming Step 5b
string step5b(string word)
{
    //ends in "ll"
    if (word.length() > 2 && word.substr(word.length() - 2) == "ll"
        && numVC(word.substr(0, word.length() - 1)) > 1)
        return word.substr(0, word.length() - 1); //remove last 2 letters

    return word;
}

//check if a letter is a vowel or not
bool isVowel(string str, int index)
{
    if (str[index]=='a' || str[index]=='e' || str[index]=='i' || str[index]=='o' || str[index]=='u' 
        || str[index] == 'y' && !isVowel(str, index - 1)) //if y, check for consonant before y
        return true;
    else
        return false; //is not vowel
}

//rule (*v*) check if stem word contains a vowel
bool containsVowel(string str)
{
    //if stem word contains a vowel
    for (int i=0; i < str.length(); i++)
        if (isVowel(str, i))
            return true;

    return false; //doesn't contain vowel
}

//get value of m, m is the number of vowels followed by a consonant in a word
int numVC(string word)
{
    int m = 0;
    bool foundVowel = false;

    for (int i=0; i < word.length(); i++)
    {
        if (isVowel(word, i)) //found vowel
            foundVowel = true;

        if (foundVowel && !isVowel(word, i)) //found VC pattern, increment m
        {
            foundVowel = false;
            m++;
        }
    }

    return m;
}

//rule (*o*) ends in consonant-vowel-consonant pattern
bool ifCVC(string word)
{
    if (word[2] != 'w' && word[2] != 'x' && word[2] != 'y' && //second to last character of word is not 'W', 'X' or 'Y'
        !isVowel(word, 0) && isVowel(word, 1) && !isVowel(word, 2)) //if word ends with consonant-vowel-consonant (CVC)
        return true;
    else
        return false; //last three letters do not follow CVC pattern
}

//finds number of unique words in abstract
int numUniqueWords(vector<string> abstract)
{
    bool add = true;
    vector<string> unique = {abstract[0]}; //stores unique words

    for (int i=0; i < abstract.size(); i++)
    {
        for (int j=0; j < unique.size(); j++)
            if (abstract[i] == unique[j] || abstract[i] == "")
            {
                add = false; //found duplicate word
                break;
            }

        if (add)
            unique.push_back(abstract[i]); //found unique word
        add = true;
    }

    return unique.size();
}

//outputs the first doc's abstract
void printFirstDoc(vector<string> abstract)
{
    for (int i=0; i < abstract.size(); i++)
        if(abstract[i] != "")
            cout << abstract[i] << ' ';

    cout << endl;
}