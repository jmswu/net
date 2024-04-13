#pragma once

#include <unistd.h>
// #include <sys/types.h>
#include <sys/socket.h>
#include <net/ethernet.h>
#include <netinet/in.h>
// #include <linux/if_packet.h>
// #include <arpa/inet.h>
// #include <netdb.h>

namespace net
{
    class socket_raw
    {
    public:
        socket_raw() : socket_fd_{}
        {
            socket_fd_ = socket(AF_PACKET,         /* Socket for network driver level */
                                SOCK_RAW,          /* Raw socket, so we can capture frame from Ethernet */
                                htons(ETH_P_ALL)); /* capture everything */
        }

        ~socket_raw()
        {
            if (socket_fd_ != 1)
            {
                close(socket_fd_);
            }
        };

    private:
        int socket_fd_;
    };
}
