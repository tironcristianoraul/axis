#include "include/CLI11.hpp"
#include "src/Engine/Engine.cpp"

int main(int argc, char *argv[]) {

    CLI::App axis {"Axis - C++ Package Manager"};

    axis.set_version_flag("-v,--version", "v0.0.1alpha");

    Engine::RegisterSubcommands(axis);

    CLI11_PARSE(axis, argc, argv);

    return 0;
}
