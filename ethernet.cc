
// vim: sts=4:ts=4:sw=4:et

#include "basic.h"
#include "ethernet.hh"

#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <string>

using std::ostream;
using std::string;

AQUATIC_NAMESPACE

mac_address::mac_address(string str) {
    int res = sscanf(str.c_str(),
        "%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx",
        &v[0], &v[0], &v[0], &v[0], &v[0], &v[0]
    );
    if (res != 6) {
        throw std::runtime_error{"invalid mac address"};
    }
}

ostream& operator<<(ostream& s, mac_address const& m) {
    s << std::hex;
    for (int i=0; i<6; i++) {
        s << m.v[i];
        if (i < 5)  s << ":";
    }
    s << std::dec;
    return s;
}

ostream& operator<<(ostream& s, ethertype const& e) {
    string name;
    switch (e) {
    case ethertype::IP4:
        name = "IP4"; break;
    default:
        name = "unknown"; break;
    }
    s << name;
    return s;
}

ostream& operator<<(ostream& s, ethernet_frame const& e) {
    s << "f: ";
    s << e._destination;
    s << ", t: ";
    s << e._source;
    s << ", [";
    s << e._type;
    s << "]";
    return s;
}

AQUATIC_END_NAMESPACE

