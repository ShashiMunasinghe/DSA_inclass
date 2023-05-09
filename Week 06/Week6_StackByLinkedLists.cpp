#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

class Node {
public:
    int key;
    Node *next;
};

class Stack {
private:
    Node *top;
public:
    Stack() {
        top = NULL;
    }


    bool isEmpty(Node *top)
    {
        if (top == NULL) return true;
        else return false;
    }


    void push(int value)
    {
        Node *newNode = new Node();
        newNode -> key = value;
        if (top == NULL) {
            top = newNode;
        } else {
            newNode -> next = top;
            top = newNode;
        }
    }

    void pop()
    {
        if (isEmpty(top)) cout << "Stack underflow" << endl;
        else {
            cout << top -> key << endl;
            top = top -> next;
        }
    }

    void isTop(Node *top)
    {
        cout << top -> key << endl;
    }

    void display(){
        cout << "[ ";
        Node *temp = top;
        while (temp != NULL) {
            cout << temp -> key << " ";
            temp = temp -> next;
        }
        cout << "]" << endl;
    }

};

int main() {
    Stack stack;

    auto start = high_resolution_clock::now();

    stack.push(23);
    stack.push(45);
    stack.push(6);
    stack.push(70);
    stack.push(27);
    stack.push(39);
    stack.push(56);
    stack.push(11);

    stack.display();
    cout << endl;

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    cout << endl;

    stack.display();

    stack.push(18);
    stack.push(87);
    stack.push(29);
    stack.push(40);
    cout << endl;

    stack.display();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time taken by the stack implemented using linkedlists: " << duration.count() << " microseconds" << endl;

    return 0;
}
