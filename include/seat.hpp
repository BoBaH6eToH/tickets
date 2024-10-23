#ifndef SEAT_HPP
#define SEAT_HPP

class Seat {
public:
    Seat(int number);
    
    int getNumber() const;
    bool isBooked() const;
    void book();

private:
    int number;
    bool booked;
};

#endif // SEAT_HPP
