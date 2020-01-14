#include "Storage.h"
#include "AgeHashTable.h"
#include "DisabilityHashTable.h"
#include "GeogHashTable.h"
extern AgeHashTable age;
extern DisHashTable dis;
extern GeogHashTable geog;

//File input function
void readInputFile(vector<string> &geogVector, vector<string> &ageVector, vector<string> &disabilityVector)
{
	ifstream inFile;
	char fileName1[20];
	bool run = false;
	string File1,File2,File3;
	string topic,file1Topic,file2Topic,file3Topic,query;
	
	//while loop that makes sure the correct file name was entered
	while (!run)
	{ 
		cout << "Please enter the main file's name:";
		cin.getline(fileName1,20);
		inFile.open(fileName1);
		if (inFile.fail())
		{
			cout << "The file provided was not found. Please try again..." << endl;
		}
		else
		{
			run = true;
		}
	}

	//Reading in the files and topicnames
	inFile >> File1;
	inFile >> topic;
	file1Topic = topicSorter(topic);	//sorts through the topics so that correct order is chosen
	inFile >> File2;
	inFile >> topic;
	file2Topic = topicSorter(topic);	//sorts through the topics so that correct order is chosen
	inFile >> File3;
	inFile >> topic;
	file3Topic = topicSorter(topic);	//sorts through the topics so that correct order is chosen

	cout << File1 << " " << file1Topic<<endl;	
	fileSorter(File1, geogVector, ageVector, disabilityVector);	//sorts through files so correct order is chosen
	cout << File2 << " " << file2Topic << endl;
	fileSorter(File2, geogVector, ageVector, disabilityVector);	//sorts through files so correct order is chosen
	cout << File3 << " " << file3Topic << endl;
	fileSorter(File3, geogVector, ageVector, disabilityVector);	//sorts through files so correct order is chosen
	
	inFile.ignore();
	inFile.ignore();
	getline(inFile,query);	//Reading in the query
	while (!inFile.eof())	//while loop that gets the commands from the file
	{
		queryReader(query);	
		getline(inFile, query);
	}
	inFile.close();
}

//function that sorts through the files so correct file is put in the correct vector
void fileSorter(string File, vector<string> &geogVector, vector<string> &ageVector, vector<string> &disabilityVector)
{
	if (File.at(0) == 'a')
	{
		ageStorage(ageVector, File);	
	}
	else if (File.at(0) == 'g')
	{
		geogStorage(geogVector, File);
	}
	else if (File.at(0) == 'd')
	{
		disabilityStorage(disabilityVector, File);
	}
}

//function that sorts through the topics and returns the correct topic
string topicSorter(string topic)
{
	if (topic.at(0) == 'g')
	{
		return topic;
	}
	else if (topic.at(0) == 'a')
	{
		return topic;
	}
	else if (topic.at(0) == 'd')
	{
		return topic;
	}
	else
	{
		return NULL;
	}
	
}
	//Inserting the vector into the hash table
void insertAge(vector<string> &ageVector)
{
	smatch matcher;
	string str = "age";
	regex ageData("(05000US.*|\\*),([0-9]*|\\*),([0-9]*|\\*),([0-9]*|\\*)");
	for (int i = 2; i < ageVector.size()-1; ++i)
	{
		regex_search(ageVector[i], matcher, ageData);
		string ageInsert = matcher[0];
		age.INSERT(ageInsert, str);
	}
}

//Inserting the vector into the hash table
void insertGeog(vector<string> &geogVector)
{
	smatch matcher;
	string str = "geography";
	regex geogData("([0-9]+|\\*),((\"(.+),(.+)\")|\\*),([a-z]{2}|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),(05000US[0-9]+|\\*),([0-9]+|\\*)");
	for (int i = 2; i < geogVector.size() - 1; ++i)
	{
		regex_search(geogVector[i], matcher, geogData);
		string geogInsert = matcher[0];
		geog.INSERT(geogInsert, str);
	}
}

//Inserting the vector into the hash table
void insertDisability(vector<string> &disabilityVector)
{
	smatch matcher;
	string str = "disability";
	regex disData("((\"(.+),(.+)\")|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*)");
	for (int i = 2; i < disabilityVector.size() - 1; ++i)
	{
		regex_search(disabilityVector[i], matcher, disData);
		string disabilityInsert = matcher[0];
		dis.INSERT(disabilityInsert, str);
	}
}

//legacy function
void csvFileReader(string File)
{
	string key;
	ifstream inFile;
	inFile.open(File);
	inFile >> key;
	while (inFile.good())
	{
		string line;
		getline(inFile, line,',');
		cout << line<<" ";
	}
}

//function that inputs file into the vector
void geogStorage(vector<string> &geogVector, string File)
{
	ifstream inFile;
	inFile.open(File);
	string line;
	cout << "Processing geography table" << endl;
	while (inFile.good())
	{
		getline(inFile,line);
		geogVector.push_back(line);
	}
	/*for (int i = 0; i < geogVector.size(); ++i)
	{
		cout << geogVector[i] << endl;
	}*/
	insertGeog(geogVector);
	inFile.close();
}

//function that inputs file into the vector
void ageStorage(vector<string> &ageVector, string File)
{
	ifstream inFile;
	inFile.open(File);
	string line;
	cout << "Processing age table" << endl;
	while (inFile.good())
	{
		getline(inFile, line);
		ageVector.push_back(line);
	}
	/*for (int i = 0; i < ageVector.size(); ++i)
	{
		cout << ageVector[i] << endl;
	}*/
	insertAge(ageVector);
	inFile.close();
}

//function that inputs file into the vector
void disabilityStorage(vector<string> &disabilityVector, string File)
{
	ifstream inFile;
	inFile.open(File);
	string line;
	cout << "Processing disability table" << endl;
	while (inFile.good())
	{
		getline(inFile, line);
		disabilityVector.push_back(line);
	}
	/*for (int i = 0; i < disabilityVector.size(); ++i)
	{
		cout << disabilityVector[i] << endl;
	}*/
	insertDisability(disabilityVector);
	inFile.close();
}

//main function that calls the hashtable functions to insert, delete, update, and select
void queryReader(string query)
{
	regex insertGeog("INSERT\\(\\((.*),(\"(.*)\"|(.*)),(.*),(.*),(.*),(.*),(.*),(.*)\\),geography\\)");
	regex insertAge("INSERT\\(\\((.*),(.*),(.*),(.*)\\),age\\)");
	regex insertDisability("INSERT\\(\\((\"(.*)\"|(.*)),(.*),(.*),(.*),(.*),(.*),(.*)\\),disability\\)");
	regex updateGeog("UPDATE\\(\\((.*),(\"(.*)\"|(.*)),(.*),(.*),(.*),(.*),(.*),(.*)\\),geography\\)");
	regex updateAge("UPDATE\\(\\((.*),(.*),(.*),(.*)\\),age\\)");
	regex updateDisability("UPDATE\\(\\((\"(.*)\"|(.*)),(.*),(.*),(.*),(.*),(.*),(.*)\\),disability\\)");
	regex selectGeog("SELECT\\(\\((.*),(\"(.*)\"|(.*)),(.*),(.*),(.*),(.*),(.*)\\),geography\\)");
	regex selectAge("SELECT\\(\\((.*),(.*),(.*),(.*)\\),age\\)");
	regex selectDisability("SELECT\\(\\((\"(.*)\"|(.*)),(.*),(.*),(.*),(.*),(.*),(.*)\\),disability\\)");
	regex deleteGeog("DELETE\\(\\((.*),(\"(.*)\"|(.*)),(.*),(.*),(.*),(.*),(.*),(.*)\\),geography\\)");
	regex deleteAge("DELETE\\(\\((.*),(.*),(.*),(.*)\\),age\\)");
	regex deleteDisability("DELETE\\(\\((\"(.*)\"|(.*)),(.*),(.*),(.*),(.*),(.*),(.*)\\),disability\\)");
	smatch matcher;

	if (query == "DISPLAY()")	//display function call
	{
		cout << "DISPLAY" << endl;
		geog.DISPLAY();
		age.DISPLAY();
		dis.DISPLAY();
	}
	else if (query == "WRITE()")	//write function call
	{
		cout << "WRITE" << endl;
		ofstream fout;
		fout.open("geog_out.csv");	//creates geog_out.csv file
		fout << "replan_id" << endl;
		fout << "replan_id," << "geo_name," <<"geo_stusab,"<<"geo_sumlev,"<<"geo_state,"<<"geo_county,"<<"geo_geoid,"<<"population"<< endl;	//outputs the schemes and labels
		GeogEntry iterate;	//creates iterator from the geog class
		for (int i = 0; i < geog.list.length(); i++)	//for loop that goes through the database
		{
			iterate = *geog.list.get(i); //get next node
			//outputs the corresponding items to the corresponding labels to the csv file
			fout << iterate.replan_id<<"," << '"' << iterate.geo_name << '"' <<","<<iterate.geo_stusab<<","<<iterate.geo_sumlev << "," <<iterate.geo_state << "," <<iterate.geo_county << "," <<iterate.geo_geoid << "," <<iterate.population<< endl;
		}
		fout.close();

		fout.open("age_out.csv");	//creates age_out.csv file
		fout << "geo_geoid" << endl;
		fout << "geo_geoid," << "under_5," << "under_18," << "over_65" << endl;	//outputs the schemes and labels to the csv file
		AgeEntry iterate1;	//creates iterator from the age class
		for (int i = 0; i < age.list.length(); i++)	//for loop that goes through the database
		{
			iterate1= *age.list.get(i);	//get next node
			//outputs the corresponding items to the corresponding labels to the csv file
			fout <<iterate1.ID<<","<< iterate1.child << "," << iterate1.teen << "," << iterate1.elder << endl;
		}
		fout.close();

		fout.open("disability_out.csv");	//creates disability_out.csv file
		fout << "geo_name" << endl;	
		//outputs the schemes and labels to the scv file
		fout << "geo_name," << "hearing_disability," << "vision_disability," << "cognitive_disability," << "ambulatory_disability," << "self_care_disability," << "independent_living_disability" << endl;
		DisEntry iterate2;	//creates iterator from the disability class
		for (int i = 0; i < dis.list.length(); i++)	//for loop that loops through the database
		{
			iterate2 = *dis.list.get(i);	//get next node
			//outputs the corresponding items to the corresponding labels to the csv file
			fout << '"' << iterate2.geo <<'"'<< ","<< iterate2.hearing << "," << iterate2.vision << "," << iterate2.cognitive << "," << iterate2.ambulatory << "," << iterate2.selfCare << "," << iterate2.independentLiving << endl;
		}
	}
	if (regex_match(query, insertGeog))	//matching the query to the geog insert and calling the geog hashtable function
	{
		string str = "geography";
		regex geogData("([0-9]+|\\*),((\"(.+),(.+)\")|\\*),([a-z]{2}|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),(05000US[0-9]+|\\*),([0-9]+|\\*)");	//regex for insert geog
		regex_search(query, matcher, geogData);
		string geogInsert = matcher[0];
		if (geogInsert[geogInsert.length() - 1] == ',')	//if there is a missing * add it to the end
		{
			geogInsert += "*";
		}
		geog.INSERT(geogInsert,str);	//hashtable function call
	}
	else if (regex_match(query, insertAge))	//matching the query to the age insert and calling the age hashtable function
	{
		string str = "age";
		regex ageData("(05000US.*|\\*),([0-9]*|.),([0-9]*|.),([0-9]*|.)");		//regex for insert age
		regex_search(query ,matcher, ageData);
		string ageInsert = matcher[0];
		if (ageInsert[ageInsert.length() - 1] == ',')	//if there is a missing * add it to the end
		{
			ageInsert += "*";
		}
		age.INSERT(ageInsert, str);	//hashtable function call
	}
	else if (regex_match(query, insertDisability))	//matching the query to the disability insert and calling the disability hashtable function
	{
		string str = "disability";
		regex disabilityData("((\"(.+),(.+)\")|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*)");	//regex insert disability 
		regex_search(query, matcher, disabilityData);
		string disabilityInsert = matcher[0];
		dis.INSERT(disabilityInsert,str);	//hashtable function call
	}
	else if (regex_match(query, updateGeog))	//matching the query to the geog update and calling the geog hashtable function
	{
		string str = "geography";
		regex geogData("([0-9]+|\\*),((\"(.+),(.+)\")|\\*),([a-z]{2}|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),(05000US[0-9]+|\\*),([0-9]+|\\*)");	//regex update geog
		regex_search(query, matcher, geogData);
		string geogUpdate = matcher[0];
		if (geogUpdate[geogUpdate.length() - 1] == ',')
		{
			geogUpdate += "*";
		}
		geog.UPDATE(geogUpdate,str);	//hashtable function call
	}
	else if (regex_match(query, updateAge))		//matching the query to the age update and calling the age hashtable function
	{
		string str = "age";
		regex ageData("(05000US.*|\\*),([0-9]*|.),([0-9]*|.),([0-9]*|.)");	//regex update age
		regex_search(query, matcher, ageData);
		string ageUpdate = matcher[0];
		if (ageUpdate[ageUpdate.length() - 1] == ',')	//if there is a missing * add it to the end
		{
			ageUpdate+= "*";
		}
		age.UPDATE(ageUpdate,str);	//hashtable function call

	}
	else if (regex_match(query, updateDisability))		//matching the query to the disability update and calling the disability hashtable function
	{
		string str = "disability";
		regex disabilityData("((\"(.+),(.+)\")|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*)");	//regex for update disability
		regex_search(query, matcher, disabilityData);
		string disabilityUpdate = matcher[0];
		if (disabilityUpdate[disabilityUpdate.length() - 1] == ',')	//if there is a missing * add it to the end
		{
			disabilityUpdate += "*";
		}
		dis.UPDATE(disabilityUpdate,str);	//hashtable function call
	}
	else if (regex_match(query, selectGeog))		//matching the query to the geog select and calling the geog hashtable function
	{
		string str = "geography";
		regex geogData("([0-9]+|\\*),((\"(.+),(.+)\")|\\*),([a-z]{2}|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),(05000US[0-9]+|\\*),([0-9]+|\\*)");	//regex for select geog
		regex_search(query, matcher, geogData);
		string geogSelect = matcher[0];
		if (geogSelect[geogSelect.length() - 1] == ',')	//if there is a missing * add it to the end
		{
			geogSelect += "*";
		}
		geog.SELECT(geogSelect,str);	//hashtable function call
	}
	else if (regex_match(query, selectAge))		//matching the query to the age select and calling the age hashtable function
	{
		string str = "age";
		regex ageData("(05000US.*|\\*),([0-9]*|.),([0-9]*|.),([0-9]*|.)");	//regex for select age
		regex_search(query, matcher, ageData);
		string ageSelect = matcher[0];
		if (ageSelect[ageSelect.length() - 1] == ',')	//if there is a missing * add it to the end
		{
			ageSelect+= "*";
		}
		age.SELECT(ageSelect, str);	//hashtable function call
	}
	else if (regex_match(query, selectDisability))		//matching the query to the disability select and calling the disability hashtable function
	{
		string str = "disability";
		regex disabilityData("((\"(.+),(.+)\")|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*)");	//regex for select disability
		regex_search(query, matcher, disabilityData);
		string disabilitySelect = matcher[0];
		if (disabilitySelect[disabilitySelect.length() - 1] == ',')	//if there is a missing * add it to the end
		{
			disabilitySelect += "*";
		}
		dis.SELECT(disabilitySelect,str);	//hashtable function call
	}
	else if (regex_match(query, deleteGeog))		//matching the query to the geog delete and calling the geog hashtable function
	{
		string str = "geography";
		regex geogData("([0-9]+|\\*),((\"(.+),(.+)\")|\\*),([a-z]{2}|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),(05000US[0-9]+|\\*),([0-9]+|\\*)");	//regex for delete geog
		regex_search(query, matcher, geogData);
		string geogDelete = matcher[0];
		if (geogDelete[geogDelete.length() - 1] == ',')	//if there is a missing * add it to the end
		{
			geogDelete += "*";
		}
		geog.DELETE(geogDelete,str);	//hashtable function call
	}
	else if (regex_match(query, deleteAge))		//matching the query to the age delete and calling the age hashtable function
	{
		string str = "age";
		regex ageData("(05000US.*|\\*),([0-9]*|.),([0-9]*|.),([0-9]*|.)");	//regex for delete age
		regex_search(query, matcher, ageData);
		string ageDelete = matcher[0];
		if (ageDelete[ageDelete.length()- 1]==',')//if there is a missing * add it to the end
		{
			ageDelete+= "*";
		}
		age.DELETE(ageDelete, str);	//hashtable function call
	}
	else if (regex_match(query, deleteDisability))		//matching the query to the disability delete and calling the disability hashtable function
	{
		string str = "disability";
		regex disabilityData("((\"(.+),(.+)\")|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*),([0-9]+|\\*)");	//regex for delete disability
		regex_search(query, matcher, disabilityData);
		string disabilityDelete = matcher[0];
		if (disabilityDelete[disabilityDelete.length() - 1] == ',')//if there is a missing * add it to the end
		{
			disabilityDelete += "*";
		}
		dis.DELETE(disabilityDelete,str);	//hashtable function call
	}
}