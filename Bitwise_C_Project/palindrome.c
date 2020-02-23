//Jason Durkee February 12, 2020
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//function that checks each bit
bool checkBit(unsigned int num, unsigned int shift) 
{
    if (num & (1 << (shift - 1)))
        return true;
    else
        return false;
}

void palindrome(unsigned int decimalNum)
{
    int left = 1; // Initialize left position 
    int right =32; // initialize right position
    int notPal = 0;
    int temp, i, binaryArr[32];
    printf("The binary representation is: ");
    for (i=31;i>=0;--i)	//for loop that converts the number into binary and stores into an array
    {
        temp = decimalNum>>i;
        if (temp&1)
        {
            binaryArr[i]=1;	//stores 1 into array
        }
        else
        {
            binaryArr[i]=0;	//stores 0 into array
        }
        printf("%d",binaryArr[i]);
    }
    printf(" \n");
    while (left < right) 
    { 
        if (checkBit(decimalNum, left) != checkBit(decimalNum, right))	//compares the two bits to make sure they are the same
        {
            printf("%d is not a palindrome\n",decimalNum); //prints if number is not a palindrome
            notPal = 1;
            break;
        }
        left++; 
        right--; 
    }
    if(notPal==0)	//if number is a palindrome, it prints out the following statement
    {
        printf("%d is a palindrome\n",decimalNum);
    }
}