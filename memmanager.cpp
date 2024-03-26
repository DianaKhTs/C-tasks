#include <iostream>
#include <vector>
using namespace std;

struct A{
    int _a[30];
    double _b;


};
class AMemoryMan{
    private:

    vector<A*>  _data;
    A* _curobj;
    vector<A*> _erased;
    const static int _n = 100000;



    public:
    AMemoryMan(){
        _data.push_back((A*)malloc(sizeof(A)*_n));
       _curobj = _data[0];
    }

    A* Alloc(){
        if (_erased.size()>0){
            A* obj  = _erased.back();
            _erased.pop_back();
            return obj;
        }
        if(_curobj >= _data.back() + _n ){
            _data.push_back((A*)malloc(sizeof(A)*_n));
            _curobj = _data.back();
        }
        return _curobj++;

    }

    void Free(A* obj){
        _erased.push_back(obj);
    }

    ~AMemoryMan(){
        for (A* a:_data){
            free(a);
        }
    }

};

class MemoryMan{
    private:

    uint8_t* _data;
    uint8_t* _curobj;
    vector<uint8_t*> _erased;

    const static int _n = 10000000;



    public:
    MemoryMan(){
        _data = (uint8_t*)malloc(_n);
       _curobj = _data;
    }

    void* Alloc(uint16_t size){
       // cout << "a" << endl;
        if (_erased.size()>0){
            //cout << "b"<<endl;
            for (int i = 0; i < _erased.size();i++){
                if (size <= *((uint16_t*)_erased[i]-1)){
                    void* obj = _erased[i];
                    int16_t remain_size_for_data = *((uint16_t*)_erased[i]-1) - size - 2;
                    if (remain_size_for_data > 0){
                        *(_erased[i]-2) = size;
                        _erased[i]+= size + 2;
                        uint8_t* ptr = _erased[i];
                        *(ptr-2) =  remain_size_for_data;
                        //cout << "upd ersize: " << obj << " " << size << " " << (void*)_erased[i] << " " << remain_size_for_data << endl;
                    }
                    else{
                        _erased.erase(_erased.begin()+i);
                    }
                    return obj;
                }
            }
        }
        if (_curobj >= _data + _n){
            return nullptr;
        }

        *(uint16_t*)_curobj = size;
        _curobj += size + sizeof(uint16_t);
        return _curobj - size; 
        /*
        if (_erased.size()>0){
            A* obj  = _erased.back();
            _erased.pop_back();
            return obj;
        }
        if(_curobj >= _data.back() + _n ){
            _data.push_back((A*)malloc(sizeof(A)*_n));
            _curobj = _data.back();
        }
        return _curobj++;
        */

    }

    void Free(void* obj){
        //cout << "free:" << " " << obj << " " << *((uint16_t*)obj - 1) << endl;
        _erased.push_back((uint8_t*)obj);
    }

    ~MemoryMan(){
      
    }

};
void G(){
    srand(0);
    AMemoryMan k;
    vector<A*> s;
    int sum_time = 0;
    int sum_time_1 = 0;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (int i = 0; i <1000000;i++){
        int t = rand()%100;
        if (t > 30){
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            A* p =  k.Alloc();
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            sum_time+=std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
            s.push_back(p);
        }
        else if (s.size() == 0){
            continue;
        }
        else{
            int num = rand()%s.size();
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            k.Free( s[num]);
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            sum_time_1+=std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
            s.erase(s.begin() + num);
        }
    }
    std::cout << "Diff(ms) = " << sum_time <<" "<<  sum_time_1<< std::endl;
}

void G1(){
    srand(0);
    vector<A*> s;
    int sum_time = 0;
    int sum_time_1 = 0;
    for (int i = 0; i <1000000;i++){
        int t = rand()%100;
        if (t > 30){
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            A* p = (A*)malloc(sizeof(A));
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            sum_time+=std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
            s.push_back(p);
        }
        else if (s.size() == 0){
            continue;
        }
        else{
            int num = rand()%s.size();
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            free(s[num]);
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            sum_time_1+=std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
            s.erase(s.begin() + num);
        }
    }

    std::cout << "Diff(ms) = " << sum_time << " " << sum_time_1 << std::endl;
}

void F(){
    AMemoryMan k;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (int i = 0; i <1000000;i++){
        A* s = k.Alloc();
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Diff(ms) = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
}
void F1(){
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (int i = 0; i <1000000;i++){
        A* s = (A*)malloc(sizeof(A));
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Diff(ms) = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
}

void H1(){
    srand(0);
    MemoryMan k;
    int count = 0;
    vector<void*> s;
    long int sum_time = 0;
    long int sum_time_1 = 0;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (int i = 0; i <100000;i++){
        int t = rand()%100;
        if (t > 30){
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            int n = rand()%5+1;
            void* p =  k.Alloc(n);
            //*(int*)p = 4;
            //cout << p << " " << n << " " << *((uint16_t*)p-1)<<  endl;
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            sum_time+=std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
            if(p!=nullptr)s.push_back(p);
            else{count++;}
        }
        else if (s.size() == 0){
            continue;
        }
        else{
            int num = rand()%s.size();
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            k.Free( s[num]);
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            sum_time_1+=std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
            s.erase(s.begin() + num);
        }
    }
    std::cout << "Diff(ms) = " << sum_time <<" "<<  sum_time_1<< " "<< count << std::endl;

}


void H(){
    srand(0);
    vector<void*> s;
    int sum_time = 0;
    int sum_time_1 = 0;
    for (int i = 0; i <100000;i++){
        int t = rand()%100;
        if (t > 30){
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            void* p = malloc(rand()%5+1);
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            sum_time+=std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
            s.push_back(p);
        }
        else if (s.size() == 0){
            continue;
        }
        else{
            int num = rand()%s.size();
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            free(s[num]);
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            sum_time_1+=std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
            s.erase(s.begin() + num);
        }
    }

    std::cout << "Diff(ms) = " << sum_time << " " << sum_time_1 << std::endl;
}
int main(){
    H1();
    H();
}
