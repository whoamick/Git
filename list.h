#pragma once
using namespace std;
#include <iostream>
template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;
    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    template <typename T>
    friend class Iterator;
    List();
    List(const List& other);
    List(const T* values, int length);
    ~List();
    void append(T value);
    void prepend(T value);
    void display();
    void swapElements(int index1, int index2);
    void deleteElement(int index);
    void clearlist();
    T getElementByIndex(int index);
    void setElementByIndex(int index, T& newvalue);
    friend std::ostream& operator<<(std::ostream& output, const List<T>& list);
    friend std::istream& operator>>(std::istream& input, List<T>& list);
    void wrtFile(const std::string& filename);
    void readFile(const std::string& filename);
    Node<T>* Begin() { return head; }
    Node<T>* End() { return tail; }

};
