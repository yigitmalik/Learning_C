#include <stdio.h>
#include <stdlib.h>

#define Size 5

int array[Size], top;

void push(int data);
void pop();
int peek();
void print();

int main (void)
{
    int secim;
    top = -1;
    while(1 == 1)
    {
        printf("\n1- Push");
        printf("\n2- Pop");
        printf("\n3- Peek");
        printf("\nMake your choice : ");
        scanf("%d", &secim);

        switch(secim)
        {
            case 1:
            {
                printf("\n Write a number : ");
                scanf("%d", &secim);
                push(secim);
                print();
                break;
            }
            case 2:
            {
                pop();
                print();
                break;
            }
            case 3:
            {
                printf("Top value => %d",peek());
                break;
            }
        }
    }
}

void push(int data)
{
    if(top + 1 == Size)
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;
        array[top] = data;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack is null");
    }
    else
    {
        top -= 1;
    }
}

int peek()
{
    return array[top];
}

void print()
{
    for(int i = 0;i < top+1; i++)
    {
        printf("%d ", array[i]);
    }
}