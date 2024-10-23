#include <iostream>
#include <vector>
#include <string>
#include "booking_service.hpp"
#include "movie.hpp"
#include "theater.hpp"

void showMenu() {
    std::cout << "1. View all playing movies\n";
    std::cout << "2. Select a movie\n";
    std::cout << "3. View theaters for selected movie\n";
    std::cout << "4. View available seats\n";
    std::cout << "5. Book seats\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    BookingService bookingService;
    
    // Prepopulate data for the sake of simplicity
    Movie movie1("Inception");
    Movie movie2("Interstellar");
    bookingService.addMovie(movie1);
    bookingService.addMovie(movie2);

    Theater theater1("Theater 1");
    Theater theater2("Theater 2");
    bookingService.addTheater(theater1);
    bookingService.addTheater(theater2);

    int choice;
    std::string selectedMovie;
    std::string selectedTheater;
    
    while (true) {
        showMenu();
        std::cin >> choice;
        
        if (choice == 1) {
            std::cout << "Available movies:\n";
            for (const Movie& movie : bookingService.getMovies()) {
                std::cout << "- " << movie.getTitle() << "\n";
            }
        }
        else if (choice == 2) {
            std::cout << "Enter movie title: ";
            std::cin.ignore(); // Clear the input buffer
            std::getline(std::cin, selectedMovie);
            std::cout << "Selected movie: " << selectedMovie << "\n";
        }
        else if (choice == 3) {
            std::cout << "Available theaters for " << selectedMovie << ":\n";
            for (const Theater& theater : bookingService.getTheatersForMovie(selectedMovie)) {
                std::cout << "- " << theater.getName() << "\n";
            }
        }
        else if (choice == 4) {
            std::cout << "Enter theater name: ";
            std::cin.ignore();
            std::getline(std::cin, selectedTheater);
            std::vector<Seat> availableSeats = bookingService.getAvailableSeats(selectedMovie, selectedTheater);
            std::cout << "Available seats in " << selectedTheater << ":\n";
            for (const Seat& seat : availableSeats) {
                std::cout << seat.getNumber() << " ";
            }
            std::cout << "\n";
        }
        else if (choice == 5) {
            std::cout << "Enter seat numbers to book (comma-separated): ";
            std::string seatInput;
            std::cin.ignore();
            std::getline(std::cin, seatInput);
            
            std::vector<int> seatNumbers;
            std::stringstream ss(seatInput);
            std::string seatNum;
            while (std::getline(ss, seatNum, ',')) {
                seatNumbers.push_back(std::stoi(seatNum));
            }
            
            if (bookingService.bookSeats(selectedMovie, selectedTheater, seatNumbers)) {
                std::cout << "Seats booked successfully!\n";
            } else {
                std::cout << "Failed to book seats. Please try again.\n";
            }
        }
        else if (choice == 6) {
            std::cout << "Exiting...\n";
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
