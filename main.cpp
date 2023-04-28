#include <iostream>
#include "include/MavLinkConnection.hpp"
#include "include/MavLinkVehicle.hpp"
#include "include/MavLinkMessages.hpp"

int main() {

    std::cout << "DroneMavLinkTransport start" << std::endl;

    // Serial connect to PX4
    auto droneConnection = mavlinkcom::MavLinkConnection::connectSerial("drone", "/dev/ttyS1", 57600, "sh /etc/init.d/rc.usb\n");

    // Create MavLinkVehicle which associated with serial port
    auto vehicle = std::make_shared<mavlinkcom::MavLinkVehicle>(0, -1);
    vehicle->connect(droneConnection);
    vehicle->startHeartbeat();

    // Check vehicle heartbeat to make sure everything is okay
    mavlinkcom::MavLinkHeartbeat heartbeat;
    bool wait = vehicle->waitForHeartbeat().wait(10000, &heartbeat);
    if (!wait) {
        throw std::runtime_error("Received no heartbeat from PX4 after 10 seconds!");
    }

    // Get compass status
    while(true) {
        float pitch = vehicle->getVehicleState().attitude.pitch;
        float yaw = vehicle->getVehicleState().attitude.yaw;
        float roll = vehicle->getVehicleState().attitude.roll;
        std::cout << "[pitch, yaw, roll]: " << pitch << " " << yaw << " " << roll << std::endl;
    }

    return 0;
}
