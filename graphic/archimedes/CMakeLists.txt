cmake_minimum_required(VERSION 3.0)
project(SFMLarchimedes)
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
add_executable(archimedes archimedes.cpp)
target_link_libraries(archimedes sfml-graphics)
