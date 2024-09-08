#include "bus_schedule_manager.h"
#include <iostream>
#include <limits>


void BusScheduleManager::AddSchedule() {
  BusSchedule new_schedule;
  std::cin >> new_schedule;
  schedules_.push_back(new_schedule);
  std::cout << "New schedule added to the list!\n";
}

void BusScheduleManager::DisplaySchedules() const {
  if (schedules_.empty()) {
    std::cout << "No schedules available.\n";
  } else {
    for (size_t i = 0; i < schedules_.size(); ++i) {
      std::cout << "Schedule " << i + 1 << ":\n";
      schedules_[i].Display();
    }
  }
}

void BusScheduleManager::UpdateSchedule() {
  size_t index;
  std::cout << "Enter the schedule number to update: ";
  std::cin >> index;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

  if (index < 1 || index > schedules_.size()) {
    std::cout << "Invalid schedule number!\n";
  } else {
    schedules_[index - 1].UpdateSchedule();
  }
}

void BusScheduleManager::DeleteSchedule() {
  size_t index;
  std::cout << "Enter the schedule number to delete: ";
  std::cin >> index;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  

  if (index < 1 || index > schedules_.size()) {
    std::cout << "Invalid schedule number!\n";
  } else {
    schedules_.erase(schedules_.begin() + index - 1);
    std::cout << "Schedule deleted successfully!\n";
  }
}
