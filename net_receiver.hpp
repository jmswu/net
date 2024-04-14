/**
 * @file net_receiver.hpp
 * @author James Wu (jameswu62@yahoo.co.nz)
 * @brief
 * @version 0.1
 * @date 2024-04-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#include <array>
#include <limits>
#include "net_socket.hpp"

namespace net
{
    template <const size_t BUF_LEN = UINT16_MAX>
    class receiver
    {
    public:
        receiver(socket_raw_rx &socket) : socket_{socket}, buf_{}, rx_len_{}
        {
        }
        ~receiver() {}

        ssize_t polling()
        {
            struct sockaddr sockaddr
            {
            };
            int saddr_len = sizeof(sockaddr);
            rx_len_ = recvfrom(socket_.value(),
                               buf_.data(),
                               buf_.size(),
                               0,
                               &sockaddr,
                               (socklen_t *)&saddr_len);
            std::printf("rx len: %lu\r\n", rx_len_);
            return rx_len_;
        }

    private:
        socket_raw_rx &socket_;
        std::array<unsigned char, BUF_LEN> buf_;
        ssize_t rx_len_;
    };
}
