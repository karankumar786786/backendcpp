#include <crow.h>
#include "controllers/greet.h"
#include "utils/dotenv/dotenv.h"
#include <cstdlib>

using namespace std;

int main() {
    loadEnv();
    crow::SimpleApp app;

    const char* portEnv = getenv("PORT");
    int port = portEnv ? atoi(portEnv) : 8060; // fallback to 8080 if not set

    CROW_ROUTE(app, "/")
    ([](){
        return "Hello, World!";
    });

    CROW_ROUTE(app, "/hello/<string>")
    ([](string name){
        return greet(name);
    });

    app.port(port).multithreaded().run();
}