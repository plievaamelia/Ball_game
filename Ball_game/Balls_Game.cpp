#include <iostream>
#include <vector>
#include <fstream>
#include "BallsGame_Header.h"

using namespace std;

// Конструктор узла
Node::Node(int c) {
    color = c;
    prev = nullptr;
    next = nullptr;
}

// Конструктор DoubleLinkedList
DoubleLinkedList::DoubleLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Деструктор
DoubleLinkedList::~DoubleLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Добавление в конец
void DoubleLinkedList::push_back(int color) {
    Node* newNode = new Node(color);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

// Удаление узла
void DoubleLinkedList::removeNode(Node* node) {
    if (node == nullptr) return;
    if (node->prev != nullptr) {
        node->prev->next = node->next;
    }
    else {
        head = node->next;
    }
    if (node->next != nullptr) {
        node->next->prev = node->prev;
    }
    else {
        tail = node->prev;
    }
    delete node;
    size--;
}

// Удаление цепочек
int DoubleLinkedList::removeChains() {
    int totalRemoved = 0;
    bool changed = true;
    while (changed) {
        changed = false;
        Node* current = head;
        while (current != nullptr) {
            Node* chainStart = current;
            int chainColor = current->color;
            int chainLength = 1;
            Node* temp = current->next;
            while (temp != nullptr && temp->color == chainColor) {
                chainLength++;
                temp = temp->next;
            }
            if (chainLength >= 3) {
                Node* toDelete = chainStart;
                for (int i = 0; i < chainLength; i++) {
                    Node* nextNode = toDelete->next;
                    removeNode(toDelete);
                    toDelete = nextNode;
                    totalRemoved++;
                }
                changed = true;
                current = toDelete;
            }
            else {
                current = current->next;
            }
        }
    }
    return totalRemoved;
}

// Счётчик цепочек из повторяющихся цветов
int DoubleLinkedList::countChains() const {
    int chains = 0;
    Node* current = head;
    while (current != nullptr) {
        int chainColor = current->color;
        int length = 1;
        Node* temp = current->next;
        while (temp != nullptr && temp->color == chainColor) {
            ++length;
            temp = temp->next;
        }
        if (length >= 3) {
            ++chains;
        }
        current = temp; 
    }
    return chains;
}
