#ifndef ADT_LIST_TPP
#define ADT_LIST_TPP

#include <algorithm>
#include "ADT/List.h"

template<typename T>
List<T>::List(int size) : size_{size}, capacity_{size + SPARE_CAPACITY}, items{nullptr} {
    items = new T[capacity_];
}

template<typename T>
List<T>::List(const List& other): size_{other.size_}, capacity_(other.capacity_), items{nullptr} {
    this->items = new T[capacity_];
    for (int i = 0; i < other.size_; i++) {
        this->items[i] = other.items[i];
    }
}

template<typename T>
List<T>::List(List&& other) : size_{other.size_}, capacity_{other.capacity_}, items{other.items} {
    other.items = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

template<typename T>
List<T>& List<T>::operator=(const List& other) {

    List copy = other;
    std::swap(*this, copy);

    return *this;
}

template<typename T>
List<T>& List<T>::operator=(List&& other) {

    std::swap(this->size_, other.size_);
    std::swap(this->capacity_, other.capacity_);
    std::swap(this->items, other.items);

    return *this;
}

template<typename T>
List<T>::~List() {
    delete[] items;
}

template<typename T>
T& List<T>::operator[](int index) {
    return this->items[index];
}

template<typename T>
const T& List<T>::operator[](int index) const {
    return this->items[index];
}

template<typename T>
void List<T>::resize(int newSize) {
    if (newSize >= this->capacity_) {
        this->reserve(newSize * 2 + 1);
    }

    this->size_ = newSize;
}

template<typename T>
void List<T>::reserve(int newCapacity) {

    if (newCapacity < this->size_) {
        return;
    }

    T* newItems = new T[newCapacity];

    for (int i = 0; i < this->size_; i++) {
        newItems[i] == std::move(this->items[i]);
    }

    this->capacity_ = newCapacity;
    std::swap(newItems, items);

    delete[] newItems;
}

template<typename T>
int List<T>::size() const {
    return size_;
}

template<typename T>
int List<T>::capacity() const {
    return capacity_;
}

template<typename T>
bool List<T>::isEmpty() const {

    return size_ == 0;
}

template<typename T>
void List<T>::pushBack(const T& item) {

    if (size_ == capacity_) {
        resize(size_);
    }

    size_ = size_ + 1;
    items[size_] = item;
}

template<typename T>
void List<T>::pushBack(T&& item) {

    if (size_ == capacity_) {
        resize(size_);
    }

    size_ = size_ + 1;
    items[size_] = std::move(item);
}

template<typename T>
void List<T>::popBack() {
    size_ = size_ - 1;
}

template<typename T>
T& List<T>::getBack() const {
    return items[size_ - 1];
}

template<typename T>
typename List<T>::iterator List<T>::begin() {
    return &items[0];
}

template<typename T>
typename List<T>::const_iterator List<T>::begin() const {
    return &items[0];
}

template<typename T>
typename List<T>::iterator List<T>::end() {
    return &items[size()];
}

template<typename T>
typename List<T>::const_iterator List<T>::end() const {
    return &items[size()];
}

#endif //ADT_LIST_TPP