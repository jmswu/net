#include <cstdio>
#include <cstdlib>
#include "net_socket.hpp"
#include "net_receiver.hpp"

void helper_print_rx_data(net::receiver_def &rx)
{
    if (rx.polling() > 0)
    {
        std::printf("rx data [%li]:\r\n", rx.len());
        for (int i = 0; i < rx.len(); i++)
        {
            std::printf("x%02X ", rx.data()[i]);
        }
        std::printf("\r\n");

        const auto [src, len] = rx.src();
        std::printf("sockaddr family: %i\r\n", src.sa_family);
        std::printf("sockaddr data  :");
        for (std::size_t i = 0; i < sizeof(src.sa_data); i++)
        {
            std::printf("x%02X ", src.sa_data[i]);
        }
        std::printf("\r\n");
    }
}

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

    net::receiver_def receiver{socket_raw_rx};
    helper_print_rx_data(receiver);

    return EXIT_SUCCESS;
}