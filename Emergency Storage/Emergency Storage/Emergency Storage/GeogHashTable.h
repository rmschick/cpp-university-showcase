//This is the header file for the geography table class

#include <iostream>
#include <vector>
#include <iomanip>
#include "linked_list.h"

using namespace std;

#ifndef GEOGHASH_H
#define GEOGHASH_H

//hash table entry class
class GeogEntry
{
    public:
        //table columns
        string replan_id;    //key
        string geo_name;
        string geo_stusab;
        string geo_sumlev;
        string geo_state;
        string geo_county;
        string geo_geoid;
        string population;

        bool tombstoned;     //is entry tombstoned or not

        GeogEntry(string[]); //constructor for entry
        GeogEntry();         //default constructor for entry
};

//hash table class
class GeogHashTable
{
    public:
        vector<GeogEntry> data;      //contains the entries of the table

        LinkedList<GeogEntry> list;  //contains a list of pointers to the entries

        GeogHashTable();
        string toString(GeogEntry);  //converts entry to a string for output
        GeogEntry split(string);     //seperates query string into an entry
        int hash(string);            //multiplicative string hashing function
        void INSERT(string, string); //inset entry into table
        void DELETE(string, string); //delete entries from table
        void SELECT(string, string); //search for entries in table
        void UPDATE(string, string); //update an entry in table
        void DISPLAY();              //output the table
};

#endif