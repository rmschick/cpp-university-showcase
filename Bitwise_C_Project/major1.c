#include <stdio.h>
#include "major1.h"

int main()
{
    int user_Input = 0;     //stores menu selection
    unsigned int num = -1;      //stores number between 0-2000000000 exclusive

    while(user_Input != 5)
    {
        do{                         
            printf("Enter the menu option for the operation to perform:\n");        //menu for program
            printf("(1) POWER OF 2\n");
            printf("(2) REVERSE BITS\n");
            printf("(3) REPLACE BIT POSITION FROM MASK\n");
            printf("(4) PALINDROME\n");
            printf("(5) EXIT\n");
            printf("--> ");
            scanf("%d", &user_Input);       //stores user input into user_Input var
            if(user_Input <1 || user_Input>5)
            {
                printf("Error: Invalid option. Please try again.\n");
            }
        } while(user_Input<1 || user_Input>5);

        if(user_Input == 5){ //if the user_Input is 5, then we need to break out the while loop to display exit program
            break;
        }else{
            do{ 
                printf("Enter a positive integer less than 2 billion: ");
                scanf("%d", &num);
            } while((num<1) || (num>1999999999));   //if the user inputted a number less than 1 or greater than 2 billion, loop back

            if(user_Input==1)       //call power of two function
            {
                isPowerOfTwo(num);
            }
            else if(user_Input == 2)        //call reverse bit function
            {
                reverseBit(num);
            }
            else if(user_Input == 3)       //call  replace bit position from mask function
            {
                replaceBit(num);
            }
            else if(user_Input == 4)      //call palindrome function
            {
                palindrome(num);
            }
        }
    }
    printf("Program terminating. Goodbye\n");
}