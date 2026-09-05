#pragma once
#include <crow.h>
#include "../models/user.h"

class UserController {
public:
    static crow::response createUser(const crow::request& req) {
        try {
            auto body = nlohmann::json::parse(req.body);
            User user = User::fromJson(body);

            // Example logic — just echoing it back with a greeting
            nlohmann::json response;
            response["message"] = "User created: " + user.name;
            response["user"] = user.toJson();

            crow::response res(response.dump());
            res.set_header("Content-Type", "application/json");
            return res;

        } catch (const std::exception& e) {
            nlohmann::json error;
            error["error"] = e.what();
            crow::response res(400, error.dump());
            res.set_header("Content-Type", "application/json");
            return res;
        }
    }
};