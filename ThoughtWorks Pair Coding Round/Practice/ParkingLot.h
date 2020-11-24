#include <bits/stdc++.h>
#pragma once
#include "ParkingSpot.h"
#include "Vehicle.h"
using namespace std;
class ParkingLot{
    private:
        int number_of_small;
        int number_of_compact;
        int number_of_large;
        int no_of_vehicles;
        int total_slots;
        vector<ParkingSpot*> parking_spots;
        unordered_map <VehicleType, vector<SlotSize>> vehicle_slots = {
            { MOTORCYCLE , { SMALL, COMPACT, LARGE } },
            { CAR , { COMPACT, LARGE} },
            { BUS , { LARGE} }
        };
    public:
        ParkingLot(string name, int number_of_small,int number_of_compact,int number_of_large){
            this->number_of_small = number_of_small;
            this->number_of_compact = number_of_compact;
            this->number_of_large = number_of_large;
            for(int i = 0; i < number_of_small; i++){
                ParkingSpot *spot = new ParkingSpot(SMALL);
                parking_spots.push_back(spot);
            }
            for(int i = 0; i < number_of_compact; i++){
                ParkingSpot *spot = new ParkingSpot(COMPACT);
                parking_spots.push_back(spot);
            }
            for(int i = 0; i < number_of_compact; i++){
                ParkingSpot *spot = new ParkingSpot(LARGE);
                parking_spots.push_back(spot);
            }
        }
        void parkVehicle( Vehicle* vehicle){
            for(int i =  0; i < parking_spots.size(); i++){
                    for( auto slot:vehicle_slots[vehicle->getVehicleType()])
                        {
                            if( slot == parking_spots[i]->getSlotType() ){
                                parking_spots[i]->assignParkingLot(vehicle);
                                cout<<"Vehicle Parked at: "<<i<<endl;
                                return;
                            }    
                        }
            }
            cout<<"Vehicle Not Parked"<<endl;
            return;
        }
        void takeVehicle( int vehicle_number){
            for(int i =  0; i < parking_spots.size(); i++){
                if( vehicle_number == parking_spots[i]->getTicketNumber() ){
                    parking_spots[i]->freeParkingLot();
                    cout<<"Vehicle Take from: "<<i<<endl;
                    return;
                }    
            }
            cout<<"Vehicle Not Parked"<<endl;
            return;
        }
};