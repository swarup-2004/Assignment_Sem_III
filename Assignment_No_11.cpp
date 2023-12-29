#include <iostream>

class JobQueue {
private:
    static const int MAX_SIZE = 10;
    int queue[MAX_SIZE];
    int front;
    int rear;

public:
    JobQueue() : front(-1), rear(-1) {}

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    void enqueue(int job) {
        if (isFull()) {
            std::cout << "Job queue is full. Cannot add more jobs.\n";
        } else {
            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear++;
            }
            queue[rear] = job;
            std::cout << "Job added successfully.\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Job queue is empty. No job to delete.\n";
        } else {
            int deletedJob = queue[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front++;
            }
            std::cout << "Job " << deletedJob << " deleted successfully.\n";
        }
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Job queue is empty.\n";
        } else {
            std::cout << "Job Queue: ";
            for (int i = front; i <= rear; ++i) {
                std::cout << queue[i] << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    JobQueue jobQueue;
    int choice, job;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add Job\n";
        std::cout << "2. Display Jobs\n";
        std::cout << "3. Delete Job\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter job number to add: ";
                std::cin >> job;
                jobQueue.enqueue(job);
                break;
            case 2:
                jobQueue.display();
                break;
            case 3:
                jobQueue.dequeue();
                break;
            case 4:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
