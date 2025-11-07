DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* tmp;
    DoublyLinkedListNode* index = llist;
    while(index -> next != nullptr){
        if(index == llist){
            index -> prev = index -> next;
            index -> next = nullptr;
            index = index -> prev ;
        }else{
            tmp = index -> next;
            index -> next = index -> prev;
            index -> prev = tmp;
            index = index -> prev;
        }
    
    }
    index -> next = index -> prev;
    index -> prev = nullptr;
    return index;
}