
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* item = new DoublyLinkedListNode(data);

    if (llist == nullptr || data <= llist->data) {
        item->next = llist;

        if (llist != nullptr) {
            llist->prev = item;
        }

        return item;
    }

    DoublyLinkedListNode* temp = llist;

    while (temp->next != nullptr && temp->next->data < data) {
        temp = temp->next;
    }

    item->next = temp->next;
    item->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = item;
    }

    temp->next = item;

    return llist;
}
