
// vim: sts=4:ts=4:sw=4:et

#ifndef AQUATIC_MAC_ADDRESS_HH
#define AQUATIC_MAC_ADDRESS_HH

#include "basic.h"

#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>

using std::ostream;
using std::string;

AQUATIC_NAMESPACE

struct [[gnu::packed]] mac_address {
    uint8_t v[6];

public:
    mac_address(string);
    mac_address() = default;

    bool operator==(mac_address const& other) const {
        return memcmp(v, other.v, 6) == 0;
    }
    bool operator<(mac_address const& other) const {
        return memcmp(v, other.v, 6) < 0;
    }

    friend ostream& operator<<(ostream& s, mac_address const&);
};

AQUATIC_END_NAMESPACE

#endif // AQUATIC_ETHERNET_HH

