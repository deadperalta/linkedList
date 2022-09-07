struct Node {
  Node* link;
  int data;
  Node(int val)
  {
    data=val;
  }
};

struct Queue {
  Node* front,*rear;
};

void enQueue(Queue* q,int data)
{
  struct Node* temp=new Node(data);
  
  if(q->front == q->rear)
  {
    q->front=temp;
  }
  else
  {
    q->rear->link=temp;
  }
  
  q->rear=temp;
  q->rear->link=q->front;
}

int deque(Queue* q)
{
  if(q->front == NULL)
  {
    cout<<"Queue is empty";
    return -1;
  }
  
  else if(q->front == q->rear)
  {
    struct Node* temp=q->front;
    int val=temp->data;
    delete temp;
  }
  
  else
  {
    struct Node* temp=q->front;
    int val=temp->data;
    q->front=q->front->link;
    q->rear->link=q->front;
    delete temp;
    return val;
  }
  return -1;
}
