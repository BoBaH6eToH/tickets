#include "movie.hpp"

Movie::Movie(const std::string& title) : title(title) {}

std::string Movie::getTitle() const {
    return title;
}
