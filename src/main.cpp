#include <iostream>
#include "velaris/aircraft.hpp"
#include "velaris/simulation.hpp"

int main(int argc, char* argv[]) {

    std::cout << "Hello, world." << std::endl;


    velaris::Aircraft aircraft(1000.0);
    velaris::Simulation sim(0.01, 10.0);

    // Execute
    sim.run(aircraft);

    // Save
    sim.save_to_csv("out");


    return 0;
}