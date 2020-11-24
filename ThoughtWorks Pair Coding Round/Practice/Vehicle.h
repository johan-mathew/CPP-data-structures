enum VehicleType{
    MOTORCYCLE, CAR, BUS,NONE
};
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
        static Vehicle* createVehicle( VehicleType type, int vehicle_number){
            if(type == MOTORCYCLE)
                return new Motorcycle(vehicle_number);
            else if(type == CAR)
                return new Car(vehicle_number);
            else if(type == BUS)
                return new Bus(vehicle_number);
        }
};

class Motorcycle: public Vehicle{
    public:
    Motorcycle(int vehicle_number){
        this->type = MOTORCYCLE;
        this->vehicle_number = vehicle_number;
        no_of_wheels = 2;
    }
};

class Car: public Vehicle{
    public:
    Car(int vehicle_number){
        this->type = CAR;
        this->vehicle_number = vehicle_number;
        no_of_wheels = 4;
    }
};

class Bus: public Vehicle{
    public:
    Bus(int vehicle_number){
        this->type = BUS;
        this->vehicle_number = vehicle_number;
        no_of_wheels = 8;
    }
};

