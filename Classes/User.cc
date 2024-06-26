#pragma once
#include <iostream>
#include <vector>
#include <unistd.h>
#include "Clock.cc"
#include "QuartzClock.cc"
#include "SandClock.cc"
#include "CuckooClock.cc"
#include "Watch.cc"

class User{
    std::string name;
    std::string surname;
    Clock *p = nullptr;
    CuckooClock *cuckoo = nullptr;
    public:
    User(std::string _name, std::string _surname): name(_name), surname(_surname){}
    void questionImportant(){
        std::string choice;
        std::cout<<"What type of clocks you want to use: ";
        std::cin>>choice;
        for(auto &x : choice){
            tolower(x);
        }
        if(choice == "quartz"){
            p = new QuartzClock("rollo",10, "white");
        } else if(choice == "watch"){
            p = new Watch("rollo",10,"white");
        } else if(choice == "sand"){
            p = new SandClock("rollo",10,"white",20);
        } else if(choice == "cuckoo"){
            CuckooClock *cuckoo = new CuckooClock("rollo", 10, "white");
            p = cuckoo;
            int h, m;
            std::cout << "Set the time for the CuckooClock (hour minute): ";
            std::cin >> h >> m;
            cuckoo->setTime(h, m);
            std::cout << "Displaying the current time of the CuckooClock:" << std::endl;
            cuckoo->displayTime();
            cuckoo->tickTock();
        } else{
            throw std::logic_error("Write a type please correctly....");
        }
    };
    void setAlarm(){
        p->alarm();
    }
    const std::string getName() const{
        return name;
    }

    const std::string getSurname() const{
        return surname;
    }
};