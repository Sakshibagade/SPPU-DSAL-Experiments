/* Practical No-4
Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given. After constructing a binary tree - Insert new node
●	Find number of nodes in longest path from root  
●	Minimum data value found in the tree
●	Change a tree so that the roles of the left and
right pointers are swapped at every node
●	Search a value */

#include <iostream>
using namespace std;

// Define the structure of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary search tree
Node* insertNode(Node* root, int data) {
    // If the tree is empty, create a new node
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    // If the data is smaller than the root's data, recur left
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    // If the data is greater than the root's data, recur right
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    // If the data is already present, return the root
    return root;
}

// Function to insert a new node in the binary search tree
Node* insertNewNode(Node* root, int data) {
    // Insert the new node
    root = insertNode(root, data);
    cout << "New node with data " << data << " inserted successfully!" << endl;
    return root;
}

// Function to find the number of nodes in the longest path from the root
int findLongestPath(Node* root) {
    // If the tree is empty, return 0
    if (root == NULL) {
        return 0;
    }
    // Find the height of the left and right subtrees
    int leftHeight = findLongestPath(root->left);
    int rightHeight = findLongestPath(root->right);
    // Return the maximum of the left and right subtree heights plus 1
    return max(leftHeight, rightHeight) + 1;
}

// Function to find the minimum data value in the binary search tree
int findMinValue(Node* root) {
    // If the tree is empty, return -1
    if (root == NULL) {
        return -1;
    }
    // Traverse to the leftmost node to find the minimum value
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// Function to swap the left and right pointers at every node
void swapLeftRight(Node* root) {
    // If the tree is empty or has only one node, return
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return;
    }
    // Swap the left and right pointers at the current node
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    // Recur on the left and right subtrees
    swapLeftRight(root->left);
    swapLeftRight(root->right);
}

// Function to search for a value in the binary search tree
bool searchValue(Node* root, int data) {
    // If the tree is empty or the data is found at the root, return true
    if (root == NULL || root->data == data) {
        return root != NULL;
    }
    // If the data is smaller than the root's data, recur left
    if (data < root->data) {
        return
            searchValue(root->left, data);
}
// If the data is greater than the root's data, recur right
else {
    return searchValue(root->right, data);
}

}

// Function to traverse the binary search tree in inorder
void inorderTraversal(Node* root) {
if (root != NULL) {
inorderTraversal(root->left);
cout << root->data << " ";
inorderTraversal(root->right);
}
}

int main() {
// Create an empty binary search tree
Node* root = NULL;
// Insert values in the order given
int values[] = {5, 2, 7, 1, 3, 6, 8};
int n = sizeof(values) / sizeof(values[0]);
for (int i = 0; i < n; i++) {
    root = insertNode(root, values[i]);
}

// Traverse the binary search tree in inorder
cout << "Inorder traversal of the binary search tree: ";
inorderTraversal(root);
cout << endl;

// Insert a new node
root = insertNewNode(root, 4);

// Find the number of nodes in the longest path from the root
int longestPath = findLongestPath(root);
cout << "The number of nodes in the longest path from the root is: " << longestPath << endl;

// Find the minimum data value in the binary search tree
int minValue = findMinValue(root);
cout << "The minimum data value in the binary search tree is: " << minValue << endl;

// Swap the left and right pointers at every node
swapLeftRight(root);

// Traverse the binary search tree in inorder
cout << "Inorder traversal of the binary search tree after swapping left and right pointers: ";
inorderTraversal(root);
cout << endl;



return 0;
}
