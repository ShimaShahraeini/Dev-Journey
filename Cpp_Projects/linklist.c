/* C programming
dev journey: practicing structure and pointer within structure.
this code make an link list and ask users if they want to add any element to the link list 
and if thats a yes  it add the element to the link list!*/

#include <stdio.h>
#include <stdlib.h>

struct students {
    char name[10];
    int age;
    struct students *newStudent;
};

int main() {
    struct students *fs = NULL, *h = NULL, *temp = NULL;
    char ch = 'y';

    do {
        printf("Add your student record:\n");
        temp = (struct students *)malloc(sizeof(struct students));
        if (temp == NULL) {
            printf("Memory allocation failed!\n");
            return 1; // Exit if memory allocation fails
        }
        
        printf("Type student name: \n");
        scanf("%s", temp->name);
        printf("Type student age: \n");
        scanf("%d", &temp->age);
        
        temp->newStudent = fs; // Link the new student to the previous head
        fs = temp; // Update head to the new student
        
        printf("Do you want to add another record? (y/n)\n");
        ch = getchar(); // Read the character
        ch = getchar(); // Read the newline character
    } while (ch == 'y'|| ch == 'Y');

    printf("\n______records_____\n");

    h = fs; // Initialize h to the head of the list
    while (h != NULL) {
        printf("Name: %s,\t", h->name);
        printf("Age: %d\n", h->age);
        h = h->newStudent; // Move to the next student
    }

    // Free allocated memory
    h = fs;
    while (h != NULL) {
        struct students *next = h->newStudent;
        free(h);
        h = next;
    }

    return 0;
}