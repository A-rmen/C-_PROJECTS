
DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* node = llist;
    DoublyLinkedListNode* newHead = nullptr;

    while (node != nullptr) {
        DoublyLinkedListNode* temp = node->next;

        node->next = node->prev;
        node->prev = temp;

        newHead = node;
        node = temp;
    }

    return newHead;
}
