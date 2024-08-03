#include <iostream>
#include <string.h>
#include <list>


class Car {
    protected:
        std::string model;
        int year;
    public:
        virtual void displayInfo() const = 0;
        virtual void inputInfo() = 0;
    
};

class Sedan : public Car {
    public:
        void displayInfo() const override;
        void inputInfo() override;
};

class SUV : public Car {
    public:
        void displayInfo() const override;
        void inputInfo() override;
};

void Sedan::inputInfo() {
    std::cout << "Sedan model:";
    std::cin >> Sedan::model;
    std::cout << "Sedan year:";
    std::cin >> Sedan::year;
}

void Sedan::displayInfo() const {
    std::cout << "Sedan model:" <<  Sedan::model << std::endl;
    std::cout << "Sedan year:" << Sedan::year << std::endl;
}

void SUV::inputInfo() {
    std::cout << "SUV model:";
    std::cin >> SUV::model;
    std::cout << "SUV year:";
    std::cin >> SUV::year;
}

void SUV::displayInfo() const {
    std::cout << "SUV model:" << SUV::model << std::endl;
    std::cout << "SUV year:" << SUV::year << std::endl;
}

int main() {
    std::list<Car*> car;

    Sedan* xe1 = new(Sedan);
    SUV* xe2 = new(SUV);

    car.push_back(xe1);
    car.push_back(xe2);

    for(auto value : car) {
        value->inputInfo();
    }
    for (auto value : car) {
        value->displayInfo();
    }

    delete(xe1);
    delete(xe2);

    return 0;
}