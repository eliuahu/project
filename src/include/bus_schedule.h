#ifndef BUS_SCHEDULE_H
#define BUS_SCHEDULE_H

#include <string>
#include <iostream>

class BusSchedule {
public:
    BusSchedule();
    BusSchedule(const std::string& destination,
                const std::string& bus_number,
                const std::string& departure_time);
    BusSchedule(const BusSchedule& other) = default;
    BusSchedule& operator=(const BusSchedule& other) = default;
    ~BusSchedule() = default; 

    void InputDestination(std::string& field) const;
    void InputBusNumber(std::string& field) const;
    void InputDepartureTime(std::string& field) const;
    void AddSchedule();
    void UpdateSchedule();
    void DeleteSchedule();
    void Display() const;


private:
    std::string destination_;
    std::string bus_number_;
    std::string departure_time_;

    friend std::istream& operator>>(std::istream& in, BusSchedule& bus);
};

#endif // BUS_SCHEDULE_H
