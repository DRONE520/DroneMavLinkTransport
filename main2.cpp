#include <iostream>
#include "include/MavLinkConnection.hpp"
#include "include/MavLinkVehicle.hpp"

int main(int argc, char* argv[]) {

    std::cout << "Proxying is running..." << std::endl;
    std::cout << "Remote address: " << argv[1] << std::endl;

    // Serial connect to PX4
    auto droneConnection = mavlinkcom::MavLinkConnection::connectSerial("drone", "/dev/ttyS1", 57600, "sh /etc/init.d/rc.usb\n");
    auto proxyConnection = mavlinkcom::MavLinkConnection::connectRemoteUdp("qgc", "192.168.1.111", argv[1], 14550);
    droneConnection->join(proxyConnection);


    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::hours(std::numeric_limits<int>::max()));
}
