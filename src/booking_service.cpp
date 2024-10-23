#include "booking_service.hpp"

void BookingService::addMovie(const Movie& movie) {
    movies.push_back(movie);
}

void BookingService::addTheater(const Theater& theater) {
    theaters.push_back(theater);
}

std::vector<Movie> BookingService::getMovies() const {
    return movies;
}

std::vector<Theater> BookingService::getTheatersForMovie(const std::string& movieTitle) const {
    return theaters;  // This is a simplified assumption for now
}

std::vector<Seat> BookingService::getAvailableSeats(const std::string& movieTitle, const std::string& theaterName) const {
    for (const Theater& theater : theaters) {
        if (theater.getName() == theaterName) {
            return theater.getAvailableSeats();
        }
    }
    return {};
}

bool BookingService::bookSeats(const std::string& movieTitle, const std::string& theaterName, const std::vector<int>& seatNumbers) {
    for (Theater& theater : theaters) {
        if (theater.getName() == theaterName) {
            return theater.bookSeats(seatNumbers);
        }
    }
    return false;
}
