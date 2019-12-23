#include <iostream>
#include "list.hpp"
#include <string>
#include <unordered_map>

using namespace std;

void List::SetMax(int da) {
    maxCount = da;
}

void List::Print() {
    Node *p = head;
    
    while(p != NULL) {
        string key = p->data;
        unordered_map<string ,string >::iterator l_it;
        l_it = this->cachemap.find(key);
        
        if(l_it != this->cachemap.end()) {
            cout << l_it->second << endl;
        }
        p = p->next;
    }
}

void List::Delete(string da) {
    Node *p = head, *q = head;
    if(p == NULL) {
        cout << "can't find value %d" << da << endl;
        return;
    }
    string value = "";
    while (p != NULL) {
        if(p->data == da) {
            value = da;
            break;
        }
        q = p;
        p = p->next;
    }
    if(p == NULL) {
        cout << "del can't find value " << da << endl;
    } else {
        q->next = p->next;
        cout << "del value " << da << endl;
    }
}

void List::Insert(string da, string value) {
    if(count >= maxCount) {
        tail->prev->next = NULL;
        tail = tail->prev;
        
        Node *p = new Node(da);
        cachemap.insert(pair<string, string>(da, value));
        p->next = head;
        head->prev = p;
        head = p;
        head->prev = NULL;
        
        return;
    }
    if(head == NULL) {
        head = tail = new Node(da);
        cachemap.insert(pair<string, string>(da, value));
        head->next = NULL;
        head->prev = NULL;
        tail->next = NULL;
        tail->prev = NULL;
    } else {
        Node *p = new Node(da);
        cachemap.insert(pair<string, string>(da, value));
        head->prev = p;
        p->next = head;
        p->prev = NULL;
        head = p;
    }
    count++;
}

void List::Search(string da) {
    Node *p = head;
    
    if(p == NULL) {
        cout << "can't find" << endl;
        return;
    }
    
    int count = -1;
    int i = 0;
    while( p!= NULL ) {
        if(p->data == da) {
            count = i;
            break;
        }
        p = p->next;
        i ++;
    }
    if(count != -1) {
        p->prev->next = p->next;
        if(p->next != NULL) {
            p->next->prev = p->prev;
        }
        p->next = head;
        p->prev = NULL;
        head->prev = p;
        head = p;
        
        unordered_map<string ,string >::iterator l_it;
        l_it = this->cachemap.find(da);
        if(l_it == this->cachemap.end()) {
            cout << "can't find key " << da << endl;
        } else {
            cout << "find value is " << l_it->second << endl;
        }
    } else {
        cout << "can't find key" << da << endl;
    }
}
