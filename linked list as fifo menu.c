//
//  linked list menu.c
//  Data Structure
//
//  Created by Harsh Fatepuria on 20/08/12.
//  Copyright (c) 2012 harsh.fatepuria@live.com. All rights reserved.
//
 
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int no;
    struct node *n;
};

struct node * push(struct node *t,int num)
{
    struct node *p,*x;
    p=(struct node * )malloc(sizeof(struct node));
    if(p==NULL)
        printf("\nOverflow!\n");
    else
    {
        p->no=num;
        p->n=NULL;
        if(t==NULL)
            t=p;
        else
        {
            for(x=t; x->n; x=x->n);
            x->n=p;
        }
    }
    return t;
}

struct node * pop(struct node *t)
{
    struct node *x;
    if(t==NULL)
        printf("\nUnderflow!\n");
    else
    {
        printf("\nPopped: %d\n",t->no);
        x=t;
        t=t->n;
        free(x);
    }
    return t;
}

void display(struct node *t)
{
    struct node *p;
    for(p=t; p->n; p=p->n)
        printf("%d-->",p->no);
    printf("%d\n",p->no);
}

void disp_rev(struct node *t)
{
    if(t)
    {
        disp_rev(t->n);
        printf("%d\t",t->no);
    }
}

int main()
{
    struct node *t=NULL;
    int ch,num;
    do
    {
        printf("\nMENU:");
        printf("\n1.Push.");
        printf("\n2.Pop.");
        printf("\n3.Display.");
        printf("\n4.Display in reverse order.");
        printf("\n5.Exit");
        printf("\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter number: ");
                scanf("%d",&num);
                t=push(t,num);
                break;
            case 2:
                t=pop(t);
                break;
            case 3:
                if(t==NULL)
                    printf("\nLinked list is empty!\n");
                else
                {
                    printf("\nDisplaying linked list:\n");
                    display(t);
                }
                break;
            case 4:
                if(t==NULL)
                    printf("\nLinked list is empty!\n");
                else
                {
                    printf("\n\nDisplaying linked list in reverse order:\n");
                    disp_rev(t);
                    printf("\n");
                }
                break;
            case 5:
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (ch!=5);
    return 0;
}