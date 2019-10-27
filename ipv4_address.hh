
// vim: sts=4:ts=4:sw=4:et

#ifndef AQUATIC_IPV4_ADDRESS_HH
#define AQUATIC_IPV4_ADDRESS_HH

#include "basic.h"

#include <cstdint>
#include <cstring>
#include <string>
#include <iostream>

using std::string;
using std::ostream;

AQUATIC_NAMESPACE

class [[gnu::packed]] ipv4_address {
    uint8_t v[4];

public:
    ipv4_address(string);
    
    bool operator==(ipv4_address const& other) const {
        return memcmp(v, other.v, 4) == 0;
    }
    bool operator<(ipv4_address const& other) const {
        return memcmp(v, other.v, 4) < 0;
    }

    friend ostream& operator<<(ostream&, ipv4_address const&);
};

AQUATIC_END_NAMESPACE

#endif // AQUATIC_IPV4_ADDRESS_HH

