#include "velaris/simulation.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <filesystem>

namespace velaris
{
    Simulation::Simulation(double dt, double duration)
        : dt_(dt), duration_(duration) {
            
            total_steps_ = static_cast<int>(duration_ / dt_ + 1e-9);
            history_.reserve(total_steps_ + 1);
        }
    
    void Simulation::run(Aircraft& aircraft)
    {

        // Clear history
        history_.clear();
        // Store starting state
        history_.push_back(aircraft.get_state());

        std::cout << "Simulation dt = " << dt_ << "s, duration = " << duration_ << std::endl;
        std::cout << "--- SIMULATION STARTED ---" << std::endl;


        for (int i = 1; i <= total_steps_; ++i) {

            // Calculate the forces
            aircraft.forces();

            // Update state
            aircraft.update(dt_);


            // Update time
            current_time_ = i * dt_;

            // Update history
            history_.push_back(aircraft.get_state());
        }

        std::cout << "--- SIMULATION FINISHED ---" << std::endl;
        std::cout << "Captured " << history_.size() << " data points." << std::endl;

    }

    void Simulation::save_to_csv(const std::string& name)
    {
        namespace fs = std::filesystem;

        fs::path base_path = fs::current_path().parent_path();
        fs::path folder = base_path / "out";
        if (!fs::exists(folder)) {
            fs::create_directories(folder);
        }

        std::string filename = name;
        if (filename.size() < 4 || filename.substr(filename.size() - 4) != ".csv") {
            filename += ".csv";
        }

        fs::path target_path = fs::path(folder) / filename;

        std::ofstream file(target_path);

        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return;
        }

        // Header
        file << "time,x,y,z,phi,theta,psi,u,v,w,p,q,r\n";

        // Set precision
        file << std::fixed << std::setprecision(6);

        // Loop through history
        for (size_t i = 0; i < history_.size(); ++i) {
            const auto& s = history_[i];
            file    << i * dt_ << ","
                    << s.pos.x() << "," << s.pos.y() << "," << s.pos.z() << ","
                    << s.att.x() << "," << s.att.y() << "," << s.att.z() << ","
                    << s.vel.x() << "," << s.vel.y() << "," << s.vel.z() << ","
                    << s.rot.x() << "," << s.rot.y() << "," << s.rot.z() << "\n";
        }

        file.close();
    }
}
