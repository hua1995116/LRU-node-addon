#ifndef list_h
#define list_h

#include <napi.h>

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    
    Node(int da = 0, Node *p = NULL) {
        this->data = da;
        this->next = p;
    }
};

class List : public Napi::ObjectWrap<List>{
private:
    Node *head, *tail;
    int count = 0;
    int maxCount = 200;
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    static Napi::FunctionReference constructor;
    List(const Napi::CallbackInfo& info);
    // ~List() {
    //     delete head;
    //     delete tail;
    // };
    void SetMax(const Napi::CallbackInfo& info);
    Napi::Value getMax(const Napi::CallbackInfo& info);
    
    // void Print();
    
    void Insert (const Napi::CallbackInfo& info);
    
    // void Delete(int da = 0);
    
    Napi::Value Search(const Napi::CallbackInfo& info);
    
    // void setValueAt(int position, int da);
};

#endif
