#pragma once
#include "velaris/aircraft.hpp"
#include <vector>


namespace velaris
{

    class Simulation
    {
        public:
            Simulation(double dt, double duration);

            const std::vector<State>& get_history() const { return history_; }
            
            void run(Aircraft& aircraft);
            void save_to_csv(const std::string& filename);
        
        private:
            double dt_;
            double duration_;
            double total_steps_;
            double current_time_{0.0};

            std::vector<State> history_;
    };
}