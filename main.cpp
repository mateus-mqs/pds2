#include <iostream>
#include <string>
#include <regex>
#include <list>
using namespace std;
int main(){
    std::list<int> str = {};
    str.push_back('a');
    str.push_back('b');
    int *aux = nullptr;
    str.pop_front();
    std::cout << str.front() << endl;
    if(aux == nullptr){
        cout << "sffs" << endl;
    }
    return 0;
}