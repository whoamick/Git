#include "iterat.h"
template <typename T>
Iterator(Node<T>* node) : current(node) {}

        Iterator& operator++() {
            current = current->next;
            return *this;
        }
        Iterator& operator--() {
            current = current->prev;
            return *this;
        }
        T& operator*() {
            return current->data;
        }
        bool operator==(const Iterator& other) {
            return current == other.current;
        }
        bool operator!=(const Iterator& other)  {
            return !(*this == other);
        }

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }
};
