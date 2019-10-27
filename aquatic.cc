
// vim: ts=4:sts=4:sw=4:et

#include "basic.h"
#include "open_tun.h"
#include "ethernet.hh"
#include "arp.hh"
#include "arp_table.hh"

#include <unistd.h>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <string>

using std::cout;
using std::string;

AQUATIC_USING_NAMESPACE;

string adapter_name = "tap0";

mac_address my_mac_address{"66:00:00:11:22:33"};
ipv4_address my_ip_address{"10.50.1.2"};

arp_table global_arp_table;

// Temporary explanitory ARP logic
int do_arp(arp_message const& arp) {
    global_arp_table.insert_association(
        arp._sender_mac_address, arp._sender_ipv4_address);

    if (arp._target_ipv4_address == my_ip_address &&
        arp.operation() == arp_operation::REQUEST) {

        // respond
    }

    return 0;
}

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

            do_arp(*arp);
        }
    }

    return 0;
}

