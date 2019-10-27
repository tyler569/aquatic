
// vim: sts=4:ts=4:sw=4:et

#ifndef AQUATIC_ETHERNET_HH
#define AQUATIC_ETHERNET_HH

#include "basic.h"
#include "mac_address.hh"
#include "arp.hh"
#include "ipv4.hh"
#include "endian.hh"

#include <cstdint>
#include <iostream>
#include <string>

using std::ostream;
using std::string;

AQUATIC_NAMESPACE

enum class ethertype : uint16_t {
    IPV4 = 0x0800,
    ARP = 0x0806,
    IPV6 = 0x86DD,
};

ostream& operator<<(ostream&, ethertype const&);

class [[gnu::packed]] ethernet_frame {
public:
    mac_address _destination;
    mac_address _source;
    be16 _type;
public:
    union [[gnu::packed]] {
        arp_message arp;
        ipv4_packet ipv4;
    };

public:
    ethertype type() const {
        return ethertype{_type.host()};
    }

    friend ostream& operator<<(ostream& s, ethernet_frame const&);
};

AQUATIC_END_NAMESPACE

#endif // AQUATIC_ETHERNET_HH

