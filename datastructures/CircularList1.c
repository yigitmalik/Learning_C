#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int x;
    struct node *next;
}
node;

void print(node *r);
node *ekle(node *r, int x);
node *Delete(node *r,int x);

int main(void)
{
    node *root;
    root = NULL;

    root = ekle(root,5);
    root = ekle(root,50);
    root = ekle(root,450);
    root = ekle(root,300);
    root = ekle(root,700);
    root = ekle(root,650);

    print(root);

    root = Delete(root,5);
    print(root);
    root = Delete(root,300);
    print(root);
    root = Delete(root,800);
    print(root);
    Delete(root,700);
    print(root);

    free(root);

}

node *ekle(node *r, int x)
{
    if(r == NULL)
    {
        r = malloc(sizeof(node));
        r->next = r;
        r->x = x;

        return r;
    }
    if(r->x > x)
    {
        node *tmp = malloc(sizeof(node));
        tmp->x = x;
        tmp->next = r;
        node *iter = r;
        while(iter->next !=r)
        {
            iter = iter->next;
        }
        iter->next = tmp;
        return tmp;
    }

    node *iter = r;

    while(iter->next != r && iter->next->x < x)
    {
        iter = iter->next;
    }
    node *tmp = malloc(sizeof(node));
    tmp->next = iter->next;
    iter->next = tmp;
    tmp->x = x;

    return r;
}

node *Delete(node *r,int x)
{

    node *iter=r;
    node *tmp;
    if(r->x == x)
    {
        while(iter->next != r)
        {
            iter = iter->next;
        }
        iter->next = r->next;
        free(r);

        return iter->next;
    }
    while(iter->next != r && iter->next->x != x)
    {
        iter = iter->next;
    }
    if(iter->next == r)
    {
        printf("Not Found");
        return r;
    }
    tmp = iter->next;
    iter->next = iter->next->next;
    free(tmp);

    return r;
}

void print(node *r)
{
    node *iter = r;
        printf("%d ",iter->x);
        iter = iter->next;
    while(iter != r)
    {
        printf("%d ",iter->x);
        iter = iter->next;
    }
    printf("\n");

}
