#include <cstdio>
#include <cstdlib>
#include "net_socket.hpp"

int main()
{
    std::printf("Hello world\r\n");
    net::socket_raw socket_raw{};

    std::printf("socket df: %i\r\n", socket_raw.id().value_or(-1));

    return EXIT_SUCCESS;
}