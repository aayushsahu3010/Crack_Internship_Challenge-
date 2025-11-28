#include <iostream>
using namespace std;

#define INF 9999999

// -------------------- BST --------------------
class node
{
public:
    int data;
    node *right;
    node *left;

    node(int data)
    {
        this->data = data;
        right = left = NULL;
    }
};

node *insert_node(node *root, int key)
{
    if (!root)
        return new node(key);

    if (key < root->data)
        root->left = insert_node(root->left, key);
    else if (key > root->data)
        root->right = insert_node(root->right, key);

    return root;
}

void inorder(node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool searchBST(node *root, int key)
{
    if (!root)
        return false;
    if (root->data == key)
        return true;
    if (key < root->data)
        return searchBST(root->left, key);
    return searchBST(root->right, key);
}

node *findmin(node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

node *delete_node(node *root, int key)
{
    if (!root)
        return NULL;

    if (key < root->data)
        root->left = delete_node(root->left, key);

    else if (key > root->data)
        root->right = delete_node(root->right, key);

    else
    {
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        else if (root->left && !root->right)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else if (!root->left && root->right)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        node *successor = findmin(root->right);
        root->data = successor->data;
        root->right = delete_node(root->right, successor->data);
    }
    return root;
}

// -------------------- Dijkstra --------------------
int minDistance(int dis[], int n, bool visited[])
{
    int minindex = -1;
    int minval = INF;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dis[i] < minval)
        {
            minval = dis[i];
            minindex = i;
        }
    }
    return minindex;
}

void dijikastras(int n, int adj[][6], int src)
{
    bool visited[10];
    int dis[10];
    int parent[10];

    for (int i = 0; i < n; i++)
    {
        dis[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    dis[src] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int u = minDistance(dis, n, visited);
        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && adj[u][v] != 0 &&
                dis[u] + adj[u][v] < dis[v])
            {

                parent[v] = u;
                dis[v] = dis[u] + adj[u][v];
            }
        }
    }

    cout << "vertex  distance  parent\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << "   " << dis[i] << "   " << parent[i] << endl;
    }
}

// -------------------- Prims --------------------
void prims(int adj[][6], int n)
{
    int key[10];
    bool mst[10];
    int parent[10];

    for (int i = 0; i < n; i++)
    {
        key[i] = INF;
        mst[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int c = 0; c < n - 1; c++)
    {
        int u = -1, mini = INF;

        for (int i = 0; i < n; i++)
        {
            if (!mst[i] && key[i] < mini)
            {
                mini = key[i];
                u = i;
            }
        }

        mst[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (adj[u][v] != 0 && !mst[v] && adj[u][v] < key[v])
            {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "node  key  parent\n";
    for (int i = 1; i < n; i++)
        cout << i << "   " << key[i] << "   " << parent[i] << endl;
}

// -------------------- DFS --------------------
void dfs(int adj[][5], int n, int src, bool visited[])
{
    cout << src << " ";
    visited[src] = true;

    for (int i = 0; i < n; i++)
    {
        if (adj[src][i] != 0 && !visited[i])
            dfs(adj, n, i, visited);
    }
}

void bfs(int adj[][5], int src, int n)
{
    bool visited[n] = {0, 0, 0, 0, 0, 0};
    int queue[10];
    int front = 0, rear = 0;

    queue[rear++] = src;
    visited[src] = true;

    while (front < rear)
    {
        int u = queue[front++];
        cout << u << " ";

        for (int v = 0; v < n; v++)
        {
            if (adj[u][v] != 0 && !visited[v])
            {
                visited[v] = true;
                queue[rear++] = v;
            }
        }

        /* code */
    }
}

class hashing
{
public:
    int tablesize;
    int *arr;

    hashing(int size)
    {
        tablesize = size;
        arr = new int[tablesize];
        for (int i = 0; i < tablesize; i++)
        {
            arr[i] = -1;
        }
    }

    int hashfunc(int key)
    {
        return key % tablesize;
    }

    void insert_key(int key)
    {
        int i = hashfunc(key);
        if (arr[i] == -1)
        {
            arr[i] = key;
            cout << "data is entered" << endl;
        }
        else
        {
            cout << "collision occur" << endl;
        }
    }

    bool search(int key)
    {
        int i = hashfunc(key);
        if (arr[i] == key)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void display()
    {
        cout << "display the hashtable data " << endl;
        for (int i = 0; i < tablesize; i++)
        {
            cout << i << " ---> " << arr[i] << endl;
        }
    }
};

class hashlinear
{
public:
    int tablesize;
    int *arr;

    hashlinear(int size)
    {
        tablesize = size;
        arr = new int[tablesize];
        for (int i = 0; i < tablesize; i++)
        {
            arr[i] = -1;
        }
    }

    int hashfunc(int key)
    {
        return key % tablesize;
    }

    void insert_key(int key)
    {
        int i = hashfunc(key);
        if (arr[i] == -1)
        {
            arr[i] = key;
            cout << "data is entered" << endl;
            return;
        }
        cout << "collision occur at" << i << endl;
        int start = i;
        i = (i + 1) % tablesize;
        while (i != start)
        {
            if (arr[i] == -1)
            {
                arr[i] = key;
                cout << "Inserted at index " << i << endl;
                return;
            }
            i = (i + 1) % tablesize;
        }
        cout << "Hash table full! Cannot insert.\n";
    }

    bool search(int key)
    {
        int i = hashfunc(key);
        int start = i;

        while (arr[i] != -1)
        {
            if (arr[i] == key)
                return true;

            i = (i + 1) % tablesize;

            if (i == start)
                return false;
        }

        return false;
    }

    void display()
    {
        cout << "display the hashtable data " << endl;
        for (int i = 0; i < tablesize; i++)
        {
            cout << i << " ---> " << arr[i] << endl;
        }
    }
};

class hashquadratic
{
public:
    int tablesize;
    int *arr;

    hashquadratic(int size)
    {
        tablesize = size;
        arr = new int[tablesize];
        for (int i = 0; i < tablesize; i++)
            arr[i] = -1;
    }

    int hashfunc(int key)
    {
        return key % tablesize;
    }

    void insert_key(int key)
    {
        int index = hashfunc(key);

        if (arr[index] == -1)
        {
            arr[index] = key;
            cout << "Inserted at index " << index << endl;
            return;
        }

        cout << "Collision at " << index << ", applying quadratic probing...\n";

        int i = 1;

        while (i < tablesize)
        {
            int newIndex = (index + i * i) % tablesize;

            if (arr[newIndex] == -1)
            {
                arr[newIndex] = key;
                cout << "Inserted at index " << newIndex << endl;
                return;
            }

            i++;
        }

        cout << "Hash table full! Cannot insert.\n";
    }

    bool search(int key)
    {
        int index = hashfunc(key);
        int i = 0;

        while (i < tablesize)
        {
            int newIndex = (index + i * i) % tablesize;

            if (arr[newIndex] == key)
                return true;

            if (arr[newIndex] == -1)
                return false;

            i++;
        }

        return false;
    }

    void display()
    {
        cout << "\nHash Table (Quadratic Probing):\n";
        for (int i = 0; i < tablesize; i++)
        {
            cout << i << " ---> " << arr[i] << endl;
        }
    }
};

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class HashChaining
{
public:
    int tablesize;
    Node **table;

    HashChaining(int size)
    {
        tablesize = size;
        table = new Node *[tablesize];
        for (int i = 0; i < tablesize; i++)
        {
            table[i] = nullptr;
        }
    }

    int hashfunc(int key)
    {
        return key % tablesize;
    }

    void insert_key(int key)
    {
        int idx = hashfunc(key);
        Node *newNode = new Node(key);

        // Insert at beginning of chain for simplicity
        newNode->next = table[idx];
        table[idx] = newNode;

        cout << "Inserted key " << key << " at index " << idx << "\n";
    }

    bool search(int key)
    {
        int idx = hashfunc(key);
        Node *cur = table[idx];
        while (cur != nullptr)
        {
            if (cur->data == key)
                return true;
            cur = cur->next;
        }
        return false;
    }

    void display()
    {
        cout << "\nHash Table (Chaining):\n";
        for (int i = 0; i < tablesize; i++)
        {
            cout << i << " -> ";
            Node *cur = table[i];
            while (cur != nullptr)
            {
                cout << cur->data << " -> ";
                cur = cur->next;
            }
            cout << "NULL\n";
        }
    }
};

class queue
{
public:
    int rear, front;
    int *arr;
    int size;

    queue(int n)
    {
        size = n;
        rear = front = -1;
        arr = new int[size];
    }

    bool isfull()
    {
        if (rear == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(int key)
    {
        if (isfull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        arr[rear] = key;
    }

    bool isempty()
    {
        if (front == -1 && rear == -1 || front > rear)
        {
            return true;
        }
        else
            return false;
    }

    void dequeue()
    {
        if (isempty())
        {
            cout << "queue is empty" << endl;
            return;
        }

        front++;
        if (front > rear)
        { // Reset queue when empty
            front = rear = -1;
        }
    }

    void display()
    {
        if (isempty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
// -------------------- MAIN --------------------

class circular_queue
{
public:
    int front, rear;
    int *arr;
    int size;

    circular_queue(int n)
    {
        size = n;
        front = rear = -1;
        arr = new int[size];
    }

    bool isfull()
    {
        return (front == 0 && rear == size - 1) || (rear + 1) % size == front;
    }

    bool isempty()
    {
        return front == -1;
    }

    void enque(int key)
    {
        if (isfull())
        {
            cout << "queue is full" << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = key;
    }

    void dequeue()
    {
        if (isempty())
        {
            cout << "queue is empty " << endl;
            return;
        }
        if (front == rear)
        {
            front = rear = -1; // queue becomes empty
        }
        else
        {
            front = (front + 1) % size;
        }
    }

    void display()
    {
        if (isempty())
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Circular Queue Elements: ";

        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size; // IMPORTANT
        }

        cout << endl;
    }
};

class Queue
{
public:
    Node *front;
    Node *rear;

    Queue()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);

        if (rear == NULL)
        { // first element
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Inserted: " << value << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is EMPTY\n";
            return;
        }

        Node *temp = front;
        cout << "Deleted: " << temp->data << endl;

        front = front->next;

        if (front == NULL) // queue becomes empty
            rear = NULL;

        delete temp;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is EMPTY\n";
            return;
        }

        Node *temp = front;

        cout << "Queue elements: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class cll
{
    int data;
    cll *next;

    cll(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int josephs(Node *&head, Node *&tail, int k)
{
    if (head == NULL)
    {
        return -1;
    }
    Node *curr = head;
    Node *prev = tail;
    while (curr != prev)
    {
        for (int i = 0; i < k; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        cout << "Elimimnated Data: " << curr->data << endl;

        // remove it
        prev->next = curr->next;
        if (curr == head)
        {
            head = curr->next;
        }

        if (curr == tail)
        {
            tail = prev;
        }
        delete curr;
        curr = prev->next;
    }
    int winner = curr->data;
    delete curr;
    head = tail = NULL;
    return winner;
}

Node *createCLL(int n, Node *&tail)
{
    Node *head = NULL;

    for (int i = 1; i <= n; i++)
    {
        Node *newNode = new Node(i);

        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

class PriorityQueue
{
public:
    int data;
    int priority;
    PriorityQueue *next;

    PriorityQueue(int val, int pr)
    {
        data = val;
        priority = pr;
        next = NULL;
    }
};

// INSERT (sorted by priority)
PriorityQueue *enqueue(PriorityQueue *head, int val, int pr)
{
    PriorityQueue *newNode = new PriorityQueue(val, pr);

    // Case 1: empty list or new node has highest priority
    if (head == NULL || pr > head->priority)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    // Case 2: find correct position in sorted order
    PriorityQueue *temp = head;
    while (temp->next != NULL && temp->next->priority >= pr)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// DELETE highest priority (always at head)
PriorityQueue *dequeue(PriorityQueue *head)
{
    if (head == NULL)
    {
        cout << "Priority Queue is EMPTY\n";
        return NULL;
    }

    PriorityQueue *temp = head;
    cout << "Deleted: " << temp->data << " (Priority: " << temp->priority << ")\n";

    head = head->next;
    delete temp;
    return head;
}

// DISPLAY
void display(PriorityQueue *head)
{
    if (head == NULL)
    {
        cout << "Priority Queue is EMPTY\n";
        return;
    }

    cout << "Queue (val:priority): ";
    PriorityQueue *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ":" << temp->priority << "  ";
        temp = temp->next;
    }
    cout << endl;
}

// Push and return new TOP
Node *push(Node *top, int val)
{
    Node *newNode = new Node(val);
    newNode->next = top;
    top = newNode;
    return top; // return updated top
}

// Pop and return new TOP
Node *pop(Node *top)
{
    if (top == NULL)
    {
        cout << "Stack is EMPTY\n";
        return NULL;
    }

    Node *temp = top;
    cout << "Popped: " << temp->data << endl;

    top = top->next; // move to next
    delete temp;
    return top; // return updated top
}

void display(Node *top)
{
    if (top == NULL)
    {
        cout << "Stack is EMPTY\n";
        return;
    }

    cout << "Stack elements: ";
    Node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // temporary arrays
    int *L = new int[n1];
    int *R = new int[n2];

    // copy data
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0;
    int k = left;

    // merge
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // remaining elements
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void manualSwap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            manualSwap(arr[i], arr[j]);
        }
    }

    i++;
    manualSwap(arr[i], arr[end]); // put pivot in correct place
    return i;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int p = partition(arr, start, end);

        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}

int main()
{

    int adj[6][6] = {
        {0, 4, 2, 1, 0, 0},
        {4, 0, 0, 7, 0, 0},
        {2, 0, 0, 3, 8, 0},
        {1, 7, 3, 0, 0, 1},
        {0, 0, 8, 0, 0, 2},
        {0, 0, 0, 1, 2, 0}};

    dijikastras(6, adj, 0);
    cout << "\nPrims:\n";
    prims(adj, 6);

    int adj2[5][5] = {0};
    bool visited[5] = {false};

    adj2[0][1] = adj2[1][0] = 1;
    adj2[0][2] = adj2[2][0] = 1;
    adj2[1][3] = adj2[3][1] = 1;
    adj2[1][4] = adj2[4][1] = 1;
    adj2[3][4] = adj2[4][3] = 1;

    cout << "\nDFS: ";
    dfs(adj2, 5, 0, visited);
    cout << endl;
    cout << "bfs " << endl;
    bfs(adj2, 0, 5);

    hashing h(11); // size = 10

    h.insert_key(15); // index = 5
    h.insert_key(27); // index = 7
    h.insert_key(42); // index = 2
    h.insert_key(22); // collision if index already filled

    h.display();

    int key = 27;
    if (h.search(key))
        cout << "\nKey " << key << " found\n";
    else
        cout << "\nKey " << key << " NOT found\n";

    int n, k;
    cout << "Enter number of people (n): ";
    cin >> n;
    cout << "Enter step count (k): ";
    cin >> k;

    Node *tail = NULL;
    Node *head2 = createCLL(n, tail);

    int ans = josephs(head2, tail, k);

    cout << "\nSurvivor: " << ans << endl;

    PriorityQueue *head = NULL;

    head = enqueue(head, 10, 2);
    head = enqueue(head, 50, 5);
    head = enqueue(head, 30, 3);
    head = enqueue(head, 70, 10);

    display(head);

    head = dequeue(head);
    display(head);

    return 0;
}
