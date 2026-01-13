#include <stdio.h>
#define LEN 10   // Universal set size 0-9

// Create set from user input
void createSet(int set[], char name) {
    int n;
    for (int i = 0; i < LEN; i++)
        set[i] = 0;  // initialize all 0

    printf("Enter number of elements in Set %c: ", name);
    scanf("%d", &n);

    printf("Enter elements of Set %c :\n", name);
    for (int i = 0; i < n; i++) {
        int elem;
        scanf("%d", &elem);
        if (elem >= 0 && elem < LEN)
            set[elem] = 1;
        else
            printf("Invalid element! Skipped.\n");
    }
}

// Display set as elements
void display(int set[]) {
    printf("{ ");
    for (int i = 0; i < LEN; i++) {
        if (set[i] == 1)
            printf("%d ", i);
    }
    printf("}\n");
}

// Union
void unionSet(int A[], int B[], int U[]) {
    for (int i = 0; i < LEN; i++)
        U[i] = (A[i] | B[i]);
}

// Intersection
void interSet(int A[], int B[], int I[]) {
    for (int i = 0; i < LEN; i++)
        I[i] = (A[i] & B[i]);
}

// Difference A - B
void diffSet(int A[], int B[], int D[]) {
    for (int i = 0; i < LEN; i++)
        D[i] = (A[i] & (!B[i]));
}

int main() {
    int A[LEN], B[LEN], U[LEN], I[LEN], D[LEN];
    int choice;

    // Create sets directly
    createSet(A, 'A');
    createSet(B, 'B');

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Display Sets\n");
        printf("2. Union (A ∪ B)\n");
        printf("3. Intersection (A ∩ B)\n");
        printf("4. Difference (A - B)\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Set A = "); display(A);
                printf("Set B = "); display(B);
                break;

            case 2:
                unionSet(A, B, U);
                printf("A ∪ B = "); display(U);
                break;

            case 3:
                interSet(A, B, I);
                printf("A ∩ B = "); display(I);
                break;

            case 4:
                diffSet(A, B, D);
                printf("A - B = "); display(D);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}