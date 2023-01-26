#include <iostream>
#include <cstring>
#include <string>
#include "car.hpp"

Car::Car() : Car(nullptr, nullptr, PerformanceStats(0,0,0), 0, None){}
Car::~Car(){ delete[] manufacturer; delete[] model; }

Car :: Car(const char *const manufacturerName, const char *const modelName, PerformanceStats perf, uint8_t numSeats,
           DoorKind backseatDoorDesign) {

    if(manufacturerName){
        manufacturer = new char[strlen(manufacturerName) + 1];
        strcpy(manufacturer, manufacturerName);
    }
    else manufacturer = nullptr;

    if (modelName){
        model = new char[strlen(modelName) + 1];
        strcpy(model, modelName);
    }
    else model = nullptr;

    horsepower = perf.horsepower;
    zeroToSixtyNs = perf.zeroToSixtyNs;
    headonDragCoeff = perf.headonDragCoeff;
    seatCount = numSeats;
    backseatDoors = backseatDoorDesign;
}

// Copy Constructor
Car :: Car(Car const& o) : Car(o.getManufacturer(), o.getModel(), o.getStats(), o.getSeatCount(), o.getBackseatDoors()){}

// Overloaded 'Equals'
Car& Car :: operator=(Car const& o){
    if(this == &o) return *this;

    this->manufacturerChange(o.getManufacturer());
    this->modelNameChange(o.getModel());
    this->reevaluateStats(o.getStats());
    this->recountSeats(o.getSeatCount());
    this->reexamineDoors(o.getBackseatDoors());

    return *this;
}

// **** Get/Set Methods **** //
char const* Car::getManufacturer() const {
    return manufacturer;
}
void Car::manufacturerChange(const char *const newManufacturer) {
    delete[] manufacturer;
    if(newManufacturer){
        manufacturer = new char[strlen(newManufacturer) + 1];
        strcpy(manufacturer, newManufacturer);
    }else manufacturer = nullptr;
}


char const* Car::getModel() const {return model;}
void Car::modelNameChange(const char *const newModelName) {
    delete[] model;
    if(newModelName){
        model = new char[strlen(newModelName) + 1];
        strcpy(model, newModelName);
    } else model = nullptr;
}


DoorKind Car::getBackseatDoors() const {return backseatDoors;}
void Car::reexamineDoors(DoorKind newDoorKind) {backseatDoors = newDoorKind;}


uint8_t Car::getSeatCount() const{return seatCount;}
void Car::recountSeats(uint8_t newSeatCount) {seatCount = newSeatCount;}


PerformanceStats Car::getStats() const{return {Car::horsepower, Car::zeroToSixtyNs, Car::headonDragCoeff};}
void Car::reevaluateStats(PerformanceStats newStats){
    horsepower = newStats.horsepower;
    zeroToSixtyNs = newStats.zeroToSixtyNs;
    headonDragCoeff = newStats.headonDragCoeff;
}