#include <stdio.h>
#include <time.h>
#include <math.h>

typedef int Item;
#define SIZE 100000
#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if less(B,A) exch(A,B);}

static Item *pq;
static int N;

void insertion_sort(Item *v, int l, int r){
    Item temp;
    int j, i;

    for (i = l; i<= r; i++){
        temp = v[i];

        for(j = i+1; j >= l && temp < v[j-1]; j--){
            v[j] = v[j-1];
        }
        v[j] = temp;
    }
}

void fixDown(int k, int N){
    
    while(2*k <= N){
        int j = 2 *k;

        if (j < N && less(pq[j], pq[j+1])) j++;

        if (!less(pq[j], pq[k])) break;

        exch(pq[k], pq[j]);
        k = j;
    }   
}

void heap_sort(Item *v, int l, int r){
    
}