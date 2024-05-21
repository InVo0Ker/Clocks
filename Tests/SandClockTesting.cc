#include <iostream>
#include <cassert>
#include <unistd.h>
#include "../Classes/Clock.cc"
#include "../Classes/SandClock.cc"

bool testBrand(){
    SandClock *p = new SandClock("rollo",10,"white",10);
    std::string Brand = p->getBrand();
    assert(Brand == "rollo");
    return true;
}
bool testPrice(){
    SandClock *p = new SandClock("rollo",10,"white",10);
    double Price = p->getPrice();
    assert(Price == 10);
    return true;
}
bool testColor(){
    SandClock *p = new SandClock("rollo",10,"white",10);
    std::string Color = p->getColor();
    assert(Color == "white");
    return true;
}
bool testMinute(){
    SandClock *p = new SandClock("rollo",10,"white",10);
    int Minutes = p->minutesGet();
    assert(Minutes == 10);
    return true;
}
bool testAlarmException(){
    try{
        SandClock *p = new SandClock("rollo",10,"white",10); 
        p->alarm();
    } catch(std::logic_error& err){
        assert(std::string(err.what()) == std::string("Sand clock doesn't have alarm, they have timer! "));
    }
    return true;
}
bool testHangException(){
    try{
        SandClock *p = new SandClock("rollo",10,"white",10); 
        p->hang();
    } catch(std::logic_error& err){
        assert(std::string(err.what()) == std::string("What do you mean hang sand clock, can't do that! "));
    }
    return true;
}

int main(){
    std::cout<<testBrand()<<std::endl;
    std::cout<<testPrice()<<std::endl;
    std::cout<<testColor()<<std::endl;
    std::cout<<testMinute()<<std::endl;
    std::cout<<testHangException()<<std::endl;
    std::cout<<testAlarmException()<<std::endl;
}