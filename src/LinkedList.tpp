#include "ADT/LinkedList.h"

template<typename T>
LinkedList<T>::Node::Node(const T& d, LinkedList::Node* n, LinkedList::Node* p) : data{d}, next{n}, previous{p} {

}

template<typename T>
LinkedList<T>::Node::Node(T&& d, LinkedList::Node* n, LinkedList::Node* p): data{std::move(d)}, next{n}, previous{p} {

}


