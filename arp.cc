
// vim: sts=4:ts=4:sw=4:et

#include "basic.h"
#include "arp.hh"

#include <cstdio>
#include <cstdint>
#include <iostream>
#include <string>

using std::string;
using std::ostream;

AQUATIC_NAMESPACE

ostream& operator<<(ostream& s, arp_message const& a) {
    string phrase;
    if (a.operation() == arp_operation::REQUEST) {
        s << "arp message { who-has ";
        s << a._target_ipv4_address;
        s << " ? - tell {";
        s << a._sender_mac_address;
        s << ", ";
        s << a._sender_ipv4_address;
        s << "} }";
    } else if (a.operation() == arp_operation::REPLY) {
        s << "arp message { ";
        s << a._sender_ipv4_address;
        s << " is-at ";
        s << a._sender_mac_address;
        s << "} }";
    }

    /*
    s << "arp message { sender: {";
    s << a._sender_mac_address;
    s << ", ";
    s << a._sender_ipv4_address;
    s << "} ";
    s << phrase; // who-has / is-at
    s << " {";
    s << a._target_mac_address;
    s << ", ";
    s << a._target_ipv4_address;
    s << "} }";
    */

    return s;
}

AQUATIC_END_NAMESPACE

