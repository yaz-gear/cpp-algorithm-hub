#ifndef SORTING_H
#define SORTING_H

#include <vector>

class Sorting {
public:
    void bubbleSort(std::vector<int>& arr);
    void selectionSort(std::vector<int>& arr);
    void mergeSort(std::vector<int>& arr);
    void quickSort(std::vector<int>& arr);
    void printArray(const std::vector<int>& arr);

private:
    void mergeSortHelper(std::vector<int>& arr, int left, int right);
    void merge(std::vector<int>& arr, int left, int mid, int right);
    void quickSortHelper(std::vector<int>& arr, int low, int high);
    int partition(std::vector<int>& arr, int low, int high);
};

#endif
