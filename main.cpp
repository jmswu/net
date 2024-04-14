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
        return EXIT_SUCCESS;
    }

    net::receiver receiver{socket_raw_rx};
    if (receiver.polling() > 0)
    {
        for (int i = 0; i < receiver.len(); i++)
        {
            std::printf("%02X ", receiver.data()[i]);
        }
        std::printf("\r\n");
    }

    return EXIT_SUCCESS;
}