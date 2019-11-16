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

    int size() const;

    int capacity() const;

    bool isEmpty() const;

    void pushBack(const T& item);

    void pushBack(T&& item);

    void popBack();

    T& getBack() const;

    typedef T* iterator;
    typedef const T* const_iterator;

    iterator begin();

    const_iterator begin() const;

    iterator end();

    const_iterator end() const;

    static const int SPARE_CAPACITY = 16;

private:
    T* items;
    int size_;
    int capacity_;
};


#include "List.tpp"

#endif //ADT_LIST_H
