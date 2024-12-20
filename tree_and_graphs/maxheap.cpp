/**
 * This file include importan operations of max heap
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * This algorithm makes the subtree rooted at given index forllows the max heap property. 
 * Time complexity = o(logn)
 */
void maxHeapify(int A[], int n, int index){
    int left_child = 2 * index;
    int right_child = 2*index + 1;
    int largest = index;
    if( right_child <n && A[largest] < A[left_child] )
        largest = left_child;
     if (right_child <n && A[largest] < A[right_child])
        largest = right_child;
    if(index != largest){
       int temp = A[index];
        A[index] = A[largest];
        A[largest] = temp;
        maxHeapify(A, n, largest);
    }
}

// Time complexity O(nlogn)
void buildMaxHeap(int n, int A[]){
    for(int i = n/2; i--; i >= 0)
        maxHeapify(A,n,i);
}

// Time complexity O(logn)
void increareKey(int A[], int index, int key){
    A[index] += key;
    int parent_index = index/2;
    if(A[parent_index] >= A[index]) return;
    while(A[index/2] <= A[index]){
        parent_index = index /2;
        swap(A[index], A[parent_index]);
        index = parent_index;
    }
}
// Time complexity O(logn)
void ExtractMax(int A[], int heapsize){
    swap(A[0], A[heapsize]);
    //cout A[heapsize-1] for the max element
    //reduce heap size, dyanmic memmory
    maxHeapify(A, heapsize-1, 0);
}