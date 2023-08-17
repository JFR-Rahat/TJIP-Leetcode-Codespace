// The previous timestamp for when the message gets printed
// should be mapped together with the message. If the new
// message doesn't arrive at timestamp t+10, then it is
// not printed neither stored.


// TC = O(n)
// SC = O(n)

class Logger {
private:
    unordered_map<string, int> msgAndLastTstamp;

public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        
        if(msgAndLastTstamp.count(message) && msgAndLastTstamp[message]+10 > timestamp)
            return false;
        
        msgAndLastTstamp[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */