#include <iostream>
#include <cassert>
#include "../Classes/CuckooClock.cc"

bool testBrand() {
    CuckooClock clock("CuckooBrand", 15, "black");
    assert(clock.getBrand() == "CuckooBrand");
    return true;
}

bool testPrice() {
    CuckooClock clock("CuckooBrand", 15, "black");
    assert(clock.getPrice() == 15);
    return true;
}

bool testColor() {
    CuckooClock clock("CuckooBrand", 15, "black");
    assert(clock.getColor() == "black");
    return true;
}

bool testSetAndGetTime() {
    CuckooClock clock("CuckooBrand", 15, "black");
    clock.setTime(12, 30);
    assert(clock.getHour() == 12);
    assert(clock.getMinute() == 30);
    return true;
}

int main() {
    std::cout<<testBrand()<<std::endl;
    std::cout<<testPrice()<<std::endl;
    std::cout<<testColor()<<std::endl;
    std::cout<<testSetAndGetTime()<<std::endl;

    return 0;
}
