
// vim: ts=4:sts=4:sw=4:et

#include "basic.h"
#include "open_tun.h"
#include "ethernet.hh"
#include "arp.hh"

#include <unistd.h>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <string>

using std::cout;
using std::string;

AQUATIC_USING_NAMESPACE;

string adapter_name = "tap0";

int main() {
    int fd = tun_alloc(adapter_name.c_str());

    cout << adapter_name << " file descriptor is " << fd << "\n";

    uint8_t packet_buffer[2048];

    while (true) {
        int len = read(fd, packet_buffer, 2048);

        for (int i=0; i<len; i++) {
            printf("%02hhx ", packet_buffer[i]);
            if (i % 16 == 15)
                printf("\n");
        }
        printf("\n");

        ethernet_frame *eth = reinterpret_cast<ethernet_frame *>(packet_buffer);
        cout << *eth << "\n";

        if (eth->type() == ethertype::ARP) {
            auto arp = &eth->arp;
            cout << *arp << "\n";
        }
    }

    return 0;
}

