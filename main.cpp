#include <cstdio>
#include <cstdlib>
#include "net_socket.hpp"

#include <array>
#include <cstdint>

int main()
{
    std::printf("Hello world\r\n");
    net::socket_raw_rx socket_raw_rx{};

    std::printf("socket df: %i\r\n", socket_raw_rx.value());
    if (socket_raw_rx.value() == -1)
    {
        std::printf("socket open error: %i\n\r", socket_raw_rx.value());
    }

    std::array<std::uint8_t, 65000> buffer{};
    struct sockaddr saddr;
    int saddr_len = sizeof(saddr);
    const auto rx_len = recvfrom(socket_raw_rx.value().value(),
                                 buffer.data(),
                                 buffer.size(),
                                 0,
                                 &saddr, (socklen_t *)&saddr_len);

    if (rx_len < 0)
    {
        std::printf("rx error\r\n");
    }

    std::printf("rx len: %lu\r\n", rx_len);

    return EXIT_SUCCESS;
}