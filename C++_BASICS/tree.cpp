#include <bits/stdc++.h>
using namespace std;

static int index = -1;
class node
{
public:
    int val;
    node *right;
    node *left;

    node(int value)
    {
        this->val = value;
        right = left = NULL;
    }
};

node *create_binary_Tree(vector<int> preorder)
{

    index = index + 1;
    if (preorder[index] == -1)
    {
        return NULL;
    }
    node *root = new node(preorder[index]);
    root->left = create_binary_Tree(preorder);  // left
    root->right = create_binary_Tree(preorder); // right

    return root;
}


int count_nodes(node*root){
    if(root == NULL){
        return 0;
    }
    return count_nodes(root->left)+count_nodes(root->right)+1;
}

void preoder_traversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preoder_traversal(root->left);
    preoder_traversal(root->right);
}

void inoder_traversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inoder_traversal(root->left);
    cout << root->val << " ";
    inoder_traversal(root->right);
}

void postoder_traversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postoder_traversal(root->left);
    postoder_traversal(root->right);
    cout << root->val << " ";
}

void levelorder_traversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    // q.push(NULL);
    while (q.size() > 0)
    {
        node *curr = q.front();
        if (q.size() != 0)
        {
            q.pop();
            cout << curr->val << " ";
            if (curr->left != NULL)
            {
                q.push(curr->left);
                /* code */
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
    cout << endl;
}

void levelorder_traversal2(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 0)
    {
        node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else 
            {
                break;
            }
        }

        cout << curr->val << " ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
            /* code */
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
    cout << endl;
}

int height(node*root){
    if(root ==NULL){
        return 0;
    }
    int leftht = height(root->left);
    int rightht = height(root->right);
    return max(leftht,rightht)+1;

     
}

int main()
{
    vector<int> v = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    node *root = create_binary_Tree(v);
    preoder_traversal(root);
    cout << endl;
    postoder_traversal(root);
    cout << endl;
    inoder_traversal(root);
    cout << endl;
    levelorder_traversal(root);
    levelorder_traversal2(root);
    cout<<height(root)<<endl;
    return 0;
}
