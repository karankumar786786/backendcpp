#include "greet.h"
#include <string>

using std::string;
using nlohmann::json;

string greet(string name) {
    return "Hello, " + name + "!";
}

json greetJson(string name) {
    json response;
    response["message"] = "Hello, " + name + "!";
    response["name"] = name;
    response["status"] = "success";
    return response;
}