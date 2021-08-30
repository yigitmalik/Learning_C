#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *next;
    struct node *prev;
}
node;

node *ekle(node *r,int x);
void print(node *r);
node *Delete(node *r, int x);

int main(void)
{
    node *root;
    root= NULL;

    root = ekle(root,150);
    root = ekle(root,50);
    root = ekle(root,350);
    root = ekle(root,700);
    root = ekle(root,450);

    print(root);

    root = Delete(root,50);
    print(root);
    root = Delete(root,450);
    print(root);
    root = Delete(root,55);
    print(root);
    root = Delete(root,700);
    print(root);

    free(root);
}

node *ekle(node *r,int x)
{
    node *iter = r;
    node *tmp;
    if(r == NULL)
    {
        r = malloc(sizeof(node));
        r->next = NULL;
        r->prev = NULL;
        r->x= x;

        return r;
    }
    if(r->x > x)
    {
        tmp = malloc(sizeof(node));
        tmp->x = x;
        tmp->next = r;
        r->prev = tmp;

        return tmp;
    }
    while(iter->next != NULL && iter->next->x < x)
    {
        iter = iter->next;
    }
    tmp = malloc(sizeof(node));
    tmp->next = iter->next;
    iter->next = tmp;
    tmp->prev = iter;

    if(tmp->next !=NULL)
    {
        tmp->next->prev = tmp;
    }
    tmp->x = x;


    return r;
}

node *Delete(node *r, int x)
{
    node *tmp;
    node *iter = r;
    if(r->x == x)
    {
        tmp = r;
        r = r->next;
        free(tmp);
        return r;
    }
    while (iter->next != NULL && iter->next->x != x)
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
    if(iter->next != NULL)
    iter->next->prev = iter;

    return r;

}

void print(node *r)
{
    while(r !=NULL)
    {
        printf("%d ",r->x);
        r = r->next;
    }
    printf("\n");
}