#ifndef BOOKING_SERVICE_HPP
#define BOOKING_SERVICE_HPP

#include <vector>
#include <string>
#include "movie.hpp"
#include "theater.hpp"

class BookingService {
public:
    void addMovie(const Movie& movie);
    void addTheater(const Theater& theater);
    
    std::vector<Movie> getMovies() const;
    std::vector<Theater> getTheatersForMovie(const std::string& movieTitle) const;
    std::vector<Seat> getAvailableSeats(const std::string& movieTitle, const std::string& theaterName) const;
    bool bookSeats(const std::string& movieTitle, const std::string& theaterName, const std::vector<int>& seatNumbers);

private:
    std::vector<Movie> movies;
    std::vector<Theater> theaters;
};

#endif // BOOKING_SERVICE_HPP
