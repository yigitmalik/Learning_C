#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int x;
    struct node *next;
}
node;

void print(node *r);
// bağlı listelere  döngü ile eleman ekleme
// Adding data to linkled list with loop
int main(void)
{
    node *root;
    root = malloc(sizeof(node));
    root -> x = 0;
    node *iter;
    iter = root;
    for (int i = 1; i < 5; i++)
    {
        iter->next = malloc(sizeof(node));
        iter = iter -> next;
        iter -> x = i * 10;
        iter -> next = NULL;

    }

    print(root);
    
    free(root);
}
void print(node *r)
{
    while(r !=NULL)
    {
        printf("%d",r->x);
        r = r->next;
    }
}