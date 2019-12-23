#ifndef list_hpp
#define list_hpp

#include <stdio.h>
#include <unordered_map>
#include <string>

using namespace std;

class Node {
public:
    string data;
    Node *next;
    Node *prev;
    
    Node(string da, Node *p = NULL) {
        this->data = da;
        this->next = p;
    }
};

class List {
private:
    Node *head, *tail;
    int position;
    int count = 0;
    int maxCount = 200;
    unordered_map <string, string> cachemap;
public:
    List() {
        head = tail = NULL;
    };
    void SetMax(int da);
    
    void Print();
    
    void Insert (string da, string value);
    
    void Delete(string da);
    
    void Search(string da);
    
};
#endif /* list_hpp */
