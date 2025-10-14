struct Node {
    int key, value;
    Node* prev;
    Node* next;
    
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head; 
    Node* tail; 
    
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }
    
    Node* removeTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        
        head = new Node(0, 0);
        tail = new Node(0, 0);
        
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            moveToHead(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } 
        else{
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);
            
            if(cache.size() > capacity){
                Node* tailNode = removeTail();
                cache.erase(tailNode->key);
                delete tailNode;
            }
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */