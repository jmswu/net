#include <cstdio>
#include <cstdlib>
#include "net_socket.hpp"

int main()
{
    std::printf("Hello world\r\n");
    net::socket_raw_rx socket_raw_rx{};

    std::printf("socket df: %i\r\n", socket_raw_rx.id().value_or(-1));

    return EXIT_SUCCESS;
}