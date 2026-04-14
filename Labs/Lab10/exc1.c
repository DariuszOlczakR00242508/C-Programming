#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to add a new node to the binary search tree
struct node *addnode(struct node *root, int data) {
    struct node *p = NULL;

    // If the tree is empty, create a new node and return it
    if (root == NULL) {
        p = malloc(sizeof(struct node));
        p->data = data;
        p->left = NULL;
        p->right = NULL;
        return p;
    }
    // If the data is less than the root's data, go left
    else if (data < root->data)
        root->left = addnode(root->left, data);
    // If the data is greater than or equal to the root's data, go right
    else
        root->right = addnode(root->right, data);
    return root;
} 

// Function to perform in-order traversal of the binary tree
void inorder(struct node *root) {
    // Base case: if the root is NULL, return
    if (root == NULL) return;
    // Recursive call: traverse left subtree
    inorder(root->left);
    // Print the data of the current node
    printf("%d\t", root->data);
    // Recursive call: traverse right subtree
    inorder(root->right);   
}

int main() {
    struct node *tree = NULL;
    int node_list[] = {3, 1, 0, 2, 8, 6, 5, 9};
    // Insert nodes into the binary search tree
    for (int i=0; i < sizeof(node_list)/sizeof(int); i++){
        tree = addnode(tree, node_list[i]);
    }
    // Perform inorder traversal and print the nodes
    inorder(tree);
    return 0;
}