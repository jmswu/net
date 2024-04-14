#pragma once

#include <optional>
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
    /**
     * @brief Wrap socket in class so it guaranteed close when out of scope.
     * This is a raw socket that receives everything
     */
    class socket_raw_rx
    {
    public:
        socket_raw_rx() : socket_fd_{}
        {
            socket_fd_ = socket(AF_PACKET,         /* Socket for network driver level */
                                SOCK_RAW,          /* Raw socket, so we can capture frame from Ethernet */
                                htons(ETH_P_ALL)); /* capture everything */
        }

        /* socket can't be copied or moved */
        socket_raw_rx(const socket_raw_rx &) = delete;
        socket_raw_rx(socket_raw_rx &&) = delete;
        socket_raw_rx &operator=(const socket_raw_rx &) = delete;
        socket_raw_rx &operator=(socket_raw_rx &&) = delete;

        /**
         * @brief Return a socket ID
         *
         * @return std::optional<int> socket id
         */
        auto value() const -> std::optional<int>
        {
            return socket_fd_;
        }

        ~socket_raw_rx()
        {
            if (socket_fd_ != -1)
            {
                close(socket_fd_);
            }
        };

    private:
        int socket_fd_;
    };
}
