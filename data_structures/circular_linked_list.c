#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
} *head = NULL, *temp = NULL, *newnode = NULL;

// Create a new node
struct node* create_node() {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

// Count nodes in the circular linked list
int count() {
    int cnt = 0;
    if (head == NULL) return 0;

    temp = head;
    do {
        cnt++;
        temp = temp->next;
    } while (temp != head);

    return cnt;
}

// Insert at beginning
void ins_begin() {
    newnode = create_node();
    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        temp = head;
        while (temp->next != head) temp = temp->next;
        newnode->next = head;
        head = newnode;
        temp->next = head;
    }
    printf("\n%d is inserted at beginning\n", newnode->data);
}

// Insert at given position
void ins_pos(int pos) {
    if (pos < 1 || pos > count() + 1) {
        printf("\nInvalid position\n");
        return;
    }

    if (pos == 1) {
        ins_begin();
        return;
    }

    newnode = create_node();
    temp = head;
    for (int i = 1; i < pos - 1; i++) temp = temp->next;

    newnode->next = temp->next;
    temp->next = newnode;
    printf("\n%d is inserted at position %d\n", newnode->data, pos);
}

// Insert at end
void ins_end() {
    newnode = create_node();
    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newnode;
        newnode->next = head;
    }
    printf("\n%d is inserted at end\n", newnode->data);
}

// Delete from beginning
void del_beg() {
    if (head == NULL) {
        printf("\nEmpty list\n");
        return;
    }

    struct node* to_delete = head;
    if (head->next == head) {
        printf("\n%d is deleted\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != head) temp = temp->next;
    head = head->next;
    temp->next = head;

    printf("\n%d is deleted\n", to_delete->data);
    free(to_delete);
}

// Delete from a position
void del_pos(int pos) {
    if (head == NULL) {
        printf("\nEmpty list\n");
        return;
    }
    int total = count();
    if (pos < 1 || pos > total) {
        printf("\nInvalid position\n");
        return;
    }

    if (pos == 1) {
        del_beg();
        return;
    }

    temp = head;
    for (int i = 1; i < pos - 1; i++) temp = temp->next;

    struct node* to_delete = temp->next;
    temp->next = to_delete->next;

    printf("\n%d is deleted\n", to_delete->data);
    free(to_delete);
}

// Delete from end
void del_end() {
    if (head == NULL) {
        printf("\nEmpty list\n");
        return;
    }

    if (head->next == head) {
        printf("\n%d is deleted\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next->next != head) temp = temp->next;

    struct node* to_delete = temp->next;
    temp->next = head;

    printf("\n%d is deleted\n", to_delete->data);
    free(to_delete);
}

// Display the list
void display() {
    if (head == NULL) {
        printf("\nEmpty list\n");
        return;
    }
    temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main menu
int main() {
    int n;
    while (1) {
        printf("\nSELECT OPERATION\n");
        printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1: {
                int x, pos;
                printf("SELECT INSERTION TYPE:\n1. Insert at beginning\n2. Insert at position\n3. Insert at end\nEnter your choice: ");
                scanf("%d", &x);

                switch (x) {
                    case 1: ins_begin(); break;
                    case 2: 
                        printf("Enter the position to insert node: ");
                        scanf("%d", &pos);
                        ins_pos(pos);
                        break;
                    case 3: ins_end(); break;
                    default: printf("\nInvalid choice for insertion!\n");
                }
                break;
            }
            case 2: {
                int z, pos;
                printf("SELECT DELETION TYPE:\n1. Delete from beginning\n2. Delete from position\n3. Delete from end\nEnter your choice: ");
                scanf("%d", &z);

                switch (z) {
                    case 1: del_beg(); break;
                    case 2: 
                        printf("Enter the position to delete node: ");
                        scanf("%d", &pos);
                        del_pos(pos);
                        break;
                    case 3: del_end(); break;
                    default: printf("\nInvalid choice for deletion!\n");
                }
                break;
            }
            case 3: display(); break;
            case 4: printf("\nExiting\n"); exit(0);
            default: printf("\nInvalid choice\n");
        }
    }
    return 0;
}
