#include "sorting.h"
#include <iostream>
#include <algorithm>

// Bubble Sort
void Sorting::bubbleSort(std::vector<int>& arr){
    int n = arr.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]) std::swap(arr[j], arr[j+1]);
        }
    }
}

// Selection Sort
void Sorting::selectionSort(std::vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        int min_idx = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx]) min_idx=j;
        }
        std::swap(arr[i], arr[min_idx]);
    }
}

// Merge Sort
void Sorting::mergeSort(std::vector<int>& arr){
    mergeSortHelper(arr,0,arr.size()-1);
}

void Sorting::mergeSortHelper(std::vector<int>& arr,int left,int right){
    if(left<right){
        int mid = left + (right-left)/2;
        mergeSortHelper(arr,left,mid);
        mergeSortHelper(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void Sorting::merge(std::vector<int>& arr,int left,int mid,int right){
    int n1 = mid-left+1;
    int n2 = right-mid;
    std::vector<int> L(n1), R(n2);
    for(int i=0;i<n1;i++) L[i]=arr[left+i];
    for(int i=0;i<n2;i++) R[i]=arr[mid+1+i];
    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

// Quick Sort
void Sorting::quickSort(std::vector<int>& arr){
    quickSortHelper(arr,0,arr.size()-1);
}

void Sorting::quickSortHelper(std::vector<int>& arr,int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quickSortHelper(arr,low,pi-1);
        quickSortHelper(arr,pi+1,high);
    }
}

int Sorting::partition(std::vector<int>& arr,int low,int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            std::swap(arr[i],arr[j]);
        }
    }
    std::swap(arr[i+1],arr[high]);
    return i+1;
}

// Print Array
void Sorting::printArray(const std::vector<int>& arr){
    for(int x: arr) std::cout << x << " ";
    std::cout << std::endl;
}
