//
//  matrixchain.c
//  Data Structure
//
//  Created by Harsh Fatepuria on 09/08/13.
//  Copyright (c) 2013 harsh.fatepuria@live.com. All rights reserved.
//


#include <stdio.h>
int p[10]={0};
int min=22222;
int m[10][10]={{0}},s[10][10]={{0}};
int n;
void mcm(int i,int j)
{
    int k,a;
    if(j==i)
        m[i][j]= 0;
    else if(j==i+1)
        m[i][j]=(p[i-1]*p[i]*p[i+1]);
    else
    {
        min=22222;
        for(k=i; k<j; k++)
        {
            a=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
            if(a<min)
            {
                min=a;
                s[i][j]=k;
            }
        }
        m[i][j]=min;
    }
}

void mcorder(int i,int j)
{
    if (i == j)
        printf("A%d",i);
    else if (j == i + 1)
        printf("(A%d.A%d)",i,j);
    else{
        printf("(");
        mcorder(i, s[i][j]);
        mcorder(s[i][j] + 1, j);
        printf(")");
    }
}


int main()
{
    int i,k,j;
    printf("\nEnter n: ");
    scanf("%d",&n);
    for(i=0; i<=n; i++)
        scanf("%d",&p[i]);
    
    
    for(j=1; j<=n;j++)
        for(i=1;i<=(n-j+1); i++)
            mcm(i,j+i-1);
    
    
    j=m[1][n];
    for(i=0; i<=n; i++)
        printf("%d\t",p[i]);
    
    printf("\n\nm[][]:\n");
    for(i=1; i<=n; i++)
    {
        for(k=1; k<=n; k++)
            printf("%d\t",m[i][k]);
        printf("\n");
    }
    printf("\nS[][]:\n");
    for(i=1; i<=n; i++)
    {
        for(k=1; k<=n; k++)
            printf("%d\t",s[i][k]);
        printf("\n");
    }
    
    printf("\nMinimum number of scalar multiplications: %d\nOrder of multiplication:  ",j);
    mcorder(1,n);
    return 0;
}