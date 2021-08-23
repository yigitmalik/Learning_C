#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startsize;
    int endsize;
    int year = 0;
    
    // TODO: Prompt for start size
    do
    {
        startsize = get_int("Start size: ");
    }
    while (startsize < 9);
    
    // TODO: Prompt for end size
    do
    {
        endsize = get_int("End size: ");
    }
    while (startsize > endsize);
    
    // TODO: Calculate number of years until we reach threshold
    if (startsize == endsize)
    {
        year = 0;
    }
    else
    {
        do
        {
            year++;
            startsize = startsize + (startsize / 3) - (startsize / 4);
            
        }
        while (startsize < endsize);
    }
    // TODO: Print number of years
    
    printf("Years: %i\n", year);
    
    
}