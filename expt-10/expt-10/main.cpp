//
//  main.cpp
//  expt-10
//
//  Created by Parth Verma on 30/10/17.
//  Copyright © 2017 Parth Verma. All rights reserved.
//

#include <iostream>

using namespace std;

template <class T>
void swap(T *t1,T *t2) {
    T temp;
    temp = *t1;
    *t1=*t2;
    *t2=temp;
}
template <class T>
void bubble_sort(int n,T arr[]) {
    int i, j;
    for (i = 0; i < n-1; i++)
        
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

template <class T>
void selection_sort(int n,T arr[]) {
    int i, j, max_idx;
    for (i = 0; i < n-1; i++)
    {
        max_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] > arr[max_idx])
                max_idx = j;
        swap(&arr[max_idx], &arr[i]);
    }
}

int main(int argc, const char * argv[]) {
    int n;
    int arr[1000];
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    for (int i=0; i<n; i++) {
        cout<<"Enter element #"<<i+1<<": ";
        cin>>arr[i];
    }
    
    bubble_sort(n, arr);
    cout<<"\n\nSorted Array:\n";
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<' ';
    }
    selection_sort(n, arr);
    cout<<"\n\nReverse Sorted Array:\n";
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    return 0;
}
