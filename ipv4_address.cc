
// vim: sts=4:ts=4:sw=4:et

#include "basic.h"
#include "ipv4.hh"

#include <cstdio>
#include <cstdint>
#include <iostream>
#include <string>

using std::string;
using std::ostream;

AQUATIC_NAMESPACE

ipv4_address::ipv4_address(string str) {
    int res = sscanf(str.c_str(),
        "%02hhu.%02hhu.%02hhu.%02hhu",
        &v[0], &v[1], &v[2], &v[3]
    );
    if (res != 4) {
        throw std::runtime_error{"invalid ipv4 address"};
    }
}
    
ostream& operator<<(ostream& s, ipv4_address const& a) {
    for (int i=0; i<4; i++) {
        s << (int)a.v[i];
        if (i < 3)  s << ".";
    }

    return s;
}

AQUATIC_END_NAMESPACE

