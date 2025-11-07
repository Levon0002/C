SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode*  Node = new SinglyLinkedListNode(data);
    
    SinglyLinkedListNode* index =  llist;
    for(int i = 1; i <= position; ++i){
        if(i == position){
            Node -> next = index -> next;
            index -> next =  Node;
            
        }
        index = index -> next;  
    }
            return llist;
    
}
