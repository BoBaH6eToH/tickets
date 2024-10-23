# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(MovieBookingSystem)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable file with the source files
add_executable(movie_booking main.cpp MovieService.cpp Theater.cpp Seat.cpp)

# Include directories for header files
target_include_directories(movie_booking PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Compiler options (optional: enable warnings and treat them as errors)
target_compile_options(movie_booking PRIVATE -Wall -Wextra -Werror)

# (Optional) If using Boost or other third-party libraries, link them
find_package(Boost REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(movie_booking ${Boost_LIBRARIES})
endif()

# (Optional) Add unit tests, if any
enable_testing()
add_subdirectory(tests)
