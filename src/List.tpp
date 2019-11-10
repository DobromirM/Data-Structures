#ifndef ADT_LIST_TPP
#define ADT_LIST_TPP

#include "../include/ADT/List.h"

template<typename T>
List<T>::List(int size) : size{size}, capacity{size + SPARE_CAPACITY}, items{nullptr} {
    items = new T[capacity];
}

template<typename T>
List<T>::List(const List& other): size{other.size}, capacity(other.capacity), items{nullptr} {
    this->items = new T[capacity];
    for (int i = 0; i < other.size; i++) {
        this->items[i] = other.items[i];
    }
}

template<typename T>
List<T>::List(List&& other) : size{other.size}, capacity{other.capacity}, items{other.items} {
    other.items = nullptr;
    other.size = 0;
    other.capacity = 0;
}

template<typename T>
List<T>& List<T>::operator=(const List& other) {

    List copy = other;
    std::swap(*this, copy);

    return *this;
}

template<typename T>
List<T>& List<T>::operator=(List&& other) {

    std::swap(this->size, other.size);
    std::swap(this->capacity, other.capacity);
    std::swap(this->items, other.items);

    return *this;
}

template<typename T>
List<T>::~List() {
    delete[] items;
}

template<typename T>
void List<T>::resize(int newSize) {
    if (newSize > this->capacity) {
        this->reserve(newSize * 2 + 1);
    }

    this->size = newSize;
}

template<typename T>
void List<T>::reserve(int newCapacity) {

    if (newCapacity < this->size) {
        return;
    }

    T* newItems = new T[newCapacity];

    for (int i = 0; i < this->size; i++) {
        newItems[i] == std::move(this->items[i]);
    }

    this->capacity = newCapacity;
    std::swap(newItems, items);

    delete[] newItems;
}

template<typename T>
T& List<T>::operator[](int index) {
    return this->items[index];
}

template<typename T>
const T& List<T>::operator[](int index) const {
    return this->items[index];
}

#endif //ADT_LIST_TPP