#include<bits/stdc++.h>
using namespace std;
enum VehicleType{
    MOTORCYCLE, CAR, BUS,NONE
};

// class Motorcycle;
// class Car;
// class Bus;

class Vehicle{
    protected:
        int vehicle_number;
        VehicleType type;
        int no_of_wheels;
    public:
        int getVehicleNumber(){
            return  vehicle_number;
        }
        VehicleType getVehicleType(){
            return  type;
        }
        int getWheels(){
            return no_of_wheels;
        }
        static Vehicle* createVehicle( VehicleType type, int vehicle_number);
};

class Motorcycle: public Vehicle{
    public:
    Motorcycle(int vehicle_number){
        type = MOTORCYCLE;
        this->vehicle_number = vehicle_number;
        no_of_wheels = 2;
    }
};

class Car: public Vehicle{
    public:
    Car(int vehicle_number){
        type = CAR;
        this->vehicle_number = vehicle_number;
        no_of_wheels = 4;
    }
};

class Bus: public Vehicle{
    public:
    Bus(int vehicle_number){
        type = BUS;
        this->vehicle_number = vehicle_number;
        no_of_wheels = 8;
    }
};

Vehicle* Vehicle::createVehicle( VehicleType type, int vehicle_number){
            if(type == MOTORCYCLE)
                return new Motorcycle(vehicle_number);
            else if(type == CAR)
                return new Car(vehicle_number);
            else if(type == BUS)
                return new Bus(vehicle_number);
}
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
        ParkingLot(int number_of_small,int number_of_compact,int number_of_large){
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

int main(){
    ParkingLot *parkinglot = new ParkingLot(10,10,10);
    int vehicle_number;
    int ch;
    while(1)
    {
        cout<<"\n\nwelcome to Johans Parking Garage\n";
        cout<<"what would you like to do"<<"\n";
        cout<<"1.park"<<"\n";
        cout<<"2.take vehicle"<<"\n";
        cout<<"3.exit"<<"\n";
        cin>>ch;
        Vehicle *v;
        int s;
        VehicleType type;
        switch(ch)
        {
            case 1: cout<<"enter type of vehicle(1.motorcycle,2.car,3.bus):";
                    cin>>s;
                    switch(s)
                    {
                        case 1: type = MOTORCYCLE;
                                break;
                        case 2: type=  CAR;
                                break;
                        case 3: type = BUS;
                                break;
                    }    
                    cout<<"enter vehicle number:";
                    cin>>vehicle_number;
                    v = Vehicle::createVehicle(type,vehicle_number);
                    parkinglot->parkVehicle(v);
                    break;
            
            case 2: cout<<"enter vehicle number:";
                    cin>>vehicle_number;
                    parkinglot->takeVehicle(vehicle_number);
                    break;

            case 3: exit(0);
       }
    }      
    return 0;
}