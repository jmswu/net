#include <cstdio>
#include <cstdlib>
#include "net_socket.hpp"
#include "net_receiver.hpp"

int main()
{
    std::printf("Hello world\r\n");
    net::socket_raw_rx socket_raw_rx{};

    std::printf("socket df: %i\r\n", socket_raw_rx.value());
    if (socket_raw_rx.value() == -1)
    {
        std::printf("socket open error: %i\n\r", socket_raw_rx.value());
    }

    net::receiver receiver{socket_raw_rx};

    receiver.polling();

    // std::printf("rx len: %lu\r\n", rx_len);

    return EXIT_SUCCESS;
}