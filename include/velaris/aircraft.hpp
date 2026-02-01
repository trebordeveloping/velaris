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

    struct Forces
    {
        double x, y, z;
    };

    class Aircraft
    {

    public:
        Aircraft(double mass);

        State get_state();
        void forces();
        void update(double dt);
        void print_status() const;

    private:
        double mass_;
        State state_{}; // initialise all to 0.0
        Forces forces_{};
    };

}