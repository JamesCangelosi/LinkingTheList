#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string bookName) {
        data = bookName;
        next = nullptr; // nullptr indicates there isn't a next node in the list
    }
};

class LinkedList {
public:
    LinkedList() {
        head = nullptr;
    }

    void insert(string bookName) {
        Node* newNode = new Node(bookName);
        newNode->next = head;
        head = newNode;
    }

    void remove(string bookName) {
        if (head == nullptr) 
            return;

        if (head->data == bookName) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* currentNode = head;

        while (currentNode->next != nullptr && currentNode->next->data != bookName) {
            currentNode = currentNode->next;
        }

        if (currentNode->next != nullptr) {
            Node* temp = currentNode->next;
            currentNode->next = currentNode->next->next;
            delete temp;
        }
    }

    void print() {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }

private:
    Node* head;
};

int main()
{
    
}