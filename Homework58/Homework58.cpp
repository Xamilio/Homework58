#include <iostream>
#include <string>
using namespace std;

class Transport
{
protected:
    string Type;
public:
    Transport(const string& type)
    {
        Type = type;
    }
    virtual ~Transport() 
    {

    }
    virtual void display() const 
    {
        cout << "Тип транспорта: " << Type << endl;
    }
    virtual void fuelConsumption() const = 0;
};
class Airplane : public Transport {
public:
    Airplane() : Transport("Самолёт") 
    {

    }
    virtual void fuelConsumption() const override {
        cout << "Расход топлива самолёта: 2000 л/ч" << endl;
    }
};

class Ship : public Transport {
public:
    Ship() : Transport("Судно") 
    {

    }
    virtual void fuelConsumption() const override {
       cout << "Расход топлива судна: 500 л/ч" << endl;
    }
};

class Truck : public Transport {
public:
    Truck() : Transport("Грузовик") 
    {
    
    }
    virtual void fuelConsumption() const override {
        cout << "Расход топлива грузовика: 30 л/100 км" << endl;
    }
};

class Bicycle : public Transport {
public:
    Bicycle() : Transport("Велосипед") 
    {

    }
    virtual void fuelConsumption() const override {
        cout << "Велосипед не потребляет топливо" << endl;
    }
};

class Car : public Transport {
public:
    Car() : Transport("Легковой автомобиль") 
    {

    }
    virtual void fuelConsumption() const override {
        cout << "Расход топлива легкового автомобиля: 8 л/100 км" << endl;
    }
};
int main() {
    Transport* vehicle = nullptr;
    int choice;
    while (true) {
        cout << "Выберите тип транспортного средства:" << endl;
        cout << "1. Самолёт" << endl;
        cout << "2. Судно" << endl;
        cout << "3. Грузовик" << endl;
        cout << "4. Велосипед" << endl;
        cout << "5. Легковой автомобиль" << endl;
        cout << "0. Выход" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            vehicle = new Airplane();
            break;
        case 2:
            vehicle = new Ship();
            break;
        case 3:
            vehicle = new Truck();
            break;
        case 4:
            vehicle = new Bicycle();
            break;
        case 5:
            vehicle = new Car();
            break;
        case 0:
            cout << "Выход из программы" << endl;
            return 0;
        default:
            cout << "Некорректный ввод. Попробуйте ещё раз" << endl;
            continue;
        }
        vehicle->display();
        vehicle->fuelConsumption();
    }
}

