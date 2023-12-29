#include <iostream>
using namespace std;

class Deque {
    int size;
    int* array;
    int front;
    int rear;

public:
    Deque(int size) : size(size), array(new int[size]), front(-1), rear(-1) {}

    ~Deque() {
        delete[] array;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    void insertRear(int val) {
        if ((rear + 1) % size == front) {
            cout << "Deque is full" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        array[rear] = val;
        cout << "Inserted element is " << val << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        cout << "Deleted element is " << array[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        int val = array[rear];
        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + size) % size;
        }
        cout << "Deleted element is " << val << endl;
    }

    void insertFront(int val) {
        if ((front - 1 + size) % size == rear) {
            cout << "Deque is full" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + size) % size;
        }
        array[front] = val;
        cout << "Inserted Element is " << val << endl;
    }

    void showDeque() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        int i = front;
        do {
            cout << array[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        cout << endl;
    }
};

void menu() {
    cout << "1. Insert at Rear\n2. Delete from front\n3. Delete from rear\n4. Insert at front\n5. Exit" << endl;
}

int main() {
    int size;
    cout << "Enter maximum size of the deque : ";
    cin >> size;
    Deque dq(size);
    int ch;
    do {
        menu();
        cout << "Enter your choice : ";
        cin >> ch;

        if (ch == 1) {
            int val;
            cout << "Enter the value :";
            cin >> val;
            dq.insertRear(val);
            dq.showDeque();
        } else if (ch == 2) {
            dq.deleteFront();
            dq.showDeque();
        } else if (ch == 3) {
            dq.deleteRear();
            dq.showDeque();
        } else if (ch == 4) {
            int val;
            cout << "Enter the value :";
            cin >> val;
            dq.insertFront(val);
            dq.showDeque();
        } else if (ch != 5) {
            cout << "Invalid choice!!!" << endl;
        }

    } while (ch != 5);
    return 0;
}
