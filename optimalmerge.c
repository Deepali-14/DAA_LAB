#include <stdio.h>
#include <malloc.h>

struct treenode
{
    struct treenode *lchild;
    struct treenode *rchild;
    int weight;
};
struct listnode
{
    struct listnode *prev;
    struct listnode *next;
    struct treenode *tn;
};
struct treenode *tree(struct listnode *list, int n);
struct treenode *least(struct listnode **list);
struct listnode *insert(struct listnode *list, struct treenode *pt);



int main()
{
    int n, i, weight;
    struct listnode *list = NULL ;
     struct listnode *t;
    struct treenode *pt;
    struct treenode *root;
    printf("Enter the total number of files to be merged: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) // initially start from 1
    {
        printf("Enter the total number of records in file %d:", i);
        scanf("%d", &weight);
        pt = (struct treenode *)malloc(sizeof(struct treenode));
        pt->lchild = NULL;
        pt->rchild = NULL;
        pt->weight = weight;

        list = insert(list, pt);
    }

    printf("The elements in the list: ");
    for (t = list;t != NULL; t = t->next)
        printf("%d ", t->tn->weight);

    root = tree(list, n);
    printf("\nThe total number of records in the merged file: %d", root->weight);

    return 0;
}

struct treenode *tree(struct listnode *list, int n)
{
    int i;
    struct treenode *pt;
    for (i = 1; i <= n - 1; i++)
    {
        pt = (struct treenode *)malloc(sizeof(struct treenode));
        pt->lchild = least(&list);
        pt->rchild = least(&list);
        pt->weight = ((pt->lchild)->weight + (pt->rchild)->weight);
        list = insert(list, pt);
    }
    return least(&list);
}

struct treenode *least(struct listnode **list)
{
    struct listnode *t, *tmin;
    int min;
    min = 99999;
    for (t = (*list); t != NULL; t = t->next)
    {
        if ((t->tn)->weight < min)
        {
            tmin = t;
            min = (tmin->tn)->weight;
        }
    }

    if (tmin->prev == NULL)
    {
        (*list) = tmin->next;

        if (tmin->next != NULL)
            (tmin->next)->prev = NULL;
    }
    else
    {
        (tmin->prev)->next = tmin->next;
        if (tmin->next != NULL)
            (tmin->next)->prev = tmin->prev;
    }
    return tmin->tn;
}

struct listnode *insert(struct listnode *list, struct treenode *pt)
{
    struct listnode *t=list, *tnew;
    tnew = (struct listnode *)malloc(sizeof(struct listnode));
    tnew->prev = NULL;
    tnew->next = NULL;
    tnew->tn = pt;
    if (list == NULL)
        list = tnew;
    else
    {
        while (t->next != NULL)
            t = t->next;

        t->next = tnew;
        tnew->prev = t;
    }
    return list;
}

