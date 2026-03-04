#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void findCycleDetails(Node* head) {
    if (!head || !head->next) {
        std::cout << "fara cicli" << std::endl;
        return;
    }

    Node *slow = head, *fast = head;
    bool hasCycle = false;

    while (fast && fast->next) {
        slow = slow->next;          // sare 1
        fast = fast->next->next;    // sare 2
        
        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }

    if (!hasCycle) {
        std::cout << "fara cicli" << std::endl;
        return;
    }

    int length = 0;
    Node* temp = slow;
    do {
        temp = temp->next;
        length++;
    } while (temp != slow);
    
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    std::cout << "primul nod in ciclu " << slow->data << std::endl;
    std::cout << "lungime ciclu " << length << std::endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    Node* start = new Node(3);
    head->next->next = start;
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = start; 

    findCycleDetails(head);

    return 0;
}