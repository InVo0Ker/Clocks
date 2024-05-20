#include <iostream>
#include <vector>
#include <unistd.h>
#include "./Classes/Clock.cc"
#include "./Classes/User.cc"
#include "./Classes/QuartzClock.cc"
#include "./Classes/SandClock.cc"
#include "./Classes/Watch.cc"


int main(){
    User john("John","Cramel");
    john.questionImportant();
    john.setAlarm();
}
