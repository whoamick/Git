//#include "list.h"
template<typename T>
class Iterator {
protected:
    Node<T>* current;
public:
    Iterator(Node<T>* node) : current(node) {}
    Iterator& operator++() {
        current = current->next;
        return *this;
    }
    Iterator& operator--() {
        current = current->prev;
        return *this;
    }
    T& operator*() const {
        return current->data;
    }
    bool operator==(const Iterator& other) const {
        return current == other.current;
    }
    bool operator!=(const Iterator& other) const {
        return !(*this == other);
    }
};