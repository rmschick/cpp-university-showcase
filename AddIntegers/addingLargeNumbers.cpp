#include <iostream>
//#include <cmath>
//#include <iomanip>
#include <string>
#include <stack>          
/*#include <vector>         
#include <deque> */

using namespace std;

/*Function addingLargeNumbers() add two large numbers using stacks*/
static stack<int> addingLargeNumbers(stack<int> Numm1_stack, stack<int> Numm2_stack)
{
	//lnitialize carryy as 0 
	int carryy = 0;
	//Declare variables 
	stack<int> Resultt_stack; 
	int numb1, numb2, resultt_num, resultdgt;
	if (!Numm1_stack.empty() && !Numm2_stack.empty())
	{
		//Till any one of stack becomes empty
		while (!Numm1_stack.empty() && !Numm2_stack.empty())
		{
			numb1 = Numm1_stack.top(); numb2 = Numm2_stack.top();
			//Add Both stack tops with carryy 
			resultt_num = numb1 + numb2 + carryy;
			/*Push Last digit of result into stack Resultt_stack*/
			resultdgt = resultt_num % 10;
			Resultt_stack.push(resultdgt);
			//Store carry digit into carryy 
			carryy = resultt_num / 10;
			//Pop both stack tops
			Numm1_stack.pop();
			Numm2_stack.pop();
		}
	}
	//If Numm1_stack is not empty
	if (!Numm1_stack.empty())
	{
		//Till Numm1_stack becomes empty 
		while (!Numm1_stack.empty())
		{
			numb1 = Numm1_stack.top();
			//Add stack top with carryy to get result 
			resultt_num = numb1 + carryy;
			/*Push Last digit of result into stack Resultt_stack*/
			resultdgt = resultt_num % 10;
			Resultt_stack.push(resultdgt); 
			carryy = resultt_num / 10;
			//Pop stack top of Numm1_stack 
			Numm1_stack.pop();
		}
	}
	//If Numm2_stack is not empty 
	if (!Numm2_stack.empty()) {
		while (!Numm2_stack.empty()) {
		
			numb2 = Numm2_stack.top();
			//Add stack top with carryy to get result 
			resultt_num = numb2 + carryy;
			// Compute Last digit of result
			resultdgt = resultt_num % 10;
			/*Push Last digit of result into stack Resultt_stack*/
			Resultt_stack.push(resultdgt);
			//Store carry digit into carryy 
			carryy = resultt_num / 10;
			//Pop stack top of Numm2_stack 
			Numm2_stack.pop();
		}
	}
	//If carryy is not O 
	if (carryy != 0)
	{
		//Push carryy into Resultt_stack 
		Resultt_stack.push(carryy);
	}
	
	//Return Resultt stack 
	return Resultt_stack;		
}