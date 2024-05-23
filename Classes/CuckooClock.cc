#pragma once
#include <iostream>
#include <vector>
#include <unistd.h>
#include "Clock.cc"

class CuckooClock : public Clock {
    std::vector<std::string> listOfSounds;
    int hour;
    int minute;

public:
    CuckooClock(std::string _brand, double _price, std::string _color)
            : Clock(_brand, _price, _color), hour(0), minute(0) {}

    void addSound() {
        int count;
        std::cout << "How many sounds your cuckoo clock will have?: " << std::endl;
        std::cin >> count;
        for (int i = 0; i < count; i++) {
            std::string sound;
            std::cout << "Type " << i + 1 << " sound: ";
            std::cin >> sound;
            listOfSounds.push_back(sound);
        }
    }

    std::string chooseSound() {
        addSound();
        std::cout << "What sound do you like the most?: " << std::endl;
        for (int i = 0; i < listOfSounds.size(); i++) {
            std::cout << i + 1 << '.' << listOfSounds[i] << std::endl;
        }
        int decision;
        std::cin >> decision;
        return listOfSounds[decision - 1];
    }

    void alarm() override {
        std::string sound = chooseSound();
        std::cout << sound << std::endl;
    }

    void setTime(int h, int m) {
        if (h >= 0 && h < 24 && m >= 0 && m < 60) {
            hour = h;
            minute = m;
        } else {
            std::cout << "Invalid time." << std::endl;
        }
    }

    void displayTime() {
        std::cout << "Current time: " << (hour < 10 ? "0" : "") << hour << ":"
                  << (minute < 10 ? "0" : "") << minute << std::endl;
    }

    void cuckooSound() {
        std::string sound = "Cuckoo! ";
        for (int i = 0; i < hour; ++i) {
            std::cout << sound;
            sleep(1); // Simulate delay between sounds
        }
        std::cout << std::endl;
    }

    void tickTock() {
        while (true) {
            sleep(60); // Simulate a minute passing
            minute++;
            if (minute == 60) {
                minute = 0;
                hour++;
                if (hour == 24) {
                    hour = 0;
                }
                cuckooSound(); // Sound the cuckoo every hour
            }
            displayTime();
        }
    }

    const std::string getBrand() const {
        return brand;
    }

    const double getPrice() const {
        return price;
    }

    const std::string getColor() const {
        return color;
    }
    const int getHour() const{
        return hour;
    }
    const int getMinute() const{
        return minute;
    }
};
