
// vim: sts=4:ts=4:sw=4:et

#ifndef AQUATIC_ARP_HH
#define AQUATIC_ARP_HH

#include "basic.h"
#include "mac_address.hh"
#include "ipv4.hh"

#include <cstdint>
#include <iostream>

using std::ostream;

AQUATIC_NAMESPACE

enum class arp_operation : uint16_t {
    REQUEST = 1,
    REPLY = 2,
};

class [[gnu::packed]] arp_message {
public:
    be16 _hardware_type;
    be16 _protocol_type;
    uint8_t _hardware_address_length;
    uint8_t _protocol_address_length;
    be16 _operation;

    // TODO: support IPv6

    mac_address _sender_mac_address;
    ipv4_address _sender_ipv4_address;

    mac_address _target_mac_address;
    ipv4_address _target_ipv4_address;

public:
    arp_operation operation() const {
        return arp_operation{_operation.host()};
    }

    friend ostream& operator<<(ostream&, arp_message const&);
};

AQUATIC_END_NAMESPACE

#endif // AQUATIC_ICMP_HH

