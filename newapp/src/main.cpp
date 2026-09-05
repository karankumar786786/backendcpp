#include <crow.h>
#include "controllers/greet.h"
#include "utils/dotenv/dotenv.h"
#include <cstdlib>


int main() {
    loadEnv();
    crow::SimpleApp app;

    const char* portEnv = std::getenv("PORT");
    int port = portEnv ? std::atoi(portEnv) : 8080;

    CROW_ROUTE(app, "/")
    ([](){
        return "Hello, World!";
    });

    CROW_ROUTE(app, "/hello/<string>")
    ([](std::string name){
        return greet(name);
    });

    // New JSON route
    CROW_ROUTE(app, "/api/hello/<string>")
    ([](std::string name){
        nlohmann::json result = greetJson(name);
        return crow::response(result.dump());
    });

    app.port(port).multithreaded().run();
}