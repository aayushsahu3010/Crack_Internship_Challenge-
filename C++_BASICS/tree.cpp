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

int count_nodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return count_nodes(root->left) + count_nodes(root->right) + 1;
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

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftht = height(root->left);
    int rightht = height(root->right);
    return max(leftht, rightht) + 1;
}

int node_sum(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = root->val;
    int leftsum = node_sum(root->left);
    int rightsum = node_sum(root->right);
    return (ans + leftsum + rightsum);
}

bool identical_trees(node *root1, node *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        return root1 == root2;
    }

    bool isleft = identical_trees(root1->left, root2->left);
    bool isright = identical_trees(root1->right, root2->right);

    return (isleft && isright && (root1->val == root2->val));
}

int main()
{
    vector<int> v = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    vector<int> v1 = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    index = -1;
    node *root = create_binary_Tree(v);
    index = -1;
    node *root2 = create_binary_Tree(v1);

    preoder_traversal(root);
    cout << endl;
    postoder_traversal(root);
    cout << endl;
    inoder_traversal(root);
    cout << endl;
    levelorder_traversal(root);
    levelorder_traversal2(root);
    cout << height(root) << endl;
    cout << count_nodes(root) << endl;

    cout << node_sum(root) << endl;

    cout << identical_trees(root, root2);
    return 0;
}
