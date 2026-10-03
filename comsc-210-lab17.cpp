//COMSC-210 | Lab 17 | Ahmad Dharhan
#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void prependNode(Node *&);
void appendNode(Node *&);
void deleteNode(Node *&);
void insertNode(Node *&);
void deleteList(Node *&);


int main() {
    Node *head = nullptr;
    int count = 0;
    int input = 0;

    // create a linked (list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
    }

    while(input != -1){
        cout << "What would you like to do?" << endl;
        cout << "1. Prepend a Node" << endl;
        cout << "2. Append a Node " << endl;
        cout << "3. Delete a Node" << endl;
        cout << "4. Insert a Node" << endl;
        cout << "5. Delete LinkedList" << endl;
        cout << "Enter -1 to exit!" << endl;

        cin >> input;

        if (input == 1){
            prependNode(head);
        }
        if (input == 2){
            appendNode(head);
        }
        if (input == 3){
            deleteNode(head);
        }
        if (input == 4){
            insertNode(head);
        }
        if (input == 5){
            deleteList(head);
            
        }
        if (input == -1){
            break;
        }
    }

}

void prependNode(Node *&head){
        int tmp_val;

        cout << "Enter Value" << endl;
        cin >> tmp_val;

        Node * newVal = new Node;
        // adds node at head
        if (!head) {
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else {
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    output(head);
}

void deleteNode(Node *&head){
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    Node *current = head;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion

    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    // at this point, delete current and reroute pointers
    if (current) {
        if (prev == nullptr) {
            // deleting the head node
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        current = nullptr;
    }
    output(head);
}

void insertNode(Node *&head, int count){

    int entry;
    // insert a node
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    Node *current = head;
    Node *prev;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = nullptr;  // reset prev to nullptr for same reason

    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }


    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;

    if (prev == nullptr) {
        // inserting before the head
        head = newnode;
    } else {
        prev->next = newnode;
    }
    output(head);
}

void deleteList(Node*&head){
    // deleting the linked list
    Node * current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);
}

void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}