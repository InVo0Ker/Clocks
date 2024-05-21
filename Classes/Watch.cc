#pragma once
#include <iostream>
#include <vector>
#include <unistd.h>
#include "Clock.cc"


class Watch : public Clock{
    std::string nameOfSound;
    public:
    Watch(std::string _brand, double _price, std::string _color): Clock(_brand,_price,_color) {};
    std::string setSound(){
        std::cout<<"Write a name of sound that you want to hear first when you will wake up: "<<std::endl;
        std::cin>>nameOfSound;
        return nameOfSound;
    }
    void useSound(){
        std::cout<<".::Playing::. "<<setSound();
    }
    void alarm() override{
        useSound();
    }
    void hang() override{
        throw std::logic_error("What do you mean hang, I can't do it!");
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
};