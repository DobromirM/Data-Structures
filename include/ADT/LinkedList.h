#ifndef ADT_LINKEDLIST_H
#define ADT_LINKEDLIST_H

#include <algorithm>

template<typename T>
class LinkedList {

public:

private:

    struct Node {

        T data;
        Node* next;
        Node* previous;

        Node(const T& d = T{}, Node* n = nullptr, Node* p = nullptr);

        Node(T&& d, Node* n = nullptr, Node* p = nullptr);

    };
};


#include "LinkedList.tpp"

#endif //ADT_LINKEDLIST_H
