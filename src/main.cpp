#include <iostream>
#include "sorting.h"
#include "search.h"
#include "graph.h"
#include "input_manager.h"

int main(){
    InputManager input;
    Sorting sorting;
    Search search;

    int choice;
    do{
        std::cout << "\n=== C++ Algorithm Hub ===\n";
        std::cout << "1. Sorting Algorithms\n";
        std::cout << "2. Searching Algorithms\n";
        std::cout << "3. Graph Algorithms\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose option: ";
        std::cin >> choice;

        switch(choice){
            case 1:{
                auto arr = input.getArrayFromUser();
                sorting.bubbleSort(arr);
                std::cout << "Bubble Sorted: "; sorting.printArray(arr);
                arr = input.getArrayFromUser();
                sorting.selectionSort(arr);
                std::cout << "Selection Sorted: "; sorting.printArray(arr);
                arr = input.getArrayFromUser();
                sorting.mergeSort(arr);
                std::cout << "Merge Sorted: "; sorting.printArray(arr);
                arr = input.getArrayFromUser();
                sorting.quickSort(arr);
                std::cout << "Quick Sorted: "; sorting.printArray(arr);
                break;
            }
            case 2:{
                auto arr = input.getArrayFromUser();
                std::cout << "Enter key: ";
                int key = input.getSingleValue();
                std::cout << "Linear Index: "<< search.linearSearch(arr,key) << "\n";
                std::sort(arr.begin(),arr.end());
                std::cout << "Binary Index: "<< search.binarySearch(arr,key) << "\n";
                std::cout << "Ternary Index: "<< search.ternarySearch(arr,key) << "\n";
                break;
            }
            case 3:{
                Graph g(6);
                g.addEdge(0,1,4); g.addEdge(0,2,3);
                g.addEdge(1,2,1); g.addEdge(1,3,2);
                g.addEdge(2,3,4); g.addEdge(3,4,2);
                g.addEdge(4,5,6);

                std::cout << "BFS from 0: "; g.BFS(0);
                std::cout << "DFS from 0: "; g.DFS(0);
                g.dijkstra(0);
                break;
            }
            case 0:
                std::cout << "Exiting...\n"; break;
            default:
                std::cout << "Invalid choice\n";
        }
    }while(choice!=0);

    return 0;
}
