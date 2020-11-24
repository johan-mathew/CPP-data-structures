#pragma once
#include "Vehicle.h"
enum SlotSize{
    SMALL,COMPACT,LARGE
};

class ParkingSpot{
    private:
        bool occupied;
        Vehicle* vehicle;
        SlotSize slot_type;
    public:
        ParkingSpot(SlotSize slot_type){
            this->slot_type = slot_type;
            vehicle = nullptr;
            occupied = false;
        }
        int getTicketNumber(){
            if(vehicle)
                return vehicle->getVehicleNumber();
            else
                return 0;
        }
        VehicleType getParkedVehicleType(){
            if(vehicle)
                return vehicle->getVehicleType();
        }
        SlotSize getSlotType(){
            return this->slot_type;
        }
        bool isOccupied(){
            return this->occupied;
        }
        void assignParkingLot(Vehicle* vehicle){
            this->vehicle = vehicle;
            occupied = true;
        }
        void freeParkingLot(){
            this->vehicle = nullptr;
            occupied = false;
        }
};