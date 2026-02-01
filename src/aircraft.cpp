#include "velaris/aircraft.hpp"
#include <iostream>

namespace velaris
{
    Aircraft::Aircraft(double mass)
        : mass_(mass) {}
    
    State Aircraft::get_state() { return state_; }

    void Aircraft::forces()
    {
        // constants
        const double g = 9.80665; // m/s

        // forces
        const double weight = mass_ * g;

        const double lift = mass_ * g;
        const double thrust = 5;
        const double drag = 5;

        forces_ = Eigen::Vector3d(
            thrust - drag,
            0.0,
            lift - weight
        );
    }
    
    void Aircraft::update(double dt)
    {

        // accelerations
        Eigen::Vector3d acc = forces_ / mass_;
        

        // integration
        state_.pos += (state_.vel * dt) + (0.5 * acc * dt*dt);
        state_.vel += (acc * dt);

        // hardcode 3DOF
        state_.pos.y() = 0;
        state_.vel.y() = 0;

    }

    void Aircraft::print_status() const
    {
        std::cout << "Pos: (" << state_.pos.x() << ", " << state_.pos.y() << ", " << state_.pos.z() << ")" << std::endl;
    }
}