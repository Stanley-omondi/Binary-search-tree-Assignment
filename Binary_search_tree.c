#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

struct TreeNode* createBSTFromArray(int arr[], int n) {
    struct TreeNode* root = NULL;
    for (int i = 0; i < n; ++i) {
        root = insert(root, arr[i]);
    }
    return root;
}

int findHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void printLevelAndHeight(struct TreeNode* root, int key, int level) {
    if (root == NULL) {
        printf("Node with key %d not found in the BST.\n", key);
        return;
    }
    if (root->key == key) {
        printf("Node with key %d is at level %d and height %d.\n", key, level, findHeight(root));
        return;
    }
    if (key < root->key) {
        printLevelAndHeight(root->left, key, level + 1);
    } else {
        printLevelAndHeight(root->right, key, level + 1);
    }
}

int main() {
    int arr[] = {30, 20, 40, 10, 25, 35, 45, 5, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct TreeNode* root = createBSTFromArray(arr, n);

    int keyToSearch = 25;
    printLevelAndHeight(root, keyToSearch, 1);

    return 0;
}
