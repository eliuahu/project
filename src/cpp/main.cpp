#include "bus_schedule_manager.h"
#include <iostream>
#include <limits> 


int main() {
  BusScheduleManager manager;
  int choice;

  while (true) {
    std::cout << "\n\n\n";
    std::cout << "Bus Schedule Management System\n";
    std::cout << "1. Add new schedule\n";
    std::cout << "2. View schedules\n";
    std::cout << "3. Update schedule\n";
    std::cout << "4. Delete schedule\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

    switch (choice) {
      case 1:
        manager.AddSchedule();
        break;
      case 2:
        manager.DisplaySchedules();
        break;
      case 3:
        manager.UpdateSchedule();
        break;
      case 4:
        manager.DeleteSchedule();
        break;
      case 5:
        std::cout << "Exiting...\n";
        return 0;
      default:
        std::cout << "Invalid choice! Please try again.\n";
    }
  }
}
