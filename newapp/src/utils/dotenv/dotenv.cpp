#include "dotenv.h"
#include <cstddef>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;


void loadEnv(const string& path){
    ifstream file(path);
    if (!file.is_open()) return;
    string line;
    while (getline(file,line)) {
        if (line.empty() || line[0] == '#') continue;
        size_t eq = line.find('=');
        if(eq == string::npos) continue;
        string key = line.substr(0,eq);
        string value = line.substr(eq+1);
        setenv(key.c_str(), value.c_str(), 1);
    }
}