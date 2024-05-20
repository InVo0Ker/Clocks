#include <iostream>
#include <vector>

class Clock{
    protected:
    std::string brand;
    double price;
    public:
    Clock(std::string _brand, double _price): brand(_brand), price(_price){}
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
class Watch : public Clock{
    std::string nameOfSound;
    public:
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
        throw std::logic_error("What do you mean hang, I can't do it");
    }
};
class QuartzClock : public Clock{
    std::vector<std::string> listOfSounds;
    public:
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
        std::cout<<"What sound you like the most?: ";
        for(int i = 0; i<listOfSounds.size(); i++){
            std::cout<<i+1<<'.'<<listOfSounds[i];
        }
        int decision;
        std::cin>>decision;
        return listOfSounds[decision-1]; 
    }
    void alarm() override{
        chooseSound();
    }
};
class User{
    std::string name;
    std::string surname;
    Clock *p;
    public:
    User(std::string _name, std::string _surname, double _budget, Clock *t): name(_name), surname(_surname){}
    void questionImportant(){
        std::string choice;
        std::cout<<"What type of clocks you want to use: ";
        std::cin>>choice;
        for(auto &x : choice){
            tolower(x);
        }
        if(choice == "quartz"){
            QuartzClock *f;
            p = f;
        } else if(choice == "watch"){
            Watch *f;
            p = f;
        } else{
            throw std::logic_error("Write a type please correctly...");
        }
    };
    void setAlarm(){
        p->alarm();
    }

};

int main(){
    
}
