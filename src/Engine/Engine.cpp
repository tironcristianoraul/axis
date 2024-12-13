#pragma once

#include "include/CLI11.hpp"
#include "include/nlohmann_json.hpp"

#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <format>

class Engine {

    // -- CONSTRUCTOR & DESTRUCTOR -- //
    Engine() = default;
   ~Engine() = default;

public:

    // -- METHODS -- //
    static void RegisterSubcommands(CLI::App &app) {

        // Create Command
        auto cmd = app.add_subcommand("create", "Create a new C++ project using Axis! ✨");
        cmd->add_option_function<std::string>("name", [](std::string name) -> void
        { 
            nlohmann::json Axisfile;

            auto start = std::chrono::high_resolution_clock::now();

            int mkdir = std::system(std::format("mkdir -p {}", name).c_str());
            if(mkdir) {
                std::cerr << "Create command failed with status " << mkdir;
                std::exit(1);
            }

            std::system(std::format("cd {}", name).c_str());

            Axisfile["name"] = name;
            Axisfile["version"] = "1.0.0";

            std::ofstream file(std::format("./{}/Axisfile", name).c_str());

            file << Axisfile.dump(4);

            auto end = std::chrono::high_resolution_clock::now();

            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

            std::cout << "Project created successfully! ✨\nDone in " << duration << "ms";


        }, "The name of your new awesome project");
    }

};