//
//  Insertion Sort.c
//  Data Structure
//
//  Created by Harsh Fatepuria on 09/10/12.
//  Copyright (c) 2012 harh.fatepuria@live.com. All rights reserved.
//

#include <stdio.h>
void insertion(int *a,int n)
{
    int i,j,t;
    for(i=1; i<n; i++)
    {
        t=a[i];
        for(j=i-1; j>=0 && t<a[j]; j--)
            a[j+1]=a[j];
        a[j+1]=t;
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
    insertion(a,n);
    printf("\n\nSorted array:\n");
    for(i=0; i<n; i++)
        printf("%d\t",a[i]);
    return 0;
}