// The get() function can be implemented by keeping track 
// of the length of the linked list. Both addAtHead() and addAtTail()
// functions can be implemented using the addAtIndex() function. We need 
// to iterate over the linked list until before the indexed node and then
// create a new node after that and link that node with the previous node 
// and the node in front of it. The deleteAtIndex() function can be simplified
// using a dummy head in the linked list to avoid checking additional condition
// for deleting the head node. Deleting is now simply just un-link the node from
// the nodes around it. Using shared pointer will free up the memory space taken
// by the pointers after going out of scope.


// TC = O(1)    [For addAtHead() and addAtTail()]
// SC = O(1)    [For addAtHead() and addAtTail()]

// TC = O(n)    [For getIndex() and addAtIndex() and deleteAtIndex()]
// SC = O(1)    [For getIndex() and addAtIndex() and deleteAtIndex()]

class MyLinkedList {
private:
    class Node{
    public:
        int value;
        shared_ptr<Node> next;
        Node(int _value, shared_ptr<Node> _next){

            value = _value;
            next = _next;
        }
    };

    int length;
    shared_ptr<Node> dummyHead = nullptr;   

public:
    MyLinkedList() {
        
        length = 0;
        dummyHead = make_shared<Node>(0, nullptr);
    }
    
    int get(int index) {
        if(index >= length)
            return -1;
        
        auto currNode = dummyHead->next;
        while(index--)
            currNode = currNode->next;

        return currNode->value;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(length, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > length)
            return;
        
        auto currNode = dummyHead;
        while(index--)
            currNode = currNode->next;
        
        auto newNode = make_shared<Node>(val, nullptr);
        newNode->next = currNode->next;
        currNode->next = newNode;
        length++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= length)
            return;
        
        auto currNode = dummyHead;
        while(index--)
            currNode = currNode->next;
        
        auto nodeToRemove = currNode->next;
        currNode->next = nodeToRemove->next;

        length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */