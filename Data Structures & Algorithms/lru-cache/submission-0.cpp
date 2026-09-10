class LRUCache {
public:
    // doubly ll chahiye isliye node ki class banayenge
    class Node{
        public:
        int key, val;
        Node* next;
        Node* prev;

        Node(int k, int v){
            key = k;
            val = v;
            next = prev = NULL;
        }
    };

    unordered_map<int, Node*>m; // yeh chahiye ki hum dekh sake ki task cache mein hai ya nhi
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    void addNode(Node* newNode){
        Node* oldNode = head->next;
        head->next = newNode;
        newNode->prev = head;

        newNode->next = oldNode;
        oldNode->prev = newNode;
    }

    void delNode(Node* oldNode){
        Node* oldNext = oldNode->next;
        Node* oldPrev = oldNode->prev;

        oldNext->prev = oldPrev;
        oldPrev->next = oldNext;
    }

    int limit;
    LRUCache(int capacity) {
        limit = capacity;

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;

        Node* getNode = m[key];

        delNode(getNode);
        addNode(getNode);

        m[key] = getNode;

        return getNode->val;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* oldNode = m[key];
            m.erase(oldNode->val);
            delNode(oldNode);
        }
        if(m.size() == limit){
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};
