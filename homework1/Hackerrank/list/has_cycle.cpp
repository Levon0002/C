bool has_cycle(Node* head) {
    bool result;
    Node* index = head;
    Node* fast_index;
    if(head != nullptr && head->next != nullptr  ){
        fast_index = head->next;
    }else{
        result = false;
        return result;
    }
    while(fast_index != nullptr && fast_index->next != nullptr){
        if(index == fast_index){
            result = true;
            return result;
        }
        index = index->next;
        fast_index = fast_index->next->next;
        
    }
    result = false;
    return result;
    
}