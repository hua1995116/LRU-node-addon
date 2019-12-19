#include "list.h"
#include <iostream>
#include <map>
#include <iostream>
#include <string>

#define INITVALUE ""

Napi::FunctionReference List::constructor;

Napi::Object List::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func =
      DefineClass(env,
                  "List",
                  {
                    InstanceMethod("SetMax", &List::SetMax),
                    InstanceMethod("getMax", &List::getMax),
                    InstanceMethod("Insert", &List::Insert),
                    InstanceMethod("Search", &List::Search),
                    InstanceMethod("Print", &List::Print),
                   });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("List", func);
  return exports;
}

List::List(const Napi::CallbackInfo& info) : Napi::ObjectWrap<List>(info) {
    this->head = this->tail = NULL;
}

void List::SetMax(const Napi::CallbackInfo& info) {
    int length = info.Length();
    Napi::Env env = info.Env();

     if (length <= 0 || !info[0].IsNumber()) {
        Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    }

    Napi::Number value = info[0].As<Napi::Number>();

    int cvalue = value.Int32Value();

    if(cvalue < 10) {
        Napi::TypeError::New(env, "min count is 10").ThrowAsJavaScriptException();
    }

    this->maxCount = cvalue;
}

Napi::Value List::getMax(const Napi::CallbackInfo& info) {
    int num = this->maxCount;
    return Napi::Number::New(info.Env(), num);
}

Napi::Value List::Print(const Napi::CallbackInfo& info) {
    // array https://github.com/nodejs/node-addon-api/issues/423
    Node *p = this->head;
    Napi::Array arr = Napi::Array::New(info.Env(), this->count);

    int i = 0;
    while(p != NULL) {
        string key = p->data;
        map<string ,string >::iterator l_it;
        l_it = this->cachemap.find(key);

        if(l_it != this->cachemap.end()) {
            arr[i] = Napi::String::New(info.Env(), l_it->second);
        }
        i++;
        p = p->next;
    }
    
    return arr;
}

// void List::Delete(int da) {
//     Node *p = head, *q = head;
//     if(p == NULL) {
//         cout << "can't find value %d" << da << endl;
//         return;
//     }
//     int value = -1;
//     while (p != NULL) {
//         if(p->data == da) {
//             value = da;
//             break;
//         }
//         q = p;
//         p = p->next;
//     }
//     if(p == NULL) {
//         cout << "del can't find value " << da << endl;
//     } else {
//         q->next = p->next;
//         cout << "del value " << da << endl;
//     }
// }
void List::Insert(const Napi::CallbackInfo& info) {
    int length = info.Length();
    Napi::Env env = info.Env();

     if (length <= 1 || !info[0].IsString() || !info[1].IsString()) {
        Napi::TypeError::New(env, "key and value expected").ThrowAsJavaScriptException();
    }
    Napi::String key = info[0].As<Napi::String>();
    Napi::String value = info[1].As<Napi::String>();

    string da = key.ToString();

    if(this->count >= this->maxCount) {
        this->tail->prev->next = NULL;
        this->tail = this->tail->prev;
        
        Node *p = new Node(da);
        this->cachemap.insert(std::pair<string, string>(da, value));
        p->next = this->head;
        this->head->prev = p;
        this->head = p;
        this->head->prev = NULL;
        
        return;
    }
    if(this->head == NULL) {
        this->head = this->tail = new Node(da);
        this->cachemap.insert(std::pair<string, string>(da, value));
        this->head->next = NULL;
        this->head->prev = NULL;
        this->tail->next = NULL;
        this->tail->prev = NULL;
    } else {
        Node *p = new Node(da);
        this->cachemap.insert(std::pair<string, string>(da, value));
        this->head->prev = p;
        p->next = this->head;
        p->prev = NULL;
        this->head = p;
    }
    this->count++;
}

Napi::Value List::Search(const Napi::CallbackInfo& info) {
    int length = info.Length();
    Napi::Env env = info.Env();

     if (length <= 0 || !info[0].IsString()) {
        Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
    }
    Napi::String value = info[0].As<Napi::String>();
    string da = value.ToString();

    Node *p = this->head;
    
    if(p == NULL) {
        return Napi::String::New(info.Env(), INITVALUE);
    }
    
    int count = -1;
    int i = 0;
    

    while( p!= NULL) {
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
        p->next = this->head;
        p->prev = NULL;
        this->head->prev = p;
        this->head = p;
        map<string ,string >::iterator l_it;
        l_it = this->cachemap.find(da);
        if(l_it == this->cachemap.end()) {
            return Napi::String::New(info.Env(), INITVALUE);
        } else {
            return Napi::String::New(info.Env(), l_it->second);
        }

    } else {
        return Napi::String::New(info.Env(), INITVALUE);
    }
    return Napi::String::New(info.Env(), INITVALUE);
}
