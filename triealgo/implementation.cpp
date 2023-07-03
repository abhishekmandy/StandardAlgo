#include<iostream>
using namespace std;
class trieNode{
    public:
    char data;
    trieNode* children[26];
    bool isTerminal;

    trieNode(char ch){
        this->data = ch;
        for(int i=  0;i<26;i++)children[i] = NULL;
        isTerminal = false;
    }
};

class Trie{
    public:
    trieNode* root;
    public:
    Trie(){
        root = new trieNode('\0');
    }

    private:
    void insertUtil(string word, trieNode * root){
        // base case .

        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0]-'A' ; // considering all letterss in caps lock..
        trieNode * child;
        // presernt .
        if(root->children[index] != NULL){
            child = root->children[index];
        }


        // absent.
        else{
            child = new trieNode(word[0]);
            root->children[index] = child;
        }

        // recursive call.
        insertUtil(word.substr(1),child);

    }
    bool srch(string word,trieNode *root){
        // base case.
        if(word.length() == 0){
            return root->isTerminal;
        }
        trieNode * child;
        int index = word[0]-'A';

        if(root->children[index] != NULL){
            // present.
            child = root->children[index];
        }
        else{
            //absent.
            return false;
        }
        return srch(word.substr(1),child);
    }
    void deletew(string word,trieNode*root){
        // base case.
        if(word.length() == 0){
            root->isTerminal = false;
        }

        int index=  word[0]-'A';
        trieNode* child;

        if(root->children[index] != NULL){
            // present.
            child = root->children[index];
            deletew(word.substr(1),child);
        }
        else{
            return;
        }
    }

    void deletewOptimised(string word,trieNode*root){
           // base case.
        if(word.length() == 0){
            root->isTerminal = false;
            return;
        }

        int index=  word[0]-'A';
        trieNode* child;

        if(root->children[index] != NULL){
            // present.
            child = root->children[index];
            deletewOptimised(word.substr(1),child);
            delete root->children[index];
        }
        else{
            return;
        }

    }
    public : 
    void insertWord(string word){
        insertUtil(word,root);
    }
    bool searchWord(string word){
        return srch(word,root);
    }
    void deleteWord(string word){
        // deletew(word, root);
        deletewOptimised(word,root);
    }
};
int main(){
    Trie *t = new Trie();
    t->insertWord("ABCD");
    // t->deleteWord("ABCD");
    if(t->searchWord("ABCD")){
        cout<<"It is present." <<endl;
    }
    else{
        cout<<"It is not present."<<endl;
    }

    
    return 0;
}
