#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

node *insert_bst(node *root, int key)
{
    if (root == NULL)
    {
        return new node(key);
    }

    if (key < root->data)
    {
        root->left = insert_bst(root->left, key);
    }

    if (key > root->data)
    {
        root->right = insert_bst(root->right, key);
    }

    return root;
}

void inorder(node *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search_bst(node *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == key)
    {
        return true;
    }

    if (key < root->data)
    {
        return search_bst(root->left, key);
    }

    if (key > root->data)
    {
        return search_bst(root->right, key);
    }
}

node *minimum_node(node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
        /* code */
    }

    return root;
}

node *deletion_node(node *root, int key)
{
    if (!root)
    {
        return root;
    }
    else if (key < root->data)
    {
        root->left = deletion_node(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deletion_node(root->right, key);
    }
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
        node *successor = minimum_node(root->right);
        root->data = successor->data;
        root->right = deletion_node(root->right, successor->data);
    }
    return root;
}

class graph
{
public:
    int v;
    list<int> *l;

    graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void add_edge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print_graph()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << "--> ";
            for (int val : l[i])
            {
                cout << val<<" ";
            }
            cout << endl;
        
        }
    }
};

int main()
{
    node *root = NULL;
    vector<int> v = {50, 60, 10, 12, 45, 13, 15, 78};
    for (int x : v)
    {
        root = insert_bst(root, x);
    }

    cout << search_bst(root, 10) << endl;
    inorder(root);
    cout << endl;
    root = deletion_node(root, 50);
    inorder(root);

    cout << "Graph data" << endl;

    graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0,2);
    g.add_edge(1,3);
    g.add_edge(4,1);
    g.add_edge(3,4);

    g.print_graph();

    return 0;
}
