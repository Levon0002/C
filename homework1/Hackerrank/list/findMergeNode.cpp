int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    int result;
    int lenght1=0, lenght=0;
    int lenght2=0;
    SinglyLinkedListNode* index1=head1, *index2=head2;
    while(index1 != nullptr){
        lenght1++;
        index1 = index1->next;
    }
    while(index2 != nullptr){
        lenght2++;
        index2 = index2->next;
    }
    if(lenght1 == lenght2){
        while(head1!= head2){
            head1=head1->next;
            head2=head2->next;
        }
        result = head1->data;
    }else if(lenght1 > lenght2){
        lenght = lenght1 - lenght2;
        for(int i=0; i < lenght; ++i){
            head1 = head1->next;
        }
        while(head1 != head2 ){
            head1=head1->next;
            head2=head2->next;
        }
        result = head1->data;
    }else{
        lenght = lenght2 - lenght1;
        for(int i=0; i < lenght; ++i){
            head2 = head2->next;
        }
        while(head1 != head2){
            head1=head1->next;
            head2=head2->next;
        }
        result = head1->data;
        
    }
    return result;
    
    
    
}