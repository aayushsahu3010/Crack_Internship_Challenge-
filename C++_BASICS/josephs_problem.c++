#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {}
};

class CircularLinkedList
{
    Node *tail; // points to last node

public:
    CircularLinkedList() : tail(NULL) {} // replaced nullptr with NULL

    // Add node to the circular linked list
    void addNode(int val)
    {
        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            tail = newNode;
            tail->next = tail; // points to itself, circular
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Display the circular linked list
    void display()
    {
        if (tail == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = tail->next; // start from head
        cout << "Circular List: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }

    // Solve Josephus problem and return the winner
    int josephus(int k)
    {
        if (tail == NULL)
            return -1; // empty list

        Node *curr = tail->next; // head
        Node *prev = tail;

        while (curr != prev)
        { // more than 1 node in the list
            // Move k-1 times
            for (int count = 1; count < k; count++)
            {
                prev = curr;
                curr = curr->next;
            }
            // Remove k-th node (curr)
            cout << "Person eliminated: " << curr->data << endl;
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }

        int winner = curr->data;
        delete curr;
        tail = NULL; // list is now empty
        return winner;
    }
};

int main()
{
    int n, k;
    cout << "Enter number of people (n): ";
    cin >> n;
    cout << "Enter step count (k): ";
    cin >> k;

    CircularLinkedList cll;

    for (int i = 1; i <= n; i++)
    {
        cll.addNode(i);
    }

    cll.display(); // Display initial list

    int winner = cll.josephus(k);
    cout << "The winner is person: " << winner << endl;

    return 0;
}
