//
//  towers of hanoi.c
//  Data Structure
//
//  Created by Harsh Fatepuria on 27/08/12.
//  Copyright (c) 2012 harsh.fatepuria@live.com. All rights reserved.
//

#include <stdio.h>
void hanoi(char t1,char t2,char t3,int n)
{
    if(n==1)
        printf("\n Move top disk from Tower %c ----> %c",t1,t3);
    else
    {
        hanoi(t1,t3,t2,n-1);
        hanoi(t1,t2,t3,1);
        hanoi(t2,t1,t3,n-1);
    }
}


int main()
{
	 int n;
	 printf("\n Enter the no. of disks: ");
	 scanf("%d",&n);
     if(n<1)
     {
         printf("\n Nothing to move");
     }
     else
         hanoi('X', 'Y', 'Z', n);
    return 0;
}