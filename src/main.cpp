#include <iostream>
#include "ADT/List.h"

int main() {

    List<int> myList{4};
    myList[0] = 5;
    myList[1] = 10;
    myList[2] = 15;
    myList[3] = 20;

    List<int>::iterator ptr = myList.begin();

    for (int i = 0; i < 4; i++) {
        std::cout << *ptr << std::endl;
        ptr++;
    }

    return 0;
}