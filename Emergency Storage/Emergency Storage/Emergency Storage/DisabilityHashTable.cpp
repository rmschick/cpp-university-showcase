//Hashing function: Direct Hashing
//Collision: Quadratic Probing
#include "DisabilityHashTable.h"

DisHashTable::DisHashTable() {
	data.resize(79); //allocateSpace
}

DisEntry::DisEntry(string g, string h, string v, string c, string a, string s, string i)
{
	geo = g;
	hearing = h;
	vision = v;
	cognitive = c;
	ambulatory = a;
	selfCare = s;
	independentLiving = i;
	tombstone = false;
}

DisEntry::DisEntry()
{
	geo = "NoName";	//key values
	hearing = "NoName";
	vision = "NoName";
	cognitive = "NoName";
	ambulatory = "NoName";
	selfCare = "NoName";
	independentLiving = "NoName";
}


void DisHashTable::INSERT(string element, string table)
{
	int j = 0;
	DisEntry temp = SEPERATE(element);
	int index = key(temp);
	if (data[index].geo == "NoName")		//if the hash entry at the index is empty
	{
		data[index] = temp;	//adds temp into HashTable
		list.append(&data[index]);  //adds new AgeEntry to secondary index
		cout << "Inserted(" << element << ") into disability" << endl;
	}
	else	//the index position is occupied: collision occured
	{
		for (int i = 0; i < data.size(); i++)
		{
			index = (temp.geo.length() + pow(j, 2));
			index %= data.size();	//hash function
			if (data[index].geo == "NoName")
			{
				data[index] = temp;	//adds temp into HashTable
				list.append(&data[index]);  //adds new AgeEntry to secondary index
				cout << "Inserted(" << element << ") into disability" << endl;
				break;
			}
			else if (data[index].geo != "NoName")
			{
				if (data[index].tombstone == true)
				{
					data[index] = temp; //adds temp into HashTable
					list.append(&data[index]);	//adds new AgeEntry to secondary index
					cout << "Inserted(" << element << ") into disability" << endl;
					break;
					
				}
				else if (temp.geo == data[index].geo)
				{
					cout << "Failed to insert (" << element << ") into disability" << endl;
					break;
				}
			}
			j = j + 1;
		}
	}
}

void DisHashTable::SELECT(string element, string table)		//search through entire hash table to find requested query
{
	vector<DisEntry> foundEntries;
	DisEntry temp = SEPERATE(element);
	DisEntry it;
	for (int i = 0; i < list.length(); i++) //go through all of the collisions until found
	{
		it = *list.get(i);
		if (temp.geo== "*" || temp.geo == it.geo)
		{
			if (temp.hearing == "*" || temp.hearing == it.hearing)
			{
				if (temp.vision == "*" || temp.vision == it.vision)
				{
					if (temp.cognitive == "*" || temp.cognitive == it.cognitive)
					{
						if (temp.ambulatory == "*" || temp.ambulatory == it.ambulatory)
						{
							if (temp.selfCare == "*" || temp.selfCare == it.selfCare)
							{
								if (temp.independentLiving == "*" || temp.independentLiving == it.independentLiving)		//everything matched so add to found vector
									foundEntries.push_back(temp);
							}
						}
						
					}
				}
			}
		}
	}
	if (foundEntries.size() == 1)		//output found entries
		cout << "Found " << "(" << foundEntries[0].geo << "," << foundEntries[0].hearing << "," <<
		foundEntries[0].vision << "," << foundEntries[0].cognitive << foundEntries[0].ambulatory <<
		foundEntries[0].selfCare << foundEntries[0].independentLiving << ") in disability" << endl;
	else if (foundEntries.size() > 1)	//if there was more than one found DisEntry, output all data
	{
		cout << "Found entries:" << endl;
		for (int j = 0; j < foundEntries.size(); j++)
		{
			cout << "Found " << "(" << foundEntries[0].geo << "," << foundEntries[0].hearing << "," <<
				foundEntries[0].vision << "," << foundEntries[0].cognitive << foundEntries[0].ambulatory <<
				foundEntries[0].selfCare << foundEntries[0].independentLiving << ") in disability" << endl;
		}
		foundEntries.clear();
	}
	else                  // no entries found output
		cout << "No entries match query " << "(" << element << ") in disability" << endl;
}

void DisHashTable::UPDATE(string element, string table)	//find and replace an ID requested by the query
{
	bool found = false;
	int j = 0;
	DisEntry temp = SEPERATE(element);
	int index = key(temp);	//hash function
	for (int i = 0; i < data.size(); i++)
	{
		if (data[index].geo == temp.geo) { //found
			if (data[index].tombstone == true)
			{
				cout << "Failed to update (" << element << ") in disability" << endl; //the requested update is on a deleted entry
				break;
			}
			else if (data[index].geo == temp.geo) //found
			{
				data[index] = temp;
				cout << "Updated(" << element << ") in disability" << endl;
				found = true;
				break;
			}

		}
		else {			//increase the index with Quadratic Probing 
			index = (temp.geo.length() + pow(j, 2));
			index %= data.size();
			j++;
		}
	}
	if (!found)
		cout << "Failed to update (" << element << ") in disability" << endl; //couldn't find
	
}

void DisHashTable::DELETE(string element, string table)		//Delete entry requested by query
{
	vector<DisEntry> deletedEntries;
	DisEntry temp = SEPERATE(element);
	DisEntry it;
	for (int i = 0; i < list.length(); i++) //go through all of the collisions until found
	{
		it = *list.get(i);
		if (temp.geo == "*" || temp.geo == it.geo)
		{
			if (temp.hearing == "*" || temp.hearing == it.hearing)
			{
				if (temp.vision == "*" || temp.vision == it.vision)
				{
					if (temp.cognitive == "*" || temp.cognitive == it.cognitive)
					{
						if (temp.ambulatory == "*" || temp.ambulatory == it.ambulatory)
						{
							if (temp.selfCare == "*" || temp.selfCare == it.selfCare)
							{
								if (temp.independentLiving == "*" || temp.independentLiving == it.independentLiving)	//All matched and will be deleted
								{
									DisEntry *pnt = list.get(i);
									pnt->tombstone = true;
									deletedEntries.push_back(it);
									list.erase(i);
									i = -1;
								}
							}
						}

					}
				}
			}
		}	
	}
	if (deletedEntries.size() == 1)	//if there is a single entry that was deleted, output it
		cout << "Deleted(" << deletedEntries[0].geo << "," << deletedEntries[0].hearing << "," <<
		deletedEntries[0].vision << "," << deletedEntries[0].cognitive << deletedEntries[0].ambulatory <<
		deletedEntries[0].selfCare << deletedEntries[0].independentLiving << ") in disability" << endl;
	else if (deletedEntries.size() > 1) {		//if there was MORE THAN ONE entry that was deleted, output all the data
		cout << "Deleted entries:" << endl;
		for (int j = 0; j < deletedEntries.size(); j++)
		{

			cout << "(" << deletedEntries[0].geo << "," << deletedEntries[0].hearing << "," <<
				deletedEntries[0].vision << "," << deletedEntries[0].cognitive << deletedEntries[0].ambulatory <<
				deletedEntries[0].selfCare << deletedEntries[0].independentLiving << ") in disability" << endl;
		}
	}
	else {	 //didn't find any entries to delete
		cout << "Failed to delete(" << element << ") in disability" << endl;
	}
}
DisEntry DisHashTable::SEPERATE(string data)
{
	string g,h, v, c, a, s, i;
	string word = "";
	vector<string> result;

	for (int i = 0; i < data.length(); i++)
	{
		if (data[i] != ',' || (data[i] == ',' && data[i + 1] == ' '))
			word += data[i];
		else
		{
			result.push_back(word);
			word = "";
		}
	}
	result.push_back(word);		//creates all the strings to equal their respective data
	string updatedGEO = "";
	string geograph = result[0];
	for (int i = 0; i < geograph.length(); i++)
	{
		if (geograph[i] != '"')
			updatedGEO += geograph[i];
	}
	g = updatedGEO;
	h = result[1];
	v = result[2];
	c = result[3];
	a = result[4];
	s = result[5];
	i = result[6];
	return DisEntry(g,h,v,c,a,s,i);
} 

void DisHashTable::DISPLAY()
{
	cout << endl;
	DisEntry it;
	cout << left << setw(45) << "geo_name" << "hearing_disability vision_disability cognitive_disability ambulatory_disability self_care_disability independent_living_disability" << endl;
	for (int i = list.length(); i >= 0; i--) {
		it = *list.get(i);
		if (it.geo == "NoName")
			list.erase(i);
		else 
			cout << left << setw(45) << it.geo << setw(19) << it.hearing <<
			setw(18) << it.vision << setw(21) << it.cognitive << setw(22) << it.ambulatory << setw(21) << it.selfCare <<
			 it.independentLiving << endl;


	}
	cout << endl;
}

int DisHashTable::key(DisEntry data) {		//generates key and index 
	int index = data.geo.length();
	return index;
}