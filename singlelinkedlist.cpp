#include <iostream>
#include <stdexcept>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value, Node* nextPtr = nullptr) {
        data = value;
        next = nextPtr;
    }
};

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void addAtFront(T value) {
        Node<T>* newNode = new Node<T>(value, head);
        head = newNode;
    }

    void addAtEnd(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    T removeFirst() {
        if (head == nullptr) {
            throw std::underflow_error("List is empty");
        }
        T tempData = head->data;
        Node<T>* oldHead = head;
        head = head->next;
        delete oldHead;
        return tempData;
    }

    T removeLast() {
        if (head == nullptr) {
            throw std::underflow_error("List is empty");
        }
        if (head->next == nullptr) { // Single node
            return removeFirst();
        }
        Node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        T tempData = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        return tempData;
    }

    void displayList() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    int size() const {
        int count = 0;
        Node<T>* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    Node<T>* find(T value) const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};

// Test the functions
int main() {
    SinglyLinkedList<int> l1;

    l1.addAtFront(5);
    l1.addAtFront(10);
    l1.addAtEnd(20);
    l1.addAtFront(30);

    l1.displayList(); // Output: 30 -> 10 -> 5 -> 20 -> NULL

    std::cout << "Size: " << l1.size() << std::endl; // Output: Size: 4

    l1.removeFirst(); // Removes 30
    l1.removeLast();  // Removes 20

    l1.displayList(); // Output: 10 -> 5 -> NULL

    std::cout << "Size: " << l1.size() << std::endl; // Output: Size: 2

    int val;
    std::cout << "Enter the number to find: ";
    std::cin >> val;
    if (l1.find(val) != nullptr) {
        std::cout << "Entered value is on the list" << std::endl;
    } else {
        std::cout << "Entered value is not on the list" << std::endl;
    }

    return 0;
}
