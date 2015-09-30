//
//  kWayMerge.c
//  Data Structure
//
//  Created by Harsh Fatepuria on 10/01/14.
//  Copyright (c) 2014 harsh.fatepuria@live.com. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
struct element
{
    int row;
    int col;
    int item;
};
int heapSize;

void bubbleSort(int *a,int n)
{
    int i,j,temp,c;
    c=1;
    for(i=0; i<n-1 && c; i++)
    {
        c=0;
        for(j=0; j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                c++;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}


void heapify(struct element *a,int i,int n)
{
    int temp,l,r,min;
    l=2*i;
    r=2*i+1;
    min=i;
    if(l<=n && a[l].item<a[min].item)
        min=l;
    if(r<=n && a[r].item<a[min].item)
        min=r;
    if(i!=min)
    {
        temp=a[i].item;
        a[i].item=a[min].item;
        a[min].item=temp;
        
        temp=a[i].col;
        a[i].col=a[min].col;
        a[min].col=temp;

        temp=a[i].row;
        a[i].row=a[min].row;
        a[min].row=temp;
        
        heapify(a, min, n);
    }
}

void buildHeap(struct element *array, int n)
{
    int i;
    for(i=n/2;i>=0; i--)
        heapify(array,i,n);
}

 
int delete(int **twoDArray, struct element *array, int c)
{
    int min=array[0].item;
    array[0].col++;
    if(array[0].col==c)
    {
        array[0].item=array[heapSize].item;
        array[0].col=array[heapSize].col;
        array[0].row=array[heapSize].row;
        heapSize--;
    }
    else
        array[0].item=twoDArray[array[0].row][array[0].col];
    heapify(array, 0, heapSize);
    return min;
}

int main()
{
    int i,j,r,c,**twoDArray;
    scanf("%d%d",&r,&c);
    heapSize=r-1;
    struct element *array=(struct element *)malloc(r*sizeof(struct element));
    twoDArray=(int **)malloc(r*sizeof(int *));
    for(i=0; i<r; i++)
    {
        twoDArray[i]=(int *)malloc(c*sizeof(int));
        for(j=0; j<c; j++)
            scanf("%d",&twoDArray[i][j]);
    }
    for(i=0; i<r; i++)
    {
        bubbleSort(twoDArray[i],c);
        array[i].item=twoDArray[i][0];
        array[i].col=0;
        array[i].row=i;
    }
    buildHeap(array, r-1);
    for(i=0; i<(r*c); i++)
        printf("%d\t",delete(twoDArray,array,c));
    for(i=0; i<r; i++)
        free(twoDArray[i]);
    free(twoDArray);
    free(array);
    return 0;
}