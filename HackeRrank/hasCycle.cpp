
bool has_cycle(Node* head) {
    Node* one = head;
    Node* two = head;

    while (two != nullptr && two->next != nullptr) {
        one = one->next;
        two = two->next->next;

        if (one == two) {
            return true;
        }
    }

    return false;
}
