//
//  Merge sort.c
//  Data Structure
//
//  Created by Harsh Fatepuria on 09/10/12.
//  Copyright (c) 2012 harsh.fatepuria@live.com. All rights reserved.
//

#include <stdio.h>
 
void mergeSort(int *a,int l,int m,int h)
{
    int p,q,r,i,temp[100];
    p=l;
    q=m+1;
    r=0;
    while(p<=m && q<=h)
        temp[r++]=a[p]<a[q]?a[p++]:a[q++];
    while(p<=m)
        temp[r++]=a[p++];
    while(q<=h)
        temp[r++]=a[q++];
    for(i=l,r=0; i<=h; i++,r++)
        a[i]=temp[r];
}

void merge(int *a,int l,int h)
{
    int m;
    if(l<h)
    {
        m=(l+h)/2;
        merge(a,l,m);
        merge(a,m+1,h);
        mergeSort(a,l,m,h);
    }
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
    merge(a,0,n-1);
    printf("\n\nSorted array:\n");
    for(i=0; i<n; i++)
        printf("%d\t",a[i]);
    return 0;
}