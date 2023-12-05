#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <fstream>
#include <string>

// Định nghĩa cấu trúc Node
template <typename T>
class Node
{
public:
    T data;
    Node* next;
    Node(const T& newData) : data(newData), next(nullptr) {}
};


template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    // Thêm một phần tử vào cuối danh sách
    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        ++size;
    }

    // Hiển thị danh sách
    void display() const {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Xóa danh sách
    void clear() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }

    // Hàm nhập dữ liệu từ file vào danh sách liên kết
    void readFromFile(const std::string& filename) {
        std::ifstream inputFile(filename);
        if (inputFile.is_open()) {
            T value;
            while (inputFile >> value) {
                push_back(value);
            }
            inputFile.close();
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }
};
#endif // LINKEDLIST_H
