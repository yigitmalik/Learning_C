#include <stdio.h>
#include <cs50.h>

void For(int n)
{
    
    for(int i=0; i < n; i++)
    printf("Hello\n");
  
}
void While(int n)
{
    int i=0;
    while(i < n)
    {
    printf("Bay");
    i++;
    }
}

int main(void)
{
    For(5);
    While(2);
}

