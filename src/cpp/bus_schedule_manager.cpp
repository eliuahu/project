#include "bus_schedule_manager.h"
#include <iostream>
#include <cstring>

// Constructor
BusScheduleManager::BusScheduleManager()
    : size_(0), capacity_(10) {
    schedules_ = new BusSchedule*[capacity_];
    for (int i = 0; i < capacity_; ++i) {
        schedules_[i] = nullptr;
    }
}

// Destructor
BusScheduleManager::~BusScheduleManager() {
    Clear();
}

// Copy constructor
BusScheduleManager::BusScheduleManager(const BusScheduleManager& other) {
    CopyFrom(other);
}

// Assignment operator
BusScheduleManager& BusScheduleManager::operator=(const BusScheduleManager& other) {
    if (this != &other) {
        Clear();
        CopyFrom(other);
    }
    return *this;
}

// Resize the array of schedules
void BusScheduleManager::Resize() {
    capacity_ *= 2;

    BusSchedule** new_schedules = new BusSchedule*[capacity_];

    for (int i = 0; i < size_; ++i) {
        new_schedules[i] = schedules_[i];
    }

    for (int i = size_; i < capacity_; ++i) {
        new_schedules[i] = nullptr;
    }

    delete[] schedules_;

    schedules_ = new_schedules;
}


// Copy resources from another BusScheduleManager
void BusScheduleManager::CopyFrom(const BusScheduleManager& other) {
    size_ = other.size_;
    capacity_ = other.capacity_;
    schedules_ = new BusSchedule*[capacity_];
    for (int i = 0; i < size_; ++i) {
        schedules_[i] = new BusSchedule(*other.schedules_[i]);
    }
    for (int i = size_; i < capacity_; ++i) {
        schedules_[i] = nullptr;
    }
}

// Clear the resources
void BusScheduleManager::Clear() {
    for (int i = 0; i < size_; ++i) {
        delete schedules_[i];
    }
    delete[] schedules_;
}

void BusScheduleManager::AddSchedule() {
    if (size_ == capacity_) {
        Resize();
    }

    schedules_[size_] = new BusSchedule();

    schedules_[size_]->AddSchedule();

    ++size_;
}

// Update an existing schedule
void BusScheduleManager::UpdateSchedule(int index) {
    if (index >= 0 && index < size_) {
        schedules_[index]->UpdateSchedule();
    } else {
        std::cout << "Error: Invalid index!\n";
    }
}

// Delete a schedule
void BusScheduleManager::DeleteSchedule(int index) {
    if (index >= 0 && index < size_) {
        delete schedules_[index];
        for (int i = index; i < size_ - 1; ++i) {
            schedules_[i] = schedules_[i + 1];
        }
        schedules_[size_ - 1] = nullptr;
        --size_;
    } else {
        std::cout << "Error: Invalid index!\n";
    }
}

// Display all schedules
void BusScheduleManager::DisplaySchedules() const {
    for (int i = 0; i < size_; ++i) {
        schedules_[i]->Display();
    }
}
