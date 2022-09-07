Node* h=*head;
    
    if(h->data == key)
    {
        Node* curr=h;
        if(curr->next == h)
        {
            h=NULL;
        }
        while(curr->next != h)
        {
            curr=curr->next;
        }
        curr->next=h->next;
        h=curr->next;
    }
    else
    {
        Node* curr=h;
        
        while(curr->next->data != key)
        {
            curr=curr->next;
        }
        curr->next=curr->next->next;
    }
