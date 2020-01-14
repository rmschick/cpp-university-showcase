//This is the function definition file for the geography table class
//Hashing function: multiplicative string hashing
//Collision method: linear probing

#include "GeogHashTable.h"

//constructor for entry
GeogEntry::GeogEntry(string rowData[])
{
    replan_id = rowData[0]; //key
    geo_name = rowData[1];
    geo_stusab = rowData[2];
    geo_sumlev = rowData[3];
    geo_state = rowData[4];
    geo_county = rowData[5];
    geo_geoid = rowData[6];
    population = rowData[7];
    tombstoned = false;
}

//default constructor for entry
GeogEntry::GeogEntry()
{
    replan_id = "NoName";
    geo_name = "NoName";
    geo_stusab = "NoName";
    geo_sumlev = "NoName";
    geo_state = "NoName";
    geo_county = "NoName";
    geo_geoid = "NoName";
    population = "NoName";
    tombstoned = false;
}

//default constructor for hash table
GeogHashTable::GeogHashTable()
{
    data.resize(59); //allocate 59 buckets
}

//seperates query string into an entry
GeogEntry GeogHashTable::split(string queryStr)
{
    string rowData[8];
    int column = 0;

    //split string into an array of strings
    for (int i=0; i < queryStr.length(); i++)
    {
        if (queryStr[i] != '"')
            if (queryStr[i] != ',' || queryStr[i] == ',' && queryStr[i+1] == ' ')
                rowData[column] += queryStr[i];
            else
                column++;
    }

    //return a newly created entry
    return GeogEntry(rowData);
}

//multiplicative string hashing function
int GeogHashTable::hash(string key)
{
    int index = 0;

    for (int i=0; i < key.length(); i++)
        index = index * 2 + key[i];

    return index % data.size();
}

//converts entry to a string for output
string GeogHashTable::toString(GeogEntry entry)
{
    return '(' + entry.replan_id + (entry.geo_name == "*" ? "," : ",\"") + entry.geo_name 
         + (entry.geo_name == "*" ? "," : "\",") + entry.geo_stusab + ',' + entry.geo_sumlev
         + ',' + entry.geo_state + ',' + entry.geo_county + ',' + entry.geo_geoid + ',' + entry.population + ')';
}

//inset entry into table
void GeogHashTable::INSERT(string queryStr, string table)
{
    GeogEntry query = split(queryStr);
    int index = hash(query.replan_id); //hash function
    bool failed = true;

    //add entry
    for (int i=0; i < data.size(); i++)
    {
        if (query.replan_id == data[index].replan_id) //duplicate key found
            break;   //failed
        
        if (data[index].replan_id == "NoName" || data[index].tombstoned) //find an available entry
        {
            data[index] = query;   //assign entry to table
            list.append(&data[index]); //add entry address to linked list
            failed = false;
            cout << "Inserted " << toString(query) << " into geography" << endl;
            break;   //done
        }

        if (index == data.size()-1)
            index = 0;   //start over at beginning
        else
            index++;
    }

    //failed to insert
    if (failed)
        cout << "Failed to insert " << toString(query) << " into geography" << endl;
}

//delete entries from table
void GeogHashTable::DELETE(string queryStr, string table)
{
    GeogEntry iterate;
    GeogEntry* toDelete;
    GeogEntry query = split(queryStr);
    LinkedList<GeogEntry> matches;

    //delete entries
    for (int i=0; i < list.length(); i++)
    {
        iterate = *list.get(i); //get next node

        //if entry matches the query
        if ((query.replan_id == "*" || iterate.replan_id == query.replan_id)
            && (query.geo_name == "*" || iterate.geo_name == query.geo_name)
            && (query.geo_stusab == "*" || iterate.geo_stusab == query.geo_stusab)
            && (query.geo_sumlev == "*" || iterate.geo_sumlev == query.geo_sumlev)
            && (query.geo_state == "*" || iterate.geo_state == query.geo_state)
            && (query.geo_county == "*" || iterate.geo_county == query.geo_state)
            && (query.geo_geoid == "*" || iterate.geo_geoid == query.geo_geoid)
            && (query.population == "*" || iterate.population == query.population))
        {
            matches.append(list.get(i)); //add address to matches
            toDelete = list.get(i);     //get entry address
            toDelete->tombstoned = true;    //tombstone entry
            list.erase(i);   //remove from linked list
        }
    }

    //output results
    if (matches.length() == 1) //one match to query
        cout << "Deleted " << toString(*matches.get(0)) << " in geography" << endl;
    else if (matches.length() > 1)   //multiple matches to query
    {
        cout << "Deleted entries: " << endl;
        for (int i = matches.length()-1; i >= 0; i--)
            cout << toString(*matches.get(i)) << " in geography" << endl;
    }
    else   //no matches to query
        cout << "Failed to delete " << toString(query) << " in geography" << endl;
}

//update an entry in table
void GeogHashTable::UPDATE(string queryStr, string table)
{
    GeogEntry query = split(queryStr);
    int index = hash(query.replan_id); //hash function
    bool failed = true;

    //update entry
    for (int i=0; i < data.size(); i++)
    {
        if (data[index].replan_id == "NoName" || (data[index].replan_id == query.replan_id && data[index].tombstoned))
            break;   //found a hole or it is tombstoned, therefore not in list

        //if entry with correct key is found
        if (data[index].replan_id == query.replan_id)
        {
            data[index] = query; //update entry
            failed = false;
            cout << "Updated " << toString(query) << " in geography" << endl;
            break;   //done
        }

        if (index == data.size()-1)
            index = 0;   //start over at beginning
        else
            index++;
    }

    //failed to update
    if (failed)
        cout << "Failed update " << toString(query) << " in geography" << endl;
}

//search for entries in table
void GeogHashTable::SELECT(string queryStr, string table)
{
    GeogEntry iterate;
    GeogEntry query = split(queryStr);
    LinkedList<GeogEntry> matches;

    //search for matches
    for (int i=0; i < list.length(); i++)
    {
        iterate = *list.get(i); //get next node

        //if entry matches the query
        if ((query.replan_id == "*" || iterate.replan_id == query.replan_id)
            && (query.geo_name == "*" || iterate.geo_name == query.geo_name)
            && (query.geo_stusab == "*" || iterate.geo_stusab == query.geo_stusab)
            && (query.geo_sumlev == "*" || iterate.geo_sumlev == query.geo_sumlev)
            && (query.geo_state == "*" || iterate.geo_state == query.geo_state)
            && (query.geo_county == "*" || iterate.geo_county == query.geo_state)
            && (query.geo_geoid == "*" || iterate.geo_geoid == query.geo_geoid)
            && (query.population == "*" || iterate.population == query.population))
        {
            matches.append(list.get(i));   //add address to matches
        }
    }

    //output results
    if (matches.length() == 1) //one match to query
        cout << "Found " << toString(*matches.get(0)) << " in geography" << endl;
    else if (matches.length() > 1)   //multiple matches to query
    {
        cout << "Found entries: " << endl;
        for (int i = matches.length()-1; i >= 0; i--)
            cout << toString(*matches.get(i)) << " in geography" << endl;
    }
    else   //no matches to query
        cout << "No entries match query " << toString(query) << " in geography" << endl;
    
}

//output the table
void GeogHashTable::DISPLAY()
{
    //heading
    cout << left << setw(10) << "replan_id" << setw(45) << "geo_name" << setw(11) << "geo_stusab" << setw(11) 
         << "geo_sumlev" << setw(10) << "geo_state" << setw(11) << "geo_county" << setw(14) 
         << "geo_geoid" << "population" << endl;

    //output table data
    GeogEntry iterate;
    for (int i = list.length()-1; i >= 0; i--)
    {
        iterate = *list.get(i);   //get next node
        cout << setw(10) << iterate.replan_id << setw(45) << iterate.geo_name << setw(11) << iterate.geo_stusab << setw(11) 
             << iterate.geo_sumlev << setw(10) << iterate.geo_state << setw(11) << iterate.geo_county << setw(14) 
             << iterate.geo_geoid << iterate.population << endl;
    }
}