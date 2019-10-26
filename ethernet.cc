
// vim: sts=4:ts=4:sw=4:et

#include "basic.h"
#include "ethernet.hh"

#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <string>

using std::ostream;
using std::string;

namespace aquatic {

mac_address::mac_address(string str) {
    int res = sscanf(str.c_str(),
        "%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx",
        &v[0], &v[0], &v[0], &v[0], &v[0], &v[0]
    );
    if (res != 6) {
        throw std::runtime_error{"invalid mac address"};
    }
}

ostream& mac_address::operator<<(ostream& s) {
    s << std::hex;
    for (int i=0; i<6; i++) {
        s << v[i];
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

ostream& ethernet_frame::operator<<(ostream& s) {
    s << "f: " << destination()
      << ", t: " << source()
      << ", [" << type() << "]"
    return s;
}

} // namespace aquatic

