#include <iostream>

template <typename T>
class PriorityQueue {
private:
    static const int MAX_SIZE = 10;
    struct QueueItem {
        T data;
        int priority;

        // Overloaded operator<=
        friend bool operator<=(const QueueItem& lhs, const QueueItem& rhs) {
            return lhs.priority <= rhs.priority;
        }
    };
    QueueItem queue[MAX_SIZE];
    int size;

public:
    PriorityQueue() : size(0) {}

    bool isFull() const {
        return (size == MAX_SIZE);
    }

    bool isEmpty() const {
        return (size == 0);
    }

    void enqueue(const T& item, int priority) {
        if (isFull()) {
            std::cout << "Priority queue is full. Cannot add more items.\n";
        } else {
            int index = size - 1;
            while (index >= 0 && queue[index] <= QueueItem{item, priority}) {
                queue[index + 1] = queue[index];
                index--;
            }
            queue[index + 1] = {item, priority};
            size++;
            std::cout << "Item added successfully.\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Priority queue is empty. No item to dequeue.\n";
        } else {
            std::cout << "Dequeued item: " << queue[0].data << " (Priority: " << queue[0].priority << ")\n";
            for (int i = 0; i < size - 1; ++i) {
                queue[i] = queue[i + 1];
            }
            size--;
        }
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Priority queue is empty.\n";
        } else {
            std::cout << "Priority Queue:\n";
            for (int i = 0; i < size; ++i) {
                std::cout << "Item: " << queue[i].data << " (Priority: " << queue[i].priority << ")\n";
            }
        }
    }
};

int main() {
    PriorityQueue<std::string> priorityQueue;
    int choice, priority;
    std::string item;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Enqueue Item\n";
        std::cout << "2. Dequeue Item\n";
        std::cout << "3. Display Items\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter item to enqueue: ";
                std::cin >> item;
                std::cout << "Enter priority: ";
                std::cin >> priority;
                priorityQueue.enqueue(item, priority);
                break;
            case 2:
                priorityQueue.dequeue();
                break;
            case 3:
                priorityQueue.display();
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
