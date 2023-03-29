#include <iostream>
#include <thread>
#include "include/MavLinkConnection.hpp"

int main() {

    std::cout << "DroneMavLinkTransport start" << std::endl;

    auto droneConnection = mavlinkcom::MavLinkConnection::connectSerial("drone", "/dev/ttyACM0", 115200, "sh /etc/init.d/rc.usb\n");
    auto proxyConnection = mavlinkcom::MavLinkConnection::connectRemoteUdp("qgc", "127.0.0.1", "127.0.0.1", 14550);
    droneConnection->join(proxyConnection);

    return 0;
}
