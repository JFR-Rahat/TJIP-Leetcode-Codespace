// We can use a vector to act as the randomizedSet. Since we
// can insert item only if it is not present in the vector
// and also need to remove particular element if it exists, we
// have to keep track of the existence of the numbers as well as
// their position in the vector. For removing the element, knowing 
// its position, we can swap it with the last element of the vector 
// and then pop it from there in O(1) time. The position of the swapped
// element needs to be updated then. For getting random number from the 
// vector, any random function would do the work.

// For each function
// TC = O(1)
// SC = O(n)

class RandomizedSet {
private:
    vector<int> randomizedSet;
    unordered_map<int, int> valPos;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(valPos.find(val) == valPos.end()){

            randomizedSet.push_back(val);
            valPos[val] = randomizedSet.size() - 1;
            return true;
        }

        return false;
    }
    
    bool remove(int val) {
        
        if(valPos.find(val) != valPos.end()){

            int removedPos = valPos[val];
            swap(randomizedSet[removedPos] ,randomizedSet[randomizedSet.size()-1]);
            randomizedSet.pop_back();
            valPos[randomizedSet[removedPos]] = removedPos;
            valPos.erase(val);

            return true;
        }

        return false;
    }
    
    int getRandom() {
        
        int randPos = rand() % randomizedSet.size();
        return randomizedSet[randPos];
    }

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */