//Ty Rozell
//CSCE 3600.001
//This function will reverse a binary number's bits and print out the result

#include <stdio.h>

void reverseBit(unsigned int num)
{
    unsigned int reversed = num;    //stores the reversed number
    unsigned int originalNum = num; //keeps track on the original number for outputting
    unsigned int numShift = 0;      //keeps track of the number of bits shifted
    
    //while num is greater than zero, continue reversing 'num' and store the result in 'reversed'
    while(num > 0)
    {
        num = num >> 1;
        reversed = reversed << 1;
        reversed = reversed | (num & 1);    //append the last bit of 'num' to the end of 'reversed'
        numShift++;
    }

    //shift 'reversed' all the way to the left, cutting off the unnecessary leading bits and leaving only the reversed number
    reversed = reversed << (31 - numShift);

    //output results
    printf("%u with bits reversed is %u\n", originalNum, reversed);
}