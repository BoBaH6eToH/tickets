#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>
#include <vector>

class Movie {
public:
    Movie(const std::string& title);
    
    std::string getTitle() const;

private:
    std::string title;
};

#endif // MOVIE_HPP
