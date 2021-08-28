#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next;

}
node;

node *sequentially(node *r, int number);
void print(node *r);
node *Delete(node *r, int number);

int main(void)
{
    node *root;
    root = NULL;

    root = sequentially(root, 450);
    root = sequentially(root, 40);
    root = sequentially(root, 5);
    root = sequentially(root, 500);
    root = sequentially(root, 350);
    print(root);

    root = Delete(root,5);
    print(root);
    root = Delete(root,450);
    print(root);
    root = Delete(root,5555);
    print(root);
    root = Delete(root,500);
    print(root);

}
node *sequentially(node *r, int number)
{
    if(r == NULL)
    {
        r = malloc(sizeof(node));
        r->next = NULL;
        r->number = number;

        return r;
    }
    if(r->number > number)
    {
        node *tmp = malloc(sizeof(node));
        tmp->number = number;
        tmp->next = r;

        return tmp;
    }

    node *iter = r;

    while(iter->next != NULL && iter->next->number < number)
    {
        iter = iter->next;
    }
    node *tmp = malloc(sizeof(node));
    tmp->next = iter->next;
    iter->next = tmp;
    tmp->number = number;

    return r;

}
node *Delete(node *r, int number)
{
    node *tmp;
    node *iter = r;
    if(r->number == number)
    {
        tmp = r;
        r = r->next;
        free(tmp);
        return r;
    }
    while (iter->next != NULL && iter->next->number != number)
    {
        iter = iter->next;
    }
    if(iter->next == NULL)
    {
        printf("Not found");
        return r;
    }
    tmp = iter->next;
    iter->next = iter->next->next;
    free(tmp);
    return r;
}
void print(node *r)
{
    while(r != NULL)
    {
        printf("%d ",r->number);
        r=r->next;
    }
    printf("\n");
}