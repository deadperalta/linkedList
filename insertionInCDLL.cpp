void insertion(Node* start,int value)
{
  Node* temp=new Node(value);
  
  //empty list;
  if(start == NULL)
  {
    temp->next=temp;
    temp->prev=temp;
    start=tmp;
    return;
  }
  
  //insert in start;
  Node* last=start->prev;
  temp->next=start;
  last->next=temp;
  temp->prev=last;
  start->prev=temp;
  start=prev;
  return;
  
  // insert in end;
  Node* last=start->prev;
  temp->next=start;
  last->next=temp;
  temp->prev=last;
  start->prev=temp;
  //start=prev;
  return;
  
