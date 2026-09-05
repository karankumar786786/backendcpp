#pragma once
#include <string>
#include <nlohmann/json.hpp>
using namespace std;
using namespace nlohmann;

string greet(std::string name);
json greetJson(std::string name);