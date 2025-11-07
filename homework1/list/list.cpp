#include <iostream>
using namespace std;

class DoublyLinkedListNode {
public:
    int index;
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;

    DoublyLinkedListNode(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }

    static DoublyLinkedListNode* insert_node(DoublyLinkedListNode* head, int value, int position = -1) {
        DoublyLinkedListNode* node = new DoublyLinkedListNode(value);

        if (!head) return node;

        
        if (position == 0) {
            node->next = head;
            head->prev = node;
            return node;
        }
        else if (position == -1) {
            DoublyLinkedListNode* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = node;
            node->prev = temp;
            return head;
        }
        else {
            DoublyLinkedListNode* temp = head;
            for (int i = 0; i < position - 1 && temp->next != nullptr; ++i)
                temp = temp->next;

            node->next = temp->next;
            node->prev = temp;
            if (temp->next) temp->next->prev = node;
            temp->next = node;
            return head;
        }
    }

    static DoublyLinkedListNode* delete_node(DoublyLinkedListNode* head, int position) {
        if (!head) return nullptr;

        if (position == 0) {
            DoublyLinkedListNode* newHead = head->next;
            if (newHead) newHead->prev = nullptr;
            delete head;
            return newHead;
        }

        DoublyLinkedListNode* temp = head;
        for (int i = 0; i < position && temp != nullptr; ++i)
            temp = temp->next;

        if (!temp) return head; 

        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;

        delete temp;
        return head;
    }

    static void printList(DoublyLinkedListNode* head) {
        DoublyLinkedListNode* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedListNode* head = nullptr;

    head = DoublyLinkedListNode::insert_node(head, 10);  
    head = DoublyLinkedListNode::insert_node(head, 20);  
    head = DoublyLinkedListNode::insert_node(head, 30);  
    head = DoublyLinkedListNode::insert_node(head, 5, 0);   
    head = DoublyLinkedListNode::insert_node(head, 25, 3);  

    cout << "Սկզբնական ցուցակը:" << endl;
    DoublyLinkedListNode::printList(head);

    head = DoublyLinkedListNode::delete_node(head, 1);
    cout << "Ջնջելուց հետո (index=1):" << endl;
    DoublyLinkedListNode::printList(head);

    
    head = DoublyLinkedListNode::delete_node(head, 0);
    cout << "Ջնջելուց հետո (head):" << endl;
    DoublyLinkedListNode::printList(head);

    return 0;
}
