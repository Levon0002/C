DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* node = new DoublyLinkedListNode(data);
    DoublyLinkedListNode* index = llist;
    if(data < index -> data){
        index -> prev = node;
        node -> prev = nullptr;
        node -> next = index;
        llist = node;
        return llist;
    }
    while(index -> data <  data &&  index -> next != nullptr){
        index = index -> next;
    }
    if(index -> data >= node -> data){
        index -> prev -> next = node;
        node -> prev = index -> prev;
        node -> next = index;
        index -> prev = node;
        return llist;
        
    }
    if(index -> next == nullptr){
        
        index -> next = node;
        node -> prev  = index;
        return llist;
    }
    return llist;
    
}
