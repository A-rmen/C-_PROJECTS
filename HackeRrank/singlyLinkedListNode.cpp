
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newItem = new SinglyLinkedListNode(data);

    if (position == 0) {
        newItem->next = llist;
        return newItem;
    }

    SinglyLinkedListNode* temp = llist;

    for (int i = 1; i < position && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        delete newItem;
        return llist;
    }

    newItem->next = temp->next;
    temp->next = newItem;

    return llist;
}
