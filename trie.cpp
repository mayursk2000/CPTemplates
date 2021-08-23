struct Trie{
        struct Node{
            int cnt=0;
            Node* nxt[26];
                
            Node(){
                for(int i=0;i<26;i++)
                    nxt[i]=NULL;
            }
        };
        Node* head;
            
        Trie() {
            head= new Node();
        }
            
        /** Inserts a word into the trie. */
        void insert(string word) {
            Node* cur = head;
            int n=word.length();
            for(int i = 0; i< n; i++)
            {
                int b =word[i]-'a';
                if(!cur -> nxt[b])
                    cur -> nxt[b] = new Node();
                cur = cur -> nxt[b];
                cur -> cnt++;
            }
        }
            
        /** Returns if the word is in the trie. */
        bool search(string word) {
            Node* cur = head;
            int n=word.length();
            int cou=0;
            for(int i = 0; i< n; i++)
            {
                int b =word[i]-'a';
                if(!cur -> nxt[b]){
                    return false;
                }
                cur = cur -> nxt[b];
                    
            }
            int c=cur->cnt;
            for(int i=0;i<26;i++){
                if(cur->nxt[i]!=NULL)
                    cou+=cur->nxt[i]->cnt;
            }
            if(cou<c)
                return true;
            else
                return false;
        }
            
        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix) {
            Node* cur = head;
            int n=prefix.length();
            for(int i = 0; i< n; i++)
            {
                int b =prefix[i]-'a';
                if(!cur -> nxt[b]){
                    return false;
                }
                cur = cur -> nxt[b];
            }
            return true;
        }
};
