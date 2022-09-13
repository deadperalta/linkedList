// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way
class Node 
{
    public:
    Node* next;
    Node* prev;
    
    int key,val;
    
    Node(int k,int v)
    {
        key=k;
        val=v;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache
{
    private:

    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    
    int size;
    unordered_map<int,Node*>keyToNode;
    
    
    void addNode(Node* node)
    {
        Node* headNext=head->next;
        
        node->next=headNext;
        headNext->prev=node;
        
        node->prev=head;
        head->next=node;
    }
    
    void deleteNode(Node* node)
    {
        Node* nodePrev=node->prev;
        Node* nodeNext=node->next;
        
        nodePrev->next=nodeNext;
        nodeNext->prev=nodePrev;
    }
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        size=cap;
        head->next=tail;
        tail->prev=head;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(keyToNode.find(key) != keyToNode.end())
        {
            Node* neededNode=keyToNode[key];
            deleteNode(neededNode);
            addNode(neededNode);
            keyToNode[key]=head->next;
            return neededNode->val;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if(keyToNode.find(key) != keyToNode.end())
        {
            Node* foundNode=keyToNode[key];
            deleteNode(foundNode);
            
            keyToNode.erase(key);
            
            Node* node=new Node(key,value);
            addNode(node);
            
            keyToNode[key]=head->next;
        }
        else if(keyToNode.size() == size)
        {
            Node* extraNode=tail->prev;
            deleteNode(tail->prev);
            
            keyToNode.erase(extraNode->key);
            
            Node* node=new Node(key,value);
            addNode(node);
            
            keyToNode[key]=head->next;
        }
        else
        {
            Node* node=new Node(key,value);
            addNode(node);
            
            keyToNode[key]=head->next;
        }
        // your code here   
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
