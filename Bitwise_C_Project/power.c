//Ryan Schick
//CSCE 3600
//This function checks if passed in value is a power of two and determines the next highest integer that is a power of 2
#include <stdio.h>
#define bool int

bool powerOfTwo(unsigned int x)  //bool fuction to see if x is power of two using bitwise &
{
    int y = x-1;
    return x && (!(x&y));
}
void isPowerOfTwo(unsigned int num){        //function that determines what to print out and what higher 2 squared integer is 
    unsigned int count = 0;                          
    long unsigned int result = 0;
    if (powerOfTwo(num) == 1 )      //if num is a power of 2 print it out
    {
        printf("%d is a power of 2\n", num );
    }
    else{       //else if num is not a power of two, find the next higher integer that is
        printf("%d is not a power of 2\n",num);
        while(num != 0)
        {
            num >>= 1;
            count++;
        }
    result = (1 << count);
    printf("Next higher integer that is power of 2 is: %lu\n", result);
    }
}