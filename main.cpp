#include <iostream>
#include <string>
using namespace std;
int main(){
    string str, aux;
    int num;
    str = "     ";
    num = str[1];
    for(int i = 0; i < str.size(); ++i){
        cout << num;
    }
    return 0;
}