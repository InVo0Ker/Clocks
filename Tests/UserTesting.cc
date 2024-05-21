#include <iostream>
#include <cassert>
#include <unistd.h>
#include "../Classes/Clock.cc"
#include "../Classes/User.cc"

bool testName(){
    User john("John","Cramel");
    std::string Name = john.getName();
    assert(Name == "John");
    return true;
}
bool testSurname(){
    User john("John","Cramel");
    std::string Surname = john.getSurname();
    assert(Surname == "Cramel");
    return true;
}
bool testExceptionQuestion(){
    // imagine that it will be false
    try{
        User john("John","Cramel");
        john.questionImportant();
    } catch(std::logic_error& err){
        assert(std::string(err.what()) == std::string("Write a type please correctly...."));
    }
    return true;
}


int main(){
    std::cout<<testName()<<std::endl;
    std::cout<<testSurname()<<std::endl;
    std::cout<<testExceptionQuestion<<std::endl;
}