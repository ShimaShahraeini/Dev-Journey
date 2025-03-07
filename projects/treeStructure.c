/* C programming
dev journey: practicing structure and pointer within structure.
this code make an simple binery tree and ask users if they want to add any element to the tree 
and if thats a yes, it add the element to the tree based on this functionality:
if the number is smaller than the parent it goes left to find it's place 
and if it's greater it looks for the elements place in the right part of the tree*/

#include <stdio.h>
#include <stdlib.h>

struct tree {
    int value;
    struct tree *right;
    struct tree *left;
};

void insert(struct tree **root, struct tree *temp);
void inorderTraversal(struct tree *p);
void freeTree(struct tree *p); // Function prototype for freeing memory

int main() {
    struct tree *head = NULL, *temp = NULL;
    char ch;
    int data;

    do {
        printf("Add your number:\n");
        scanf("%d", &data);

        temp = (struct tree *)malloc(sizeof(struct tree));
        if (temp == NULL) {
            printf("Memory allocation failed!\n");
            return 1; // Exit if memory allocation fails
        }
        temp->value = data;
        temp->left = NULL; // Initialize left and right pointers
        temp->right = NULL;

        insert(&head, temp);

        printf("Do you want to add another number to the tree? (y/n)\n");
        while ((ch = getchar()) != '\n' && ch != EOF); // Clear input buffer
        ch = getchar(); // Read the character
    } while (ch == 'y' || ch == 'Y');

    printf("Inorder Traversal: ");
    inorderTraversal(head);
    printf("\n");

    freeTree(head); // Free the allocated memory for the tree

    return 0;
}

void insert(struct tree **root, struct tree *temp) {
    if (*root == NULL) {
        *root = temp; // Insert the new node
    } else if (temp->value < (*root)->value) {
        insert(&((*root)->left), temp);
    } else {
        insert(&((*root)->right), temp);
    }
}

void inorderTraversal(struct tree *p) {
    if (p != NULL) {
        inorderTraversal(p->left);
        printf("%d ", p->value);
        inorderTraversal(p->right);
    }
}

// Function to free the allocated memory for the tree
void freeTree(struct tree *p) {
    if (p != NULL) {
        freeTree(p->left);   // Free left subtree
        freeTree(p->right);  // Free right subtree
        free(p);             // Free the current node
    }
}
