#include <vector>
#include <iostream>
int main(){
    std::vector<int> leftLimits = {0, 1, 2, 3, 0};
    std::vector<int> rightLimits = {0, 1, 2, 3};
    std::vector<int> auxLeft = {};
    std::vector<int> auxRight = {};
    for(int i = 0; i < leftLimits.size()-1; ++i){
        if(!(leftLimits[i] == leftLimits[i+1])){
            auxLeft.push_back(leftLimits[i]);
        }
    }
    if(!(leftLimits.front() == leftLimits.back())){
        auxLeft.push_back(leftLimits.back());
    }
    for(int i = 0; i < rightLimits.size()-1; ++i){
        if(!(rightLimits[i] == rightLimits[i+1])){
            auxRight.push_back(rightLimits[i]);
        }
    }
    if(!(rightLimits.front() == rightLimits.back())){
        auxRight.push_back(rightLimits.back());
    }

    for(int i = 0; i < auxLeft.size(); ++i){
        std::cout << auxLeft[i] << std::endl;
    }
    std::cout << auxLeft.size() << " e " << auxRight.size() << std::endl;
    for(int i = 0; i < auxRight.size(); ++i){
        std::cout << auxRight[i] << std::endl;
    }
    return 0;
}