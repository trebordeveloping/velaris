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

        forces_.x = thrust - drag;
        forces_.y = 0;
        forces_.z = lift - weight;
    }
    
    void Aircraft::update(double dt)
    {

        // accelerations
        const double a_x = forces_.x / mass_;
        const double a_y = forces_.y / mass_;
        const double a_z = forces_.z / mass_;

        // integration
        const double du = a_x * dt;
        const double dv = a_y * dt;
        const double dw = a_z * dt;

        const double dx = (state_.u * dt) + (0.5 * a_x * dt*dt);
        const double dy = (state_.v * dt) + (0.5 * a_y * dt*dt);
        const double dz = (state_.w * dt) + (0.5 * a_z * dt*dt);

        state_.x += dx;
        state_.y += dy;
        state_.z += dz;
        state_.u += du;
        state_.v += dv;
        state_.w += dw;

        // hardcode 3DOF
        state_.y = 0;
        state_.v = 0;

    }

    void Aircraft::print_status() const
    {
        std::cout << "Pos: (" << state_.x << ", " << state_.y << ", " << state_.z << ")" << std::endl;
    }
}