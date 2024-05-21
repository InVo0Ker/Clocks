#include <iostream>
#include <cassert>
#include <unistd.h>
#include "../Classes/Clock.cc"

bool testBrand(){
    Clock p("rollo",10,"white");
    std::string Brand = p.getBrand();
    assert(Brand == "rollo");
    return true;
}
bool testPrice(){
    Clock p("rollo",10,"white");
    double Price = p.getPrice();
    assert(Price == 10);
    return true;
}
bool testColor(){
    Clock p("rollo",10,"white");
    std::string Color = p.getColor();
    assert(Color == "white");
    return true;
}

int main(){
    std::cout<<testBrand()<<std::endl;
    std::cout<<testPrice()<<std::endl;
    std::cout<<testColor()<<std::endl;
}