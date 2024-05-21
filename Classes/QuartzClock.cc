#pragma once
#include <iostream>
#include <vector>
#include <unistd.h>
#include "Clock.cc"


class QuartzClock : public Clock{
    std::vector<std::string> listOfSounds;
    public:
    QuartzClock(std::string _brand, double _price, std::string _color): Clock(_brand,_price,_color) {};
    void addSound(){
        int count;
        std::cout<<"How many sounds your quartz clock will have?: ";
        std::cin>>count;
        for(int i = 0; i < count; i++){
            std::string sound;
            std::cout<<"Type "<<i+1<<" sound: ";
            std::cin>>sound;
            listOfSounds.push_back(sound);
        }
    }
    std::string chooseSound(){
        addSound();
        std::cout<<"What sound you like the most?: "<<std::endl;
        for(int i = 0; i<listOfSounds.size(); i++){
            std::cout<<i+1<<'.'<<listOfSounds[i]<<std::endl;
        }
        int decision;
        std::cin>>decision;
        return listOfSounds[decision-1]; 
    }
    void alarm() override{
        std::cout<<chooseSound();
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