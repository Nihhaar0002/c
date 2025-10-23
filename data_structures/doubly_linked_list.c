void ins_pos() {
    int pos;
    printf("\nEnter the position where the node should be inserted: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count() + 1) {
        printf("\nInvalid position!\n");
        return;
    }

    if (pos == 1) {
        ins_beg();
        return;
    }

    struct node *newnode = create_node();  // <<< ADD THIS LINE

    temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }

    temp->next = newnode;
    printf("\n%d is inserted at position %d\n", newnode->data, pos);
}
