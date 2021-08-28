#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int x;
    struct node *next;
}
node;

void print(node *r);

int main(void)
{
    node *root;
    root = malloc(sizeof(node));
    root-> x = 5;
    node *iter;
    iter = root;

    for(int i = 1; i < 5; i++)
    {
        iter->next = malloc(sizeof(node));
        iter = iter->next;
        iter ->x = i * 10;
        iter->next =NULL;
    }

    print(root);
    // 5 10 20 30 40
    printf("\n");
    // olan listeye eleman ekleme
    node *iter2 = root;
    for(int i = 1; i < 3; i++)
    {
        iter2 = iter2 ->next;
    }
    node *tmp = malloc(sizeof(node));
    tmp->next = iter2->next;
    iter2->next = tmp;
    tmp -> x = 100;

    print(root);
    // 5 10 20 100 30 40


    free(root);

}
void print(node *r)
{
    while(r != NULL)
    {
        printf("%d ",r->x);
        r=r->next;
    }
}
