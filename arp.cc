
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
        phrase = "who-has";
    } else if (a.operation() == arp_operation::REPLY) {
        phrase = "is-at";
    }

    s << "arp message{sender:{";
    s << a._sender_mac_address;
    s << ", ";
    s << a._sender_ipv4_address;
    s << "} ";
    s << phrase;
    s << " {";
    s << a._target_mac_address;
    s << ", ";
    s << a._target_ipv4_address;
    s << "} }";

    return s;
}

AQUATIC_END_NAMESPACE

