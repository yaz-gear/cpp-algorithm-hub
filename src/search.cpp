#include "search.h"

// Linear Search
int Search::linearSearch(const std::vector<int>& arr,int key){
    for(int i=0;i<arr.size();i++)
        if(arr[i]==key) return i;
    return -1;
}

// Binary Search (assumes sorted)
int Search::binarySearch(const std::vector<int>& arr,int key){
    int l=0,r=arr.size()-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]<key) l=mid+1;
        else r=mid-1;
    }
    return -1;
}

// Ternary Search (assumes sorted)
int Search::ternarySearch(const std::vector<int>& arr,int key){
    int l=0,r=arr.size()-1;
    while(r>=l){
        int mid1 = l+(r-l)/3;
        int mid2 = r-(r-l)/3;
        if(arr[mid1]==key) return mid1;
        if(arr[mid2]==key) return mid2;
        if(key<arr[mid1]) r=mid1-1;
        else if(key>arr[mid2]) l=mid2+1;
        else { l=mid1+1; r=mid2-1;}
    }
    return -1;
}
