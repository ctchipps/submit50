#include <cs50.h>
#include <stdio.h>

void space(int n);
void hashes(int n);

int main(void)
{
    printf("Height ");
    int height = get_int();
    while (height>23 || height <0)
    {
        if(height>23)
        {
            //printf("The height cannot be greater than 23, please try again\n");;
            printf("Height ");
            height = get_int();
        }
        else if(height<0)
        {
            //printf("The height cannot be negative, please try again\n");
            printf("Height ");
            height = get_int();
        }
    }
    //printf("You selected a pyramid of height %i \n", height);
    
    for(int i = 1; i <= height; i++)
    {
        space(height-i);
        hashes(i);
        printf(" ");
        printf(" ");
        hashes(i);
        printf("\n");
    }
}

void space(int n)
{
    for(int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void hashes(int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("#");
    }
}