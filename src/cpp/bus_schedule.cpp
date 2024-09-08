#include "bus_schedule.h"

BusSchedule::BusSchedule()
    : destination_(""), bus_number_(""), departure_time_("") {}

BusSchedule::BusSchedule(const std::string& destination,
                         const std::string& bus_number,
                         const std::string& departure_time)
    : destination_(destination),
      bus_number_(bus_number),
      departure_time_(departure_time) {}

void BusSchedule::InputDestination(std::string& field) const {
    std::string input;
    while (true) {
        std::cout << "Enter Destination (no numbers allowed): ";
        std::getline(std::cin, input);

        bool valid = true;
        for (char c : input) {
            if (std::isdigit(c)) {
                std::cout << "Error: Destination cannot contain numbers!\n";
                valid = false;
                break;
            }
        }

        if (!input.empty() && valid) {
            field = input;
            break;
        } else {
            std::cout << "Error: Destination cannot be empty!\n";
        }
    }
}

void BusSchedule::InputBusNumber(std::string& field) const {
    std::string input;
    while (true) {
        std::cout << "Enter Bus Number (must start with a digit, can be alphanumeric): ";
        std::getline(std::cin, input);

        if (input.empty() || !std::isdigit(input[0])) {
            std::cout << "Error: Bus Number must start with a digit and cannot be empty!\n";
            continue;
        }

        bool has_digit = false;
        for (char c : input) {
            if (std::isdigit(c)) {
                has_digit = true;
                break;
            }
        }

        if (has_digit) {
            field = input;
            break;
        } else {
            std::cout << "Error: Bus Number must contain at least one digit!\n";
        }
    }
}

void BusSchedule::InputDepartureTime(std::string& field) const {
    std::string input;
    while (true) {
        std::cout << "Enter Departure Time (HH:MM, 24-hour format): ";
        std::getline(std::cin, input);

        if (input.size() == 5 && input[2] == ':') {
            int hours = std::stoi(input.substr(0, 2));
            int minutes = std::stoi(input.substr(3, 2));

            if (hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60) {
                field = input;
                break;
            }
        }
        std::cout << "Error: Invalid time format!\n";
    }
}

void BusSchedule::AddSchedule() {
    InputDestination(destination_);
    InputBusNumber(bus_number_);
    InputDepartureTime(departure_time_);
    std::cout << "New schedule added successfully!\n";
}

void BusSchedule::UpdateSchedule() {
    InputDestination(destination_);
    InputBusNumber(bus_number_);
    InputDepartureTime(departure_time_);
    std::cout << "Schedule updated successfully!\n";
}

void BusSchedule::DeleteSchedule() {
    destination_.clear();
    bus_number_.clear();
    departure_time_.clear();
    std::cout << "Schedule deleted successfully!\n";
}

void BusSchedule::Display() const {
    if (!destination_.empty() && !bus_number_.empty() && !departure_time_.empty()) {
        std::cout << "Destination: " << destination_
                  << ", Bus Number: " << bus_number_
                  << ", Departure Time: " << departure_time_ << std::endl;
    } else {
        std::cout << "No schedule available.\n";
    }
}

std::istream& operator>>(std::istream& in, BusSchedule& bus) {
    bus.AddSchedule();
    return in;
}
