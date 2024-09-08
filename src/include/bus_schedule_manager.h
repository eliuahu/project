#pragma once

#include "bus_schedule.h"
#include <vector>

class BusScheduleManager {
 private:
  std::vector<BusSchedule> schedules_;

 public:
  BusScheduleManager() = default;
  ~BusScheduleManager() = default;

  void AddSchedule();
  void DisplaySchedules() const;
  void UpdateSchedule();
  void DeleteSchedule();
};
