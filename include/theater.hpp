#ifndef THEATER_HPP
#define THEATER_HPP

#include <string>
#include <vector>
#include "seat.hpp"

class Theater {
public:
    Theater(const std::string& name, int capacity = 20);

    std::string getName() const;
    std::vector<Seat> getAvailableSeats() const;
    bool bookSeats(const std::vector<int>& seatNumbers);

private:
    std::string name;
    std::vector<Seat> seats;
};

#endif // THEATER_HPP
