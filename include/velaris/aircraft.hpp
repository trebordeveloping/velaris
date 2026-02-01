#pragma once
#include <vector>
#include <string>
#include <Eigen/Dense>

namespace velaris
{

    struct State
    {
        // Position
        Eigen::Vector3d pos = Eigen::Vector3d::Zero();  // x, y, z
        // Attitude
        Eigen::Vector3d att = Eigen::Vector3d::Zero();  // bank, pitch, azimuth
        // Translation
        Eigen::Vector3d vel = Eigen::Vector3d::Zero();  // u, v, w
        // Rotation
        Eigen::Vector3d rot = Eigen::Vector3d::Zero();  // p, q, r
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
        Eigen::Vector3d forces_ = Eigen::Vector3d::Zero(); // Add this line
    };

}