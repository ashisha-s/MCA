#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int info;
    struct node *left;
    struct node *right;
};

// Global variables
struct node *tree = NULL;
int found = 0;

// Function to create a new node
struct node *createTree(int item) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = item;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct node *insertTree(struct node *tree, int item) {
    if (tree == NULL) {
        return createTree(item);
    } else {
        if (item < tree->info)
            tree->left = insertTree(tree->left, item);
        else if (item > tree->info)
            tree->right = insertTree(tree->right, item);
        else
            printf("Duplicate node not inserted.\n");
    }
    return tree;
}

// Preorder traversal
void preorder(struct node *tree) {
    if (tree != NULL) {
        printf("%d ", tree->info);
        preorder(tree->left);
        preorder(tree->right);
    }
}

// Inorder traversal
void inorder(struct node *tree) {
    if (tree != NULL) {
        inorder(tree->left);
        printf("%d ", tree->info);
        inorder(tree->right);
    }
}

// Postorder traversal
void postorder(struct node *tree) {
    if (tree != NULL) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ", tree->info);
    }
}

// Find the minimum value node
struct node *findMin(struct node *tree) {
    while (tree != NULL && tree->left != NULL)
        tree = tree->left;
    return tree;
}

// Delete a node from the BST
struct node *deleteNode(struct node *tree, int item) {
    if (tree == NULL)
        return tree;

    if (item < tree->info)
        tree->left = deleteNode(tree->left, item);
    else if (item > tree->info)
        tree->right = deleteNode(tree->right, item);
    else {
        // Node found
        found = 1;

        // Node with two children
        if (tree->left != NULL && tree->right != NULL) {
            struct node *temp = findMin(tree->right);
            tree->info = temp->info;
            tree->right = deleteNode(tree->right, temp->info);
        } else {
            struct node *temp = tree;
            if (tree->left != NULL)
                tree = tree->left;
            else
                tree = tree->right;
            free(temp);
        }
    }

    return tree;
}



// Find a node with a given value
struct node *find(struct node *tree, int item) {
    if (tree == NULL)
        return NULL;
    if (item < tree->info)
        return find(tree->left, item);
    else if (item > tree->info)
        return find(tree->right, item);
    else
        return tree;
}

int main() {
    int ch, item;
    struct node *result;

    do {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert Node\t");
        printf("2. Preorder Traversal\t");
        printf("3. Postorder Traversal\t");
        printf("4. Inorder Traversal\t");
        printf("5. Delete Node\t");
        printf("6. Find Node\t");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &item);
                tree = insertTree(tree, item);
                break;

            case 2:
                if (tree == NULL)
                    printf("Tree is empty.\n");
                else {
                    printf("Preorder Traversal:\n");
                    preorder(tree);
                }
                break;

            case 3:
                if (tree == NULL)
                    printf("Tree is empty.\n");
                else {
                    printf("Postorder Traversal:\n");
                    postorder(tree);
                }
                break;

            case 4:
                if (tree == NULL)
                    printf("Tree is empty.\n");
                else {
                    printf("Inorder Traversal:\n");
                    inorder(tree);
                }
                break;

            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &item);
                found = 0;
                tree = deleteNode(tree, item);
                if (!found)
                    printf("Item not found.\n");
                else
                    printf("Item deleted.\n");
                break;

            case 6:
                printf("Enter value to find: ");
                scanf("%d", &item);
                result = find(tree, item);
                if (result == NULL)
                    printf("Item not found.\n");
                else
                    printf("Item %d found in tree.\n", result->info);
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(ch != 7);

    return 0;
}