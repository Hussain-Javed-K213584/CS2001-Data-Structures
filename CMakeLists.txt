cmake_minimum_required(VERSION 3.10) # Set min cmake version

#Project name
project(speller)

# Set cxx standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Add the subdirectories of the library

add_subdirectory(HashMap_lib)
add_subdirectory(Dictionary_lib)

# Add executable

add_executable(speller speller.cpp)

# Link libraries to  the executable

target_link_libraries(speller PUBLIC dictionary)
target_link_libraries(speller PUBLIC hashmap)

# link directories

target_link_directories(speller PUBLIC
"${PROJECT_BINARY_DIR}"
"${PROJECT_SOURCE_DIR}/Dictionary_lib"
"${PROJECT_SOURCE_DIR}/HashMap_lib"
)

