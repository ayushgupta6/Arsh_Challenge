//link: https://leetcode.com/problems/lru-cache/description/

class LRUCache {
public:
    class Node{
        public:
        int val;
        int key;
        Node* prev;
        Node* next;
        Node(int _key, int _val){
            val= _val;
            key= _key;
            prev = NULL;
            next = NULL;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;
    unordered_map<int,Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    Node* addNode(int nkey, int nval){
        Node* t = new Node(nkey, nval);
        head->next->prev = t;
        t->prev = head;
        t->next = head->next;
        head->next = t;
        return t;
    }

    void Delete(Node* delNode){
        delNode->next->prev = delNode->prev;
        delNode->prev->next = delNode->next;
    }
    
    int get(int key_) {
        int ans=-1;
        if(mp.find(key_)!=mp.end()){
            ans = mp[key_]->val;
            Delete(mp[key_]);
            mp.erase(key_);
            Node* c = addNode(key_,ans);
            mp[key_] = c;
        }
        return ans;
    }
    
    void put(int key_, int value) {
        if (mp.find(key_) != mp.end()) {
            Node * existingnode = mp[key_];
            mp.erase(key_);
            Delete(existingnode);
        }
        if (mp.size() == cap) {
            mp.erase(tail -> prev -> key);
            Delete(tail -> prev);
        }

        Node *c =addNode(key_, value);
        mp[key_] = c;  
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
