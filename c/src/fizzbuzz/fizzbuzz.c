/*
    Typical fizz buzz program
    Print  Fizz if divisible by 3. Print Buzz if divisible by 5. 
    Print FizzBuzz if divisible by both. Otherwise print integer i 
    between 1 to 100 
*/

#include<stdio.h>

int main(int argc, void** args)
{
    for(int i=1; i < 101; i++)
    {
        if(i%3==0)
            printf("fizz");
        if(i%5==0)
            printf("buzz");
        if( i%3!=0 && i%5!=0 )
            printf("%d", i);
        printf("\n");
    }
    return 0;
}