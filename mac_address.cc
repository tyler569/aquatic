
// vim: sts=4:ts=4:sw=4:et

#include "basic.h"
#include "mac_address.hh"

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
        &v[0], &v[1], &v[2], &v[3], &v[4], &v[5]
    );
    if (res != 6) {
        throw std::runtime_error{"invalid mac address"};
    }
}

ostream& operator<<(ostream& s, mac_address const& m) {
    s << std::hex;
    for (int i=0; i<6; i++) {
        s << (int)m.v[i];
        if (i < 5)  s << ":";
    }
    s << std::dec;
    return s;
}

AQUATIC_END_NAMESPACE

