//
// Created by ankit on 17-Nov-18.
//

#include "heap.h"
#include<stdio.h>
#include<conio.h>
void crheap(int [], int);
int createHeap(int[]);
void processheap(int [],int);
void main_heap()
{
    //clrscr();
    int k[50], n;
    heap:;
    int x;
    printf("\n"
           "1. Enter elements into heap\n"
           "2. Sort Heap\n"
           "3. Output array\n"
           "99. Main menu\n"
           "Enter yor selection: "
    );
    int x1;
    int output;
    scanf("%d", &x1);
    switch(x1){
        case 1:
            n = createHeap(k);
            goto heap;
        case 2:
            processheap(k,n);
            goto heap;
        case 3:
            processheap(k, n);
            goto heap;
        default:
            return;
    }
}

int createHeap(int k[]){
    int i, n;
    printf("\n Number of elements: ");
    scanf(" %d",&n);
    printf("\n Enter the elements in the heap: ");
    for(i=1;i<=n;i++)
        scanf(" %d",&k[i]);
    crheap(k,n);
    return n;
}

void crheap(int k[],int n)
{
    int i,q, parent,child,temp;
    for(q=2;q<=n;q++)
    {
        child=q;
        parent=(int)child/2;
        while(child >1 && k[child] > k[parent])
        {
            temp=k[child];
            k[child]= k[parent];
            k[parent]=temp;
            child=parent;
            parent=(int)child/2;
            if(parent < 1)
                parent=1;
        }
    }
    printf("\n Maximum Element: ");
    for(i=1;i<=n-(n-1);i++)
        printf("%5d",k[i]);
    printf("\n Final Heap: ");
    for(i=1;i<=n;i++)
        printf(" %3d",k[i]);
}

/* function to sort a heap */
void processheap(int k[],int n)
{
    int current,parent,child,i,maxnodes;
    for(maxnodes=n;maxnodes>=2;maxnodes--)
    {
        current=k[maxnodes];;
        k[maxnodes]=k[1];
        /* adjust the array to be a heap of size n-1 */
        parent=1;
        /* obtain the larger of the root's children */
        if (maxnodes-1 >= 3 && k[3] > k[2])
            child=3;
        else
            child = 2;
        /* move keys upwards to find place for current */
        while (child<=maxnodes-1 && k[child]>=current)
        {
            k[parent]=k[child];
            parent=child;
            child=child*2;
            if(child+1 <= maxnodes-1 && k[child+1] > k[child])
                child = child + 1;
        }
        k[parent]=current;
    } /* end of for */
    printf("\n The sorted array is : ");
    for(i=1;i<=n;i++)
        printf("%4d",k[i]);
    getch();
}