
// vim: sts=4:ts=4:sw=4:et

#include "basic.h"
#include "ipv4.hh"
#include "ipv4_address.hh"

#include <cstdint>
#include <string>
#include <iostream>

using std::string;
using std::ostream;

AQUATIC_NAMESPACE

ostream& operator<<(ostream& s, ipv4_protocol const& a) {
    string protocol_name;
    switch (a) {
    case ipv4_protocol::ICMP:
        protocol_name = "ICMP"; break;
    case ipv4_protocol::TCP:
        protocol_name = "TCP"; break;
    case ipv4_protocol::UDP:
        protocol_name = "UDP"; break;
    default:
        protocol_name = "unknown"; break;
    }
    s << protocol_name;

    return s;
}

ostream& operator<<(ostream& s, ipv4_packet const& a) {
    s << "ipv4 packet { from: ";
    s << a._source;
    s << ", to: ";
    s << a._destination;
    s << ", protocol: [";
    s << a._protocol;
    s << "] }";

    return s;
}

AQUATIC_END_NAMESPACE

