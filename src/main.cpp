#include <iostream>
#include "../include/ADT/List.h"

int main() {

    List<int> myList{2};
    myList[0] = 5;

    List<int> temp = myList;
    temp[0] = 1;

    std::cout << myList[0] << std::endl;
    std::cout << temp[0] << std::endl;
    return 0;
}