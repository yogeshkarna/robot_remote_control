#pragma once

#include <robot_remote_control/Types/RobotRemoteControl.pb.h>
#include <base/samples/Twist.hpp>
#include "Eigen.hpp"
#include "Time.hpp"

namespace robot_remote_control {
namespace RockConversion {

    inline static void convert(const Twist &rrc_type, base::samples::Twist* rock_type) {
        convert(rrc_type.linear(), &(rock_type->linear));
        convert(rrc_type.angular(), &(rock_type->angular));
        convert(rrc_type.frame(), &(rock_type->frame_id));
        convert(rrc_type.timestamp(), &(rock_type->time));
    }

    inline static void convert(const base::samples::Twist &rock_type, Twist* rrc_type) {
        convert(rock_type.linear, &(rrc_type->linear()));
        convert(rock_type.angular, &(rrc_type->angular()));
        convert(rock_type.frame_id, &(rrc_type->frame()));
        convert(rock_type.time, &(rrc_type->timestamp()));
    }

}  // namespace RockConversion
}  // namespace robot_remote_control
