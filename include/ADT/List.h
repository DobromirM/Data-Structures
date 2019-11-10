#ifndef ADT_LIST_H
#define ADT_LIST_H


template<typename T>
class List {

public:

    explicit List(int size = 0);

    List(const List& other);

    List(List&& other);

    List& operator=(const List& other);

    List& operator=(List&& other);

    ~List();

    T& operator[](int index);

    const T& operator[](int index) const;

    void resize(int newSize);

    void reserve(int newCapacity);

    static const int SPARE_CAPACITY = 16;
private:
    T* items;
    int size;
    int capacity;


};


#include "List.tpp"

#endif //ADT_LIST_H
