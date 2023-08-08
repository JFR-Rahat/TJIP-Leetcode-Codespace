// The keys will be moded to fit in a specified range
// to make the map size smaller. This can create collision
// in the map for different keys, so the collided keys
// will be stored as a list in their index. The list
// would have a really small size, therefore traversing
// it in linear time will not hurt that much.

// TC = O(1)            [for each function]
// SC = O(CAPACITY)     [for each function]

class MyHashMap {
private:
    class Node{
    public:
        int key, value;
        Node* next;

        Node (int _key, int _value, Node* _next){

            key = _key;
            value = _value;
            next = _next;
        }
    };
    const static int CAPACITY = 1997;
    const static int BASE = 997;
    const static int OFFSET = 1981;
    Node* mapping[CAPACITY] = {};

    int calHash(int key){
        return ((key*BASE) + OFFSET) % CAPACITY;
    }
        
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        remove(key);

        int H = calHash(key);
        auto node = new Node(key, value, mapping[H]);
        mapping[H] = node;
    }
    
    int get(int key) {
        int H = calHash(key);
        auto node = mapping[H];
        while(node){
            if(node->key == key)
                return node->value;
            
            node = node->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int H = calHash(key);
        auto node = mapping[H];

        if(node == nullptr)return;
        
        if(node->key == key){
            mapping[H] = node->next;
            delete(node);
            return;
        }
        else{
            while(node && node->next){
                if(node->next->key == key){
                    auto toBeRemoved = node->next;
                    node->next = toBeRemoved->next;
                    delete(toBeRemoved);
                    return;
                }
                node = node->next;
            }
        }
    
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */