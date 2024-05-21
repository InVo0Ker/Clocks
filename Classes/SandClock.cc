#pragma once
#include <iostream>
#include <vector>
#include <unistd.h>
#include "Clock.cc"



class SandClock : public Clock{
    int holdMinutes;
    public:
    SandClock(std::string _brand, double _price, std::string _color, int _holder): Clock(_brand,_price,_color), holdMinutes(_holder){};
    void flipSandClock(){
        std::cout<<"Done "<<std::endl;
    };
    void hang() override{
        throw std::logic_error("What do you mean hang sand clock, can't do that! ");
    }
    void alarm() override{
        throw std::logic_error("Sand clock doesn't have alarm, they have timer! ");
    }
    void timer(){
        sleep(holdMinutes);
        std::cout<<"Done "<<std::endl;
    }
    const std::string getBrand() const{
        return brand;
    }
    const double getPrice() const{
        return price;
    }
    const std::string getColor() const{
        return color;
    }
    const int minutesGet() const{
        return holdMinutes;
    }
};