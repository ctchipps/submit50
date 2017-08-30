#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //dimension card_number variable and take the input
    long long card_number;
    printf("Number: ");
    card_number = get_long_long();
    //get the length of the card number
    int length = log10(card_number) + 1;
    //printf("%i\n",length);
    //check for proper length, if not re-prompt
    if((length != 13) && (length != 15) && (length != 16))
    {
        printf("INVALID\n");
        return 0;
    }
    
        //Move the number into an array
        int array[length];
        for(int i = 0; i < length; i++)
        {
            int lastnumber = card_number % 10;
            //printf("%i\n", lastnumber);
            array[i] = lastnumber;
            card_number = card_number / 10;
        }
    
        //now go through and perform Luhns algorithm
        int everyother[length];
        int value = 0;
        for (int i = 1; i < length; i = i + 2)
        {
        everyother[i - 1] = (array[i]*2);
        //printf("%i\n",everyother[i-1]); 
        value = value + ((everyother[i-1] % 10) + (everyother[i-1]/10 % 10));
        }
        //printf("%i\n",value);
    
        int allothers[length];  
        int sumallothers = 0;
        int Luhncheck = 0;
        for (int i = 0; i < length; i = i + 2)
        {
        allothers[i] = array[i];
        //printf("%i\n",allothers[i]);
        sumallothers = sumallothers + allothers[i];
        //printf("%i\n",sumallothers);
        }
        //printf("%i\n",sumallothers);
        Luhncheck = sumallothers + value;
        Luhncheck = Luhncheck % 10;
        //printf("%i\n", Luhncheck);
    
        if (Luhncheck == 0) 
        {
            if( (array[length-1] == 3 && array[length-2] == 4) || (array[length-1] == 3 && array[length-2] == 7)  )
            {
                printf("AMEX\n");
            }
            else if( (array[length-1] == 5 && array[length-2] == 1) || (array[length-1] == 5 && array[length-2] == 2) || (array[length-1] == 5 && array[length-2] == 3) || (array[length-1] == 5 && array[length-2] == 4) || (array[length-1] == 5 && array[length-2] == 5) )
            {
                printf("MASTERCARD\n");
            }
            else if( array[length-1] == 4)
            {
                printf("VISA\n")  ;  
            }
        }
        else
        {
        printf("INVALID\n");
        return 0;
        }
    }


//int* MoveToArray(int length, long long card_number, int* array)
//{
//    //static int array[20];
//    for(int i = 0; i == length; i++)
//    {
//        int lastnumber = card_number % 10;
//        array[i] = lastnumber;
//        card_number = card_number / 10;
//    }
//    return array;
//}