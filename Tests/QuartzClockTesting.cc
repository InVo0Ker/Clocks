#include <iostream>
#include <cassert>
#include <unistd.h>
#include "../Classes/Clock.cc"
#include "../Classes/QuartzClock.cc"

bool testBrand(){
    QuartzClock *p = new QuartzClock("rollo",10,"white");
    std::string Brand = p->getBrand();
    assert(Brand == "rollo");
    return true;
}
bool testPrice(){
    QuartzClock *p = new QuartzClock("rollo",10,"white");
    double Price = p->getPrice();
    assert(Price == 10);
    return true;
}
bool testColor(){
    QuartzClock *p = new QuartzClock("rollo",10,"white");
    std::string Color = p->getColor();
    assert(Color == "white");
    return true;
}
bool testChoose(){
    // for example we want bla-bla-bla it will be third option
    QuartzClock *p = new QuartzClock("rollo",10,"white");
    std::string Sound = p->chooseSound();
    assert(Sound == "bla-bla-bla");
    return true;
}

int main(){
    std::cout<<testBrand()<<std::endl;
    std::cout<<testPrice()<<std::endl;
    std::cout<<testColor()<<std::endl;
    std::cout<<testChoose()<<std::endl;
}