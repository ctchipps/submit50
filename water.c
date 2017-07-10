#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Please enter the length of your shower as integer\n");
    int length = get_int();
    printf("The entered length is %i minutes\n",length);
    int bottles = (length * 12);
    printf("Each shower takes %i bottles \n", bottles);
}