//Hash function: modulo
//Collision strategy: chaining
#include "AgeHashTable.h"

AgeHashTable::AgeHashTable()
{
	data.resize(53); //allocateSpace
	for (int i = 0; i < data.size(); i++)
	{
		data[i].resize(53);
	}
}

AgeEntry::AgeEntry(string id, string c, string t, string old)	//constructor
{
	ID = id;
	child = c;
	teen = t;
	elder = old;
	tombstone = false;
}

AgeEntry::AgeEntry()		//default constructor
{
	ID = "NoName";
	child = "NoName";
	teen = "NoName";
	elder = "NoName";
}

void AgeHashTable::INSERT(string element, string table)		//inserts data into hash table 
{
	AgeEntry temp = SEPERATE(element);
	int index = key(temp);	//hash function
	if (data[index][0].ID == "NoName")
	{
		data[index][0] = temp;	//adds temp into HashTable
		list.append(&data[index][0]);  //adds new AgeEntry to secondary index
		cout << "Inserted(" << element << ") into age" << endl;
	}
	else if (data[index][0].ID != "NoName") {
		for (int i = 0; i < data[index].size(); i++)
			if (temp.ID != data[index][i].ID && data[index][i].ID == "NoName")
			{
				data[index][i] = temp; //adds temp into HashTable
				list.append(&data[index][i]);	//adds new AgeEntry to secondary index
				cout << "Inserted(" << element << ") into age" << endl;
				break;
			}
			else if (temp.ID == data[index][i].ID)
			{
				cout << "Failed to insert (" << element << ") into age" <<endl;
				break;
			}
			else if (data[index][i].tombstone == true)
			{
				data[index][i] = temp; //adds temp into HashTable
				list.append(&data[index][i]);	//adds new AgeEntry to secondary index
				cout << "Inserted(" << element << ") into age" << endl;
				break;
			}

	}
	else
		cout << "There's another possiblilty you need to look into";
}

void AgeHashTable::SELECT(string element, string table)		//finds entries in the table requested from query
{
	vector<AgeEntry> foundEntries;
	AgeEntry temp = SEPERATE(element);
	AgeEntry it;
		for (int i = 0; i < list.length(); i++) //go through all of the collisions until found
		{
			it = *list.get(i);
			if (temp.ID == "*" || temp.ID == it.ID)
			{
				if (temp.child == "*" || temp.child == it.child)
				{
					if (temp.teen == "*" || temp.teen == it.teen)
					{
						if (temp.elder == "*" || temp.elder == it.elder) 
							foundEntries.push_back(temp);
					}
				}
			}
		}
		if (foundEntries.size() == 1)		//output found entries
			cout << "Found " << "(" << foundEntries[0].ID << "," << foundEntries[0].child << "," <<
			foundEntries[0].teen << "," << foundEntries[0].elder << ") in age" << endl;
		else if (foundEntries.size() > 1)	//if there was a found AgeEntry, output data
		{	cout << "Found entries:" << endl;
			for (int j = 0; j < foundEntries.size(); j++)
			{
				cout << "(" << foundEntries[j].ID << "," << foundEntries[j].child << "," <<
					foundEntries[j].teen << "," << foundEntries[j].elder << ") in age" << endl;
			}
			foundEntries.clear();
		}
		else                  // no entries found output
			cout << "No entries match query " << "(" << element << ") in age" << endl;
}

void AgeHashTable::UPDATE(string element, string table)		//replaces entries in table with query 
{
	bool found = false;
	AgeEntry temp = SEPERATE(element);
	int index = key(temp);	//hash function
	for (int i = 0; i < data[index].size(); i++) //go through all of the hash until found
	{
		if (data[index][i].ID == temp.ID) { //found
			if (data[index][i].tombstone == true)
				break;
			else if (data[index][i].ID == temp.ID) { //found
				data[index][i] = temp;
				cout << "Updated(" << element << ") in age" << endl;
				found = true;
				break;
			}
			cout << "Failed to update (" << element << ") in age" << endl; //couldn't find)

		}
	}


}

void AgeHashTable::DELETE(string element, string table)	// deletes entry requested by query
{
	vector<AgeEntry> deletedEntries;
	AgeEntry temp = SEPERATE(element);
	AgeEntry it;
	for (int i = 0; i < list.length(); i++) //go through all of the collisions until found
	{
		it = *list.get(i);
		if (temp.ID == "*" || temp.ID == it.ID)
		{
			if (temp.child == "*" || temp.child == it.child)
			{
				if (temp.teen == "*" || temp.teen == it.teen)
				{
					if (temp.elder == "*" || temp.elder == it.elder)	//found a match
					{
						AgeEntry *pnt = list.get(i);
						pnt->tombstone = true;
						deletedEntries.push_back(it);
						list.erase(i);	
						i = -1;
					}

				}
			}
		}
	}
	if (deletedEntries.size() == 1)		//output one single entry if only one is present
		cout << "Deleted " << "(" << deletedEntries[0].ID << "," << deletedEntries[0].child << "," <<
		deletedEntries[0].teen << "," << deletedEntries[0].elder << ") in age" << endl;
	else if (deletedEntries.size() > 1) {		//output ALL entries if multiple were deleted
		cout << "Deleted entries:" << endl;
		for (int j = 0; j < deletedEntries.size(); j++)
		{
			
			cout << "(" << deletedEntries[j].ID << "," << deletedEntries[j].child << "," <<
				deletedEntries[j].teen << "," << deletedEntries[j].elder << ") in age" << endl;
		}
	}
	else
	{
		cout << "Failed to delete " << "(" << element << ") in age" << endl;
	}
}
AgeEntry AgeHashTable::SEPERATE(string data)		//seperates data into their respective strings
{
	string id = "";
	string f = "";
	string t = "";
	string old = "";
	stringstream ss(data);
	vector<string> result;

	while (ss.good())
	{
		string substr;
		getline(ss, substr, ',');
		result.push_back(substr);
	}
	id = result[0];
	f = result[1];
	t = result[2];
	old = result[3];
	return AgeEntry(id, f, t, old);
}

void AgeHashTable::DISPLAY()
{ 
	cout << endl;
	AgeEntry it;
	cout << left << setw(13) << "geo_geoid" << "under_5 under_18 over_65" << endl;
	for (int i = list.length(); i >= 0; i--) {
		it = *list.get(i);
		if (it.ID == "NoName")
			list.erase(i);
		else
		cout << left << setw(13) << it.ID << setw(8) << it.child <<
			setw(9) << it.teen << it.elder << endl;
			
		
	}
	cout << endl;
}

int AgeHashTable::key(AgeEntry Ident)		//generates key for index using modulo
{
	int index = stoi(Ident.ID.substr(7, Ident.ID.length()));
	index %= data.size();
	return index;
}