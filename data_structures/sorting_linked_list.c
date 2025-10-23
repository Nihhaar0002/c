#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* next;
} *head = NULL, *p = NULL, *q = NULL;

// Check if list is empty
bool is_empty() {
    return (head == NULL);
}

// Count nodes in the list
int count() {
    int length = 0;
    if (is_empty()) return 0;

    p = head;
    while (p != NULL) {
        length++;
        p = p->next;
    }
    return length;
}

// Create a new node
struct node* create_node() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

// Insert at beginning
void ins_beg() {
    struct node* newnode = create_node();
    if (is_empty()) {
        head = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
    printf("\n%d is inserted at beginning\n", newnode->data);
}

// Insert at position
void ins_pos(int po) {
    if (po < 1 || po > count() + 1) {
        printf("\nInvalid position!\n");
        return;
    }

    if (po == 1) {
        ins_beg();
        return;
    }

    struct node* newnode = create_node();
    p = head;
    for (int i = 1; i < po - 1; i++) p = p->next;

    newnode->next = p->next;
    p->next = newnode;

    printf("\n%d is inserted at position %d\n", newnode->data, po);
}

// Insert at end
void ins_end() {
    struct node* newnode = create_node();
    if (is_empty()) {
        head = newnode;
    } else {
        p = head;
        while (p->next != NULL) p = p->next;
        p->next = newnode;
    }
    printf("\n%d is inserted at end\n", newnode->data);
}

// Delete from beginning
void del_begin() {
    if (is_empty()) {
        printf("\nEmpty list. Deletion not possible.\n");
        return;
    }
    p = head;
    head = p->next;
    printf("\n%d is deleted\n", p->data);
    free(p);
}

// Delete from end
void del_end() {
    if (is_empty()) {
        printf("\nEmpty list. Deletion not possible.\n");
        return;
    }
    if (head->next == NULL) {
        printf("\n%d is deleted\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    p = head;
    while (p->next != NULL) {
        q = p;
        p = p->next;
    }
    printf("\n%d is deleted\n", p->data);
    free(p);
    q->next = NULL;
}

// Delete from position
void del_pos(int pos) {
    if (pos < 1 || pos > count()) {
        printf("\nInvalid position!\n");
        return;
    }
    if (pos == 1) {
        del_begin();
        return;
    }

    p = head;
    for (int i = 1; i < pos; i++) {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    printf("\n%d is deleted\n", p->data);
    free(p);
}

// Display the list
void display() {
    if (is_empty()) {
        printf("\nEmpty list\n");
        return;
    }
    p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// Find maximum element
void max() {
    if (is_empty()) {
        printf("\nEmpty list\n");
        return;
    }
    p = head;
    int m = p->data;
    while (p != NULL) {
        if (p->data > m) m = p->data;
        p = p->next;
    }
    printf("\n%d is the maximum element\n", m);
}

// Find minimum element
void min() {
    if (is_empty()) {
        printf("\nEmpty list\n");
        return;
    }
    p = head;
    int m = p->data;
    while (p != NULL) {
        if (p->data < m) m = p->data;
        p = p->next;
    }
    printf("\n%d is the minimum element\n", m);
}

// Sort the linked list (Bubble Sort)
void sort() {
    if (is_empty()) {
        printf("\nEmpty list\n");
        return;
    }

    int size = count();
    int temp;
    for (int i = 0; i < size - 1; i++) {
        p = head;
        for (int j = 0; j < size - i - 1; j++) {
            if (p->data > p->next->data) {
                temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            }
            p = p->next;
        }
    }
    printf("\nSorted list:\n");
    display();
}

// Search for an element
void search(int key) {
    if (is_empty()) {
        printf("\nEmpty list\n");
        return;
    }
    p = head;
    int pos = 0;
    bool found = false;
    while (p != NULL) {
        pos++;
        if (p->data == key) {
            found = true;
            break;
        }
        p = p->next;
    }
    if (found)
        printf("\nElement found at position %d\n", pos);
    else
        printf("\nElement not found\n");
}

// Reverse the list
void reverse_list() {
    if (is_empty()) {
        printf("\nEmpty list\n");
        return;
    }
    struct node *current = head, *prev = NULL, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("\nReversed list:\n");
    display();
}

// Main menu
int main() {
    int n;
    while (1) {
        printf("\nSELECT OPERATION\n");
        printf("1. Insertion\n2. Deletion\n3. Display\n4. Maximum\n5. Minimum\n6. Sort\n7. Length\n8. Search\n9. Reverse the list\n10. Exit\nEnter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1: {
                int x, pos;
                printf("SELECT INSERTION TYPE:\n1. Insert at beginning\n2. Insert at position\n3. Insert at end\nEnter your choice: ");
                scanf("%d", &x);
                switch (x) {
                    case 1: ins_beg(); break;
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
                    case 1: del_begin(); break;
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
            case 4: max(); break;
            case 5: min(); break;
            case 6: sort(); break;
            case 7: printf("\nNumber of nodes: %d\n", count()); break;
            case 8: {
                int key;
                printf("\nEnter key element: ");
                scanf("%d", &key);
                search(key);
                break;
            }
            case 9: reverse_list(); break;
            case 10: printf("\nExiting\n"); exit(0);
            default: printf("\nInvalid choice\n");
        }
    }
    return 0;
}
