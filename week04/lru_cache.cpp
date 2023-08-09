// In the LRU, the key which is has performed
// get() or put() function will be at the front
// of the LRU. When the LRU has reached max
// capacity, the key at the back is evicted 
// from the LRU. The key-value pair can be 
// mapped together to retrieve existing key
// value in constant time. Again to evict
// a key from LRU, which should be a list,
// another key-location pair should be 
// mapped.

// TC = O(1)    [For both functions]
// SC = O(n)    [For both functions]

class LRUCache {
private:
    list<int> lru;
    unordered_map<int, int> keyVal;
    unordered_map<int, list<int>::iterator> keyLoc;
    int _capacity;

    void updateLRU(int key){
        if(keyVal.count(key))
            lru.erase(keyLoc[key]);
        
        lru.push_front(key);
        keyLoc[key] = lru.begin();
    }

    void evict(int key){
        int lastUsedKey = lru.back();
        keyVal.erase(lastUsedKey);
        keyLoc.erase(lastUsedKey);
        lru.pop_back();
    }
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if(keyVal.count(key) == 0) return -1;

        updateLRU(key);
        return keyVal[key];
    }
    
    void put(int key, int value) {
        if(keyVal.count(key) == 0 && _capacity == lru.size())
            evict(key);
        
        updateLRU(key);
        keyVal[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */