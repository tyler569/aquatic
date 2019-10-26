
// vim: sts=4:ts=4:sw=4:et

#ifndef AQUATIC_ETHERNET_HH
#define AQUATIC_ETHERNET_HH

#include "basic.h"
#include "ipv4.hh"

#include <cstdint>
#include <iostream>
#include <string>

using std::ostream;
using std::string;

namespace aquatic {

struct [[gnu::packed]] mac_address {
    uint8_t v[6];

public:
    mac_address();
    mac_address(string);

    bool operator==(mac_address const& othr) const {
        return memcmp(this->v, othr.v, 6) == 0;
    }

    ostream& operator<<(ostream& s) const;
};

enum class ethertype : uint16_t {
    IP4 = 0x0800,
}

class [[gnu::packed]] ethernet_frame {
public:
    mac_address _destination;
    mac_address _source;
    ethertype _type;
public:
    union [[gnu::packed]] {
        ipv4_packet ipv4;
    };

public:
    ostream& operator<<(ostream& s) const;
};

} // namespace aquatic

#endif // AQUATIC_ETHERNET_HH

