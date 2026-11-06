
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* first = head1;
    SinglyLinkedListNode* second = head2;

    while (first != second) {
        first = (first == nullptr) ? head2 : first->next;
        second = (second == nullptr) ? head1 : second->next;
    }

    return first->data;
}
