#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 100000;

class ArrayStack {
private:
    int top;
    int arr[MAX_SIZE];

public:
    ArrayStack() {
        top = -1;
    }

    bool push(int val) {
        if (top >= MAX_SIZE - 1) {
            return false;
        }
        top++;
        arr[top] = val;
        return true;
    }

    bool pop() {
        if (top < 0) {
            return false;
        }
        top--;
        return true;
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() {
        top = NULL;
    }

    bool push(int val) {
        Node* newNode = new Node(val);
        if (newNode == NULL) {
            return false;
        }
        newNode->next = top;
        top = newNode;
        return true;
    }

    bool pop() {
        if (top == NULL) {
            return false;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        return true;
    }

    void display() {
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    // Timing measurements  array-based stack
    auto arr_start = chrono::high_resolution_clock::now();
    ArrayStack arr_stack;
    for (int i = 0; i < 100000; i++) {
        arr_stack.push(rand() % 100);
    }
    for (int i = 0; i < 5; i++) {
        arr_stack.pop();
    }
    for (int i = 0; i < 100000; i++) {
        arr_stack.push(rand() % 100);
    }
    auto arr_end = chrono::high_resolution_clock::now();
    auto arr_time = chrono::duration_cast<chrono::microseconds>(arr_end - arr_start).count();
    cout << "Time taken by array-based: " << arr_time << " micro_seconds" << endl;

    // Timing measurements  linked list-based stack
    auto ll_start = chrono::high_resolution_clock::now();
    LinkedListStack ll_stack;
    for (int i = 0; i < 100000; i++) {
        ll_stack.push(rand() % 100);
    }
    for (int i = 0; i < 5; i++) {
        ll_stack.pop();
    }
    for (int i = 0; i < 100000; i++) {
        ll_stack.push(rand() % 100);
    }
    auto ll_end = chrono::high_resolution_clock::now();
    auto ll_time = chrono::duration_cast<chrono::microseconds>(ll_end - ll_start).count();
    cout << "Time taken by linked list-based : " << ll_time << " micro_seconds" << endl;

    return 0;
}
