#include <fmt/core.h>
#include <string>

int main() {
    std::string name = "Karan";
    fmt::print("Hello, {}! Your C++ toolchain is working.\n", name);
    return 0;
}