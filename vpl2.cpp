#include <iostream>
#include <vector>

using namespace std;
int main() {
    int num, add = 1;
    vector<int> nums;
    vector<int> pares;
    vector<int> impares;
    while(cin >> num){
        nums.push_back(num);
    }

    for(int i = 0; i < nums.size(); i++){
        if(nums[i]%2 == 0){
            for(int j = 0; j < pares.size(); j++){
                if(nums[i] == pares[j]){
                    add = 0;
                    break;
                }
            }
            if(add){pares.push_back(nums[i]);}
        } else {
            for(int j = 0; j < impares.size(); j++){
                if(nums[i] == impares[j]){
                    add = 0;
                    break;
                }
            }
            if(add){impares.push_back(nums[i]);}
        }
        add = 1;
    }
    for(int i = 0; i < pares.size(); i++){
        cout << pares[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < impares.size(); i++){
        cout << impares[i] << " ";
    }
    return 0;
}