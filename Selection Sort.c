//
//  Selection Sort.c
//  Data Structure
//
//  Created by Harsh Fatepuria on 09/10/12.
//  Copyright (c) 2012 harsh.fatepuria@live.com. All rights reserved.
//

#include <stdio.h>

void selection(int *a,int n)
{
    int i,p,j,t;
    for(i=0; i<n-1; i++)
    {
        p=i;
        for(j=i+1; j<n; j++)
            if(a[p]>a[j])
                p=j;
        t=a[i];
        a[i]=a[p];
        a[p]=t;
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
    selection(a,n);
    printf("\n\nSorted array:\n");
    for(i=0; i<n; i++)
        printf("%d\t",a[i]);
    return 0;
}