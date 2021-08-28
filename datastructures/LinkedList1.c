#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int x;
    struct node *next;
}
node;
// bağlı listeler giriş
// first look to linked lists
int main(void)
{
    node *root;
    root = (node *)malloc(sizeof(node));
    root -> x = 10;
    root -> next = (node *)malloc(sizeof(node));
    root -> next -> x = 20;
    root -> next -> next = (node *)malloc(sizeof(node));
    root -> next -> next -> x = 30;

    node *iter;
    iter = root;
    printf("%d",iter->x);
    iter = iter-> next;
    printf("%d",iter->x);

    free(root);

}