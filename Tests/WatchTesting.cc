#include <iostream>
#include <cassert>
#include <unistd.h>
#include "../Classes/Clock.cc"
#include "../Classes/Watch.cc"

bool testBrand(){
    Watch *p = new Watch("rollo",10,"white");
    std::string Brand = p->getBrand();
    assert(Brand == "rollo");
    return true;
}
bool testPrice(){
    Watch *p = new Watch("rollo",10,"white");
    double Price = p->getPrice();
    assert(Price == 10);
    return true;
}
bool testColor(){
    Watch *p = new Watch("rollo",10,"white");
    std::string Color = p->getColor();
    assert(Color == "white");
    return true;
}
bool testHangException(){
    try{
        Watch *p = new Watch("rollo",10,"white"); 
        p->hang();
    } catch(std::logic_error& err){
        assert(std::string(err.what()) == std::string("What do you mean hang, I can't do it!"));
    }
    return true;
}

int main(){
    std::cout<<testBrand()<<std::endl;
    std::cout<<testPrice()<<std::endl;
    std::cout<<testColor()<<std::endl;
    std::cout<<testHangException()<<std::endl;
}