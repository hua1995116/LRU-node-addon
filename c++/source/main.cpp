#include <iostream>
#include "list.hpp"

using namespace std;

int main() {
    
    List list;
    list.SetMax(10);
    list.Insert("10", "hello");
    list.Insert("11", "world");
    list.Insert("12", "hi1");
    list.Insert("13", "hi2");
    list.Insert("14", "hi3");
    list.Insert("15", "hi4");
    list.Insert("16", "hi5");
    list.Insert("17", "hi6");
    list.Insert("18", "hi7");
    list.Insert("19", "hi8");
    list.Insert("20", "hi9");
    list.Insert("21", "hi10");
    
    list.Search("10");
    list.Print();
    
    return 0;
}
