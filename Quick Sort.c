//
//  Quick Sort.c
//  Data Structure
//
//  Created by Harsh Fatepuria on 09/10/12.
//  Copyright (c) 2012 harsh.fatepuria@live.com. All rights reserved.
//

#include <stdio.h>
void quick(int *a, int l, int h)
{
    int piv,p,q,t;
    piv=l;
    p=l;
    q=h;
    while(p<=q)
    {
        while(a[p]<=a[piv] && p<=q)
            p++;
        while(a[q]>=a[piv] && p<=q)
            q--;
        if(p<q)
        {
            t=a[p];
            a[p]=a[q];
            a[q]=t;
        }
    }
    t=a[q];
    a[q]=a[piv];
    a[piv]=t;
    if(l<q-1)
        quick(a,l,q-1);
    if(q+1<h)
        quick(a,q+1,h);
}

int main()
{
    int i,n,a[100];
    printf("\nEnter limit: ");
    scanf("%d",&n);
    printf("\n");
    for(i=0; i<n;i++)
    {
        printf("Enter number: ");
        scanf("%d",&a[i]);
    }
    printf("\nOriginal array:\n");
    for(i=0; i<n; i++)
        printf("%d\t",a[i]);
    quick(a,0,n-1);
    printf("\n\nSorted array:\n");
    for(i=0; i<n; i++)
        printf("%d\t",a[i]);
    return 0;
}