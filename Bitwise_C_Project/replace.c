//			by:	Christian Campbell	cdc0343
#include <stdio.h>
#include <stdint.h>
#include "major1.h"

void replaceBit(unsigned int num)
{
	unsigned long int mask;//up to 3 billion number mask
	int pos;//bit position
	unsigned long int temp;//temporary number
	unsigned long int allones = 4294967295;//puts 1 for all 32 bits
	do
	{
		printf("Enter a positive integer mask up to 3 billion: ");
		scanf("%lu", &mask);
	}while((mask < 1) || (mask > 2999999999));//mask is between 1 and 3 billion
	do
	{
		printf("Enter the bit replacement position from mask (0-indexed): ");
                scanf("%d", &pos);
        }while((pos < 0) || (pos > 31));//bit position is between 0 and 31

	temp = (mask>>pos)&1;//determines if the bit in this position is a 1 or 0

	if(temp == 1)//if position has a 1 in the mask
	{
		temp = temp<<pos;//put back into the correct position as the only 1 in the number
		num |= temp;//Bitwise OR to put the 1 in the correct position of the original number
	}
	else//if position has a 0 in the mask
	{
		temp = 1<<pos;//put a 1 in the correct position established
		allones = allones^temp;//Bitwise XOR with a 32 bit number with all 1's making it only a zero in the desired position
		num &= allones;//Bitwise AND to put the 0 in the correct position of the original number
	}

	printf("New integer with bit %d from mask %lu is %d\n", pos, mask, num);

	return;
}
