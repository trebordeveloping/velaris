#pragma once
#include <vector>
#include <string>

namespace velaris
{

    struct State
    {
        // Position
        double x, y, z;
        // Attitude
        double phi, theta, psi;
        // Translation
        double u, v, w;
        // Rotation
        double p, q, r;
    };

    class Aircraft
    {

    public:
        Aircraft(double mass);

        State get_state();
        void update_state(const State& new_state);
        void print_status() const;

    private:
        double mass_;
        State state_{}; // initialise all to 0.0
    };

}