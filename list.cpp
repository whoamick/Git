#include "list.h"
template <typename T>
void List<T>::readFile(const std::string& filename) {
    std::ifstream file(filename);
    T value;
    while (file >> value) {
        append(value);
    }
}

template <typename T>
void List<T>::wrtFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return;
    }

    Node<T>* current = head;
    while (current != nullptr) {
        file << current->data << std::endl;
        current = current->next;
    }

    file.close();
    std::cout << "List has been written to the file." << std::endl;
}
template <typename T>
List<T>::List() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
List<T>::List(const List& other) : head(nullptr), tail(nullptr), size(0) {
    Node<T>* temp = other.head;
    while (temp != nullptr) {
        append(temp->data);
        temp = temp->next;
    }
}

template <typename T>
List<T>::List(const T* values, int length) {
    for (int i = 1; i <= length; ++i) {
        append(values[i]);
    }
}

template <typename T>
List<T>::~List() {
    clearlist();
}

template <typename T>
void List<T>::append(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

template <typename T>
void List<T>::prepend(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    size++;
}
template <typename T>
void List<T>::display() {
    if (head == nullptr) {
        std::cout << "Список пуст" << std::endl;
        return;
    }

    Node<T>* temp = head;
    int index = 1;
    while (temp != nullptr) {
        std::cout << "[" << index << "] " << temp->data << std::endl;
        temp = temp->next;
        ++index;
    }
}

template <typename T>
void List<T>::swapElements(int index1, int index2) {
    Node<T>* node1 = head;
    Node<T>* node2 = head;
    for (int i = 1; i < index1; ++i) {
        node1 = node1->next;
    }
    for (int i = 1; i < index2; ++i) {
        node2 = node2->next;
    }
    std::swap(node1->data, node2->data);
}

template <typename T>
void List<T>::deleteElement(int index) {
    if (index < 0 || index > size) {
        std::cout << "Invalid index. Out of range." << std::endl;
        return;
    }

    Node<T>* current = head;
    for (int i = 1; i < index; ++i) {
        current = current->next;
    }

    if (current == head) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
    }
    else if (current == tail) {
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
    }
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
    --size;
    cout << "Элемент удален" << endl;
}

template <typename T>
void List<T>::clearlist() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

template <typename T>
T List<T>::getElementByIndex(int index) {

    if (index < 0 || index >= size) {
        std::cout << "Invalid index. Out of range." << std::endl;

        return T();
    }

    Node<T>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
void List<T>::setElementByIndex(int index, T& newvalue) {
    if (index < 0 || index >= size) {
        std::cout << "Некорректный индекс элемента.\n";
        return;
    }

    Node<T>* current = head;
    int currentIndex = 0;
    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }

    if (current != nullptr) {
        current->data = current->data = newvalue;
        std::cout << "Элемент успешно изменен.\n";
    }
    else {
        std::cout << "Не удалось найти элемент с указанным индексом.\n";
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& output, const List<T>& list) {
    typename List<T>::Node* current = list.head;
    while (current != nullptr) {
        output << current->data << " ";
        current = current->next;
    }
    return output;
}

template <typename T>
std::istream& operator>>(std::istream& input, List<T>& list) {
    T value = 0;
    std::cout << "Enter value: ";
    input >> value;
    list.append(value);
    return input;
}

