


Account *merge(Account *first, Account *second) {
    if (first == nullptr) return second;
    if (second == nullptr) return first;

    if (first->value <= second->value) {
        first->next = merge(first->next, second);
        return first;
    } else {
        second->next = merge(first, second->next);
        return second;
    }
}

Account *MergeSort(Account *head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    // لیست رو به دو قسمت تقسیم می‌کنیم
    Node *second = split(head);

    // هر قسمت رو به‌صورت بازگشتی مرتب می‌کنیم
    head = MergeSort(head);
    second = MergeSort(second);

    // دو قسمت مرتب شده رو ادغام می‌کنیم
    return merge(head, second);
}