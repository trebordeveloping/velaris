#include "velaris/aircraft.hpp"
#include <iostream>

namespace velaris
{
    Aircraft::Aircraft(double mass)
        : mass_(mass) {}
    
    State Aircraft::get_state() { return state_; }
    
    void Aircraft::update_state(const State& new_state)
    {
        state_ = new_state;
    }

    void Aircraft::print_status() const
    {
        std::cout << "Pos: (" << state_.x << ", " << state_.y << ", " << state_.z << ")" << std::endl;
    }
}