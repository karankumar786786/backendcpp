#pragma once
#include <string>
#include <nlohmann/json.hpp>

class User {
public:
    std::string name;
    int age;

    // Convert this object -> JSON (for responses)
    nlohmann::json toJson() const {
        nlohmann::json j;
        j["name"] = name;
        j["age"] = age;
        return j;
    }

    // Convert incoming JSON -> this object (for request bodies)
    static User fromJson(const nlohmann::json& j) {
        User u;
        u.name = j.at("name").get<std::string>();
        u.age = j.at("age").get<int>();
        return u;
    }
};