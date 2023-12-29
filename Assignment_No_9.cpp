#include <iostream>

class CharStack {
private:
    char* stackArray;
    int capacity;
    int top;

public:
    CharStack(int size) {
        capacity = size;
        stackArray = new char[capacity];
        top = -1;
    }

    ~CharStack() {
        delete[] stackArray;
    }

    void push(char value) {
        if (top == capacity - 1) {
            std::cout << "Stack overflow!\n";
        } else {
            stackArray[++top] = value;
        }
    }

    char pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow!\n";
            return '\0';
        } else {
            return stackArray[top--];
        }
    }

    bool isEmpty() const {
        return top == -1;
    }
};

bool isBalanced(const std::string& expression) {
    CharStack charStack(expression.size());

    for (char ch : expression) {
        if (ch == '(' || ch == '[' || ch == '{') {
            charStack.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (charStack.isEmpty()) {
                return false;  // Unmatched closing parenthesis
            }

            char openChar = charStack.pop();

            if ((openChar == '(' && ch != ')') ||
                (openChar == '[' && ch != ']') ||
                (openChar == '{' && ch != '}')) {
                return false;  // Mismatched opening and closing parenthesis
            }
        }
    }

    return charStack.isEmpty();  // Expression is balanced if stack is empty at the end
}

int main() {
    int choice;
    std::string expression;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Check Expression\n";
        std::cout << "2. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the expression: ";
                std::cin >> expression;
                if (isBalanced(expression)) {
                    std::cout << "The expression is well-balanced.\n";
                } else {
                    std::cout << "The expression is not well-balanced.\n";
                }
                break;
            case 2:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 2);

    return 0;
}
