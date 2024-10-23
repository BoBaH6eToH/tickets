#include "theater.hpp"

Theater::Theater(const std::string& name, int capacity) : name(name), seats(capacity) {
    for (int i = 0; i < capacity; ++i) {
        seats[i] = Seat(i + 1);
    }
}

std::string Theater::getName() const {
    return name;
}

std::vector<Seat> Theater::getAvailableSeats() const {
    std::vector<Seat> availableSeats;
    for (const Seat& seat : seats) {
        if (!seat.isBooked()) {
            availableSeats.push_back(seat);
        }
    }
    return availableSeats;
}

bool Theater::bookSeats(const std::vector<int>& seatNumbers) {
    for (int num : seatNumbers) {
        if (num > seats.size() || seats[num - 1].isBooked()) {
            return false;  // Overbooking or invalid seat number
        }
    }

    for (int num : seatNumbers) {
        seats[num - 1].book();
    }
    return true;
}
