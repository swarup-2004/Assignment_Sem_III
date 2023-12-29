#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = prev = nullptr;
    }
};

class BinaryList {
private:
    Node* head;

public:
    BinaryList() {
        head = nullptr;
    }

    void insertAtEnd(int bit) {
        Node* newNode = new Node(bit);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }

    BinaryList computeOnesComplement() {
        BinaryList result;
        Node* temp = head;
        while (temp) {
            result.insertAtEnd(temp->data == 0 ? 1 : 0);
            temp = temp->next;
        }
        return result;
    }

    BinaryList computeTwosComplement() {
        BinaryList onesComplement = computeOnesComplement();
        BinaryList twosComplement = onesComplement;

        int carry = 1;
        Node* temp = twosComplement.head;
        while (temp) {
            int sum = temp->data + carry;
            temp->data = sum % 2;
            carry = sum / 2;
            temp = temp->next;
        }

        if (carry > 0) {
            twosComplement.insertAtEnd(carry);
        }

        return twosComplement;
    }

    static BinaryList addBinary(BinaryList& num1, BinaryList& num2) {
        BinaryList result;
        int carry = 0;

        Node* temp1 = num1.head;
        Node* temp2 = num2.head;

        while (temp1 || temp2) {
            int sum = carry + (temp1 ? temp1->data : 0) + (temp2 ? temp2->data : 0);
            result.insertAtEnd(sum % 2);
            carry = sum / 2;

            if (temp1) temp1 = temp1->next;
            if (temp2) temp2 = temp2->next;
        }

        if (carry > 0) {
            result.insertAtEnd(carry);
        }

        return result;
    }
};

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Input Binary Numbers\n";
    cout << "2. Display Binary Numbers\n";
    cout << "3. Compute Ones Complement\n";
    cout << "4. Compute Twos Complement\n";
    cout << "5. Add Binary Numbers\n";
    cout << "6. Exit\n";
}

int main() {
    BinaryList binaryNum1, binaryNum2;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int bit, n;

                cout << "Enter the number of bits for Binary Number 1: ";
                cin >> n;
                cout << "Enter the bits for Binary Number 1 (from MSB to LSB): ";
                for (int i = 0; i < n; ++i) {
                    cin >> bit;
                    binaryNum1.insertAtEnd(bit);
                }

                cout << "Enter the number of bits for Binary Number 2: ";
                cin >> n;
                cout << "Enter the bits for Binary Number 2 (from MSB to LSB): ";
                for (int i = 0; i < n; ++i) {
                    cin >> bit;
                    binaryNum2.insertAtEnd(bit);
                }

                break;
            }
            case 2:
                cout << "Binary Number 1: ";
                binaryNum1.display();
                cout << "Binary Number 2: ";
                binaryNum2.display();
                break;
            case 3: {
                BinaryList onesComplement = binaryNum1.computeOnesComplement();
                cout << "Ones Complement of Binary Number 1: ";
                onesComplement.display();
                break;
            }
            case 4: {
                BinaryList twosComplement = binaryNum1.computeTwosComplement();
                cout << "Twos Complement of Binary Number 1: ";
                twosComplement.display();
                break;
            }
            case 5: {
                BinaryList sum = BinaryList::addBinary(binaryNum1, binaryNum2);
                cout << "Sum of Binary Number 1 and Binary Number 2: ";
                sum.display();
                break;
            }
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
