#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *left, *right;
};

struct node *tree = NULL;

// Function to create a new node
struct node *create(int item) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = item;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insertion Function
void insertTree() {
    int item;
    printf("Enter data: ");
    scanf("%d", &item);

    struct node *newNode = create(item);

    if (tree == NULL) {
        tree = newNode;
        return;
    }

    struct node *current = tree;
    char dir;

    while (1) {
        printf("At node %d, go left or right (l/r): ", current->info);
        while ((getchar()) != '\n'); // Clear input buffer
        scanf("%c", &dir);

        if (dir == 'l') {
            if (current->left == NULL) {
                current->left = newNode;
                break;
            } else {
                current = current->left;
            }
        } else if (dir == 'r') {
            if (current->right == NULL) {
                current->right = newNode;
                break;
            } else {
                current = current->right;
            }
        } else {
            printf("Invalid direction. Enter 'l' or 'r'.\n");
        }
    }
}

// Traversal Functions
void preorder(struct node *tree) {
    if (tree != NULL) {
        printf("%d ", tree->info);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder(struct node *tree) {
    if (tree != NULL) {
        inorder(tree->left);
        printf("%d ", tree->info);
        inorder(tree->right);
    }
}

void postorder(struct node *tree) {
    if (tree != NULL) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ", tree->info);
    }
}

// Count number of nodes
int countNodes(struct node *tree) {
    if (tree == NULL)
        return 0;
    else
        return 1 + countNodes(tree->left) + countNodes(tree->right);
}

struct node *deleteNode(struct node *root, int val) {
    if (root == NULL)
        return NULL;

    if (root->info == val) {
        // No child
        if ((root->left == NULL) && (root->right == NULL)) {
            free(root);
            return NULL;
        }
        // Only left child
        if ((root->left != NULL) && (root->right == NULL)) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // Only right child
        if ((root->left == NULL) && (root->right != NULL)) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        // Two children
        if ((root->left != NULL) && (root->right != NULL)) {
            struct node *temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            root->info = temp->info;
            root->right = deleteNode(root->right, temp->info);
            return root;
        }
    }

    root->left = deleteNode(root->left, val);
    root->right = deleteNode(root->right, val);

    return root;
}

int main() {
    int ch, val;

    do {
        printf("\n1. Insertion\n2. Deletion\n3. Preorder Traversal\n");
        printf("4. Inorder Traversal\n5. Postorder Traversal\n6. Exit\n");
        printf("7. Count Nodes\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insertTree();
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                tree = deleteNode(tree, val);
                break;
            case 3:
                printf("\nPreorder Traversal: ");
                preorder(tree);
                printf("\n");
                break;
            case 4:
                printf("\nInorder Traversal: ");
                inorder(tree);
                printf("\n");
                break;
            case 5:
                printf("\nPostorder Traversal: ");
                postorder(tree);
                printf("\n");
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            case 7:
                printf("Total number of nodes: %d\n", countNodes(tree));
                break;
             default:
                printf("Invalid choice.\n");
                break;
        }
    } while (ch != 6);

return 0;
}
