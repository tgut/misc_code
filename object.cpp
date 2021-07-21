#include<iostream>
#include<memory>

class A_define{
    public:
        int a;
        A_define();
        A_define(int b){
            a = b;
        }
       static std::shared_ptr<A_define> make(int c){
            return std::make_shared<A_define>(c);
        };
};

int main(){
    class A_define a;
    // a.make();
    std::cout <<"a.make's pointer is: "<< a.make(4)<<std::endl;
}