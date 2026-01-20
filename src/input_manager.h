#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <vector>

class InputManager{
public:
    std::vector<int> getArrayFromUser();
    int getSingleValue();
    void waitForEnter();
};

#endif
