#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

bool isFull(int n, int *top) {
    if (*top == n) return true;
    else return false;
}


bool isEmpty(int *top) {
    if (*top == -1) return true;
    else return false;
}


void push(int *arr, int *top, int n, int data)
{
    if (!isFull(n, top)) {
        *top += 1;
        arr[*top] = data;
    } else {
        cout << "Stack overflow" << endl;
    }
}


void pop(int *arr, int *top)
{
    if (!isEmpty(top)) {
        cout << arr[*top] << endl;
        *top -= 1;
    } else {
        cout << "Stack underflow";
    }
}


void isTop(int *arr, int *top)
{
    cout << arr[*top];
}


void display(int *arr, int *top)
{
    cout << "[ ";
    for(int i = 0; i <= *top; ++i) {
        cout << arr[i] << " ";
    }
    cout << " ]" << endl;
}

int main() {
    int *top, n;
    int firstValue = -1;
    top = &firstValue;

    cout << "Enter the size of the array : ";
    cin >> n;

    int stack[n];

    auto start = high_resolution_clock::now();
    //inserting elements to the stack
    push(stack, top, n, 23);
    push(stack, top, n, 45);
    push(stack, top, n, 6);
    push(stack, top, n, 70);
    push(stack, top, n, 27);
    push(stack, top, n, 39);
    push(stack, top, n, 56);
    push(stack, top, n, 11);
    cout << endl;

    //display the stack
    display(stack, top);

    pop(stack, top);
    pop(stack, top);
    pop(stack, top);
    pop(stack, top);
    pop(stack, top);
    cout << endl;

    display(stack, top);

    push(stack, top, n, 18);
    push(stack, top, n, 87);
    push(stack, top, n, 29);
    push(stack, top, n, 40);
    cout << endl;

    display(stack, top);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time taken by the stack implemented using arrays : " << duration.count() << " microseconds" << endl;

    return 0;
}

