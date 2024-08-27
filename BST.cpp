#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int _data)
    {
        data = _data;
        left = right = NULL;
    }
};

class BST
{
public:
    Node* root;

    BST()
    {
        root = NULL;
    }

    void Add(int data)
    {
        Node* newNode = new Node(data);
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            Node* current = root;
            Node* parent = NULL;

            while (current != NULL)
            {
                parent = current;
                if (data > current->data)
                {
                    current = current->right;
                }
                else
                {
                    current = current->left;
                }
            }

            if (data > parent->data)
            {
                parent->right = newNode;
            }
            else
            {
                parent->left = newNode;
            }
        }
    }

    void Display(Node* pDisplay)
    {
        if (pDisplay == NULL)
            return;
        Display(pDisplay->right); // +RDL
        cout << pDisplay->data << "\t";
        Display(pDisplay->left);
    }

    void Traverse()
    {
        Display(root);
    }

    void Traverse(int data)
    {
        Node* pSearch = Search(data);
        Display(pSearch);
    }

    Node* Search(int data)
    {
        Node* current = root;

        while (current != NULL)
        {
            if (data == current->data)
            {
                return current;
            }
            if (data > current->data)
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }
        return NULL;
    }

    Node* GetMaxRight(Node* maxRight)
    {
        while (maxRight->right != NULL)
        {
            maxRight = maxRight->right;
        }
        return maxRight;
    }

    int FindMaxNode()
    {
        Node* maxRight = root;
        if (maxRight == NULL)
        {
            return -1; // Return -1 if tree is empty
        }

        while (maxRight->right != NULL)
        {
            maxRight = maxRight->right;
        }
        return maxRight->data;
    }

    void DeleteNode(int value)
    {
        Node* parent = NULL;
        Node* current = root;
        while (current != NULL && current->data != value)
        {
            parent = current;
            if (value < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        if (current == NULL)
        {
            cout << "Node not found." << endl;
            return;
        }

        // Node has no children
        if (current->left == NULL && current->right == NULL)
        {
            if (parent != NULL)
            {
                if (parent->left == current)
                {
                    parent->left = NULL;
                }
                else
                {
                    parent->right = NULL;
                }
            }
            else
            {
                root = NULL;
            }
            delete current;
        }
        // Node has only a right child
        else if (current->left == NULL && current->right != NULL)
        {
            if (parent != NULL)
            {
                if (parent->left == current)
                {
                    parent->left = current->right;
                }
                else
                {
                    parent->right = current->right;
                }
            }
            else
            {
                root = current->right;
            }
            delete current;
        }
        // Node has only a left child
        else if (current->left != NULL && current->right == NULL)
        {
            if (parent != NULL)
            {
                if (parent->left == current)
                {
                    parent->left = current->left;
                }
                else
                {
                    parent->right = current->left;
                }
            }
            else
            {
                root = current->left;
            }
            delete current;
        }
        // Node has both children
        else
        {
            Node* maxLeft = GetMaxRight(current->left);
            int maxLeftData = maxLeft->data;
            DeleteNode(maxLeftData); // Delete the node with maximum value in the left subtree
            current->data = maxLeftData;
        }
    }

    virtual ~BST() {}
};

int main()
{
    BST s;
    s.Add(10);
    s.Add(20);
    s.Add(30);
    s.Add(40);
    s.Add(400);
    s.Add(60);
    s.Add(30);
    s.Add(70);
    s.Add(80);
    s.DeleteNode(60);
    s.Traverse();
    cout << endl;
    int res = s.FindMaxNode();
    cout << res << endl;

    return 0;
}
