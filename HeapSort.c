//
//  HeapSort.c
//  Data Structure
//
//  Created by Harsh Fatepuria on 21/11/12.
//  Copyright (c) 2012 harsh.fatepuria@live.com. All rights reserved.
//
 
#include <stdio.h>

void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

void heapify(int a[],int n)
{
    int i,child,parent;
    for(i=1; i<n; i++)
    {
        child=i;
        do {
            parent=(child-1)/2;
            if(a[parent]<a[child])
                swap(&a[parent],&a[child]);
            child=parent;
        } while (child!=0);
    }
}

void heapSort(int a[],int n)
{
    int i;
    for(i=n-1; i>0; i--)
    {
        swap(&a[0],&a[i]);
        heapify(a,i);
    }
}

int main()
{
    int n,i,a[10];
    printf("\nEnter size:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    heapify(a, n);
    heapSort(a, n);
    printf("\n\n");
    for(i=0; i<n; i++)
        printf("%d\t",a[i]);
    return 0;
}