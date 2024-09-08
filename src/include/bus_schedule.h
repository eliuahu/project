#pragma once

#include <iostream>
#include <string>

class BusSchedule {
 private:
  std::string destination_;
  std::string bus_number_;
  std::string departure_time_;

  void InputDestination(std::string& field);
  void InputBusNumber(std::string& field);
  void InputDepartureTime(std::string& field);

 public:
  BusSchedule();
  BusSchedule(const std::string& destination, const std::string& bus_number,
              const std::string& departure_time);
  BusSchedule(const BusSchedule& other);
  ~BusSchedule();

  void AddSchedule();
  void UpdateSchedule();
  void DeleteSchedule();
  void Display() const;

  friend std::istream& operator>>(std::istream& in, BusSchedule& bus);
};
