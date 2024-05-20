#include <iostream>
#include <vector>
#include <unistd.h>

class Clock{
    protected:
    std::string brand;
    std::string color; 
    double price;
    public:
    Clock(std::string _brand, double _price, std::string _color): brand(_brand), price(_price), color(_color){}
    virtual void alarm(){
        std::cout<<"Bell singing...";
    }
    virtual void hang(){
        std::cout<<"Done";
    }
    const std::string getBrand() const{
        return brand;
    }
    const double getPrice() const{
        return price;
    }
    virtual ~Clock(){};
};