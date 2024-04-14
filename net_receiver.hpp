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
        receiver(socket_raw_rx &socket)
            : socket_{socket},
              buf_{},
              rx_len_{},
              src_{},
              sockaddr_len_{}
        {
        }
        ~receiver() {}

        ssize_t polling()
        {
            struct sockaddr sockaddr
            {
            };
            int saddr_len = sizeof(sockaddr);
            rx_len_ = recvfrom(socket_.value(),          /* socket fd */
                               buf_.data(),              /* pointer to buffer */
                               buf_.size(),              /* buffer size */
                               0,                        /* flags */
                               &sockaddr,                /* socket address */
                               (socklen_t *)&saddr_len); /* socket len */
            if (rx_len_ > 0)
            {
            }
            return rx_len_;
        }

        /**
         * @brief Return pointer to the Rx buffer
         *
         * @return unsigned char* Pointer to Rx buffer
         */
        auto data() const -> const unsigned char *
        {
            return buf_.data();
        }

        /**
         * @brief Received data length
         *
         * @return ssize_t Data length
         */
        auto len() const -> ssize_t
        {
            return rx_len_;
        }

        /**
         * @brief Return the socket source address, and source address length
         *
         * @return std::pair<struct sockaddr, int> Socket source address and address length
         */
        auto src() const -> std::pair<struct sockaddr, int>
        {
            return std::make_pair(src_, sockaddr_len_);
        }

    private:
        socket_raw_rx &socket_;
        std::array<unsigned char, BUF_LEN> buf_;
        ssize_t rx_len_;
        struct sockaddr src_;
        int sockaddr_len_;
    };
}
