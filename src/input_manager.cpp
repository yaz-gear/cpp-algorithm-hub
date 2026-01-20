#include "input_manager.h"
#include <iostream>
#include <sstream>

std::vector<int> InputManager::getArrayFromUser(){
    std::vector<int> arr;
    std::string line;
    std::cout << "Enter numbers separated by space: ";
    std::cin.ignore();
    std::getline(std::cin,line);
    std::istringstream iss(line);
    int num;
    while(iss>>num) arr.push_back(num);
    return arr;
}

int InputManager::getSingleValue(){
    int val;
    std::cin >> val;
    return val;
}

void InputManager::waitForEnter(){
    std::cout << "Press Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}
