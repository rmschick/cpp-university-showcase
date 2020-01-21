/* 	Ryan Schick
	Year 3
This program is used to find sum of large numbers by using vector of stacks */
#include "addingLargeNumbers.cpp"
	
using namespace std;

	int main()
	{
		//Declare variables 
		stack<int> Numm1_stackk, Numm2_stackk, Resultt_stackk; 
		char numm; 
		int numOfele;
		//Prompt and read input from user 
		cout << "Enter number of large numbers to add: ";
		cin >> numOfele;
		//Prompt and Read first number from user 
		cout << "Enter number: ";
		cin.ignore(); 
		cin.get(numm);
		while (numm !='\n'&& numm!= ' ')
		{
			//Push each digits into stack Numm1_stackk 
			Numm1_stackk.push(numm - 48);
			//Read next digit from user
			cin.get(numm);
		}
		numOfele--; 
		//Prompt and Read second number from user 
		cout << "Enter Number: ";
		cin.get(numm); 
		while (numm !='\n'&& numm!= ' ')
		{
			//Push each digits into stack Numm2_stackk 
			Numm2_stackk.push(numm - 48);
			cin.get(numm);
		}
		numOfele--; 
		/*Call function addingLargeNumbers() to add first two numbers*/ 
		Resultt_stackk= addingLargeNumbers(Numm1_stackk,Numm2_stackk); 
		while (!Numm2_stackk.empty()) {
			Numm2_stackk.pop();
		}

		while (!Resultt_stackk.empty()) {
			//Pop stacktop and store in ele 
			int ele = Resultt_stackk.top(); 
			Resultt_stackk.pop(); 
			Numm2_stackk.push(ele);
		}
		while (numOfele > 0) {
	 
			while(!Numm1_stackk.empty()) 
			{
				Numm1_stackk.pop();
			}
			/*Prompt and read number from user and store in stack Numm1_stackk*/ 
			cout << "Enter Number: "; 
			cin.get(numm);
		
			while (numm != '\n'&& numm != ' ')
			{
				//Push each digits into stack Numm1_stackk
				Numm1_stackk.push(numm - 48);
				//Read next digit from user 
				cin.get(numm);
			}
				numOfele--; 
				/*Call function addingLargeNumbers() to add each number with resultant number*/
				Resultt_stackk=addingLargeNumbers(Numm1_stackk, Numm2_stackk);
				 
				while (!Numm2_stackk.empty()) {
					Numm2_stackk.pop();
				}
				
				while(!Resultt_stackk.empty())
				{ 
						//Pop stack top and store in ele 
						int ele=Resultt_stackk.top();
						//Pop stack top of Resultt_stack 
						Resultt_stackk.pop(); 
						Numm2_stackk.push(ele);

				}
		} 
		while (!Numm2_stackk.empty())
		{
			//Pop stack top and store in ele 
			int ele = Numm2_stackk.top();
			Numm2_stackk.pop();
			//Push ele into stack Resultt_stackk 
			Resultt_stackk.push(ele);
		} 
		cout<<"Sum of numbers is: ";  
		while (!Resultt_stackk.empty())
		{
			//Print stack top of Resultt_stack
			cout << Resultt_stackk.top();
			Resultt_stackk.pop();
		}
		cout << endl;
		//Return from program
		system("pause");
		return 0;
	}
