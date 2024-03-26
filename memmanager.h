#include <iostream>
using namespace std;

struct A{
    int _a;
    double _b;

};

void F(){
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (int i = 0; i <10000;i++){
        A* s = (A*)malloc(sizeof(A));
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Diff(ms) = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
}
int main(){

}
