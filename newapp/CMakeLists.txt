cmake_minimum_required(VERSION 3.20)
project(newapp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(Crow CONFIG REQUIRED)

add_executable(newapp src/main.cpp src/controllers/greet.cpp src/utils/dotenv/dotenv.cpp)
target_link_libraries(newapp PRIVATE fmt::fmt)
target_link_libraries(newapp PRIVATE nlohmann_json::nlohmann_json Crow::Crow)