
// vim: sts=4:ts=4:sw=4:et

#ifndef AQUATIC_ETHERNET_HH
#define AQUATIC_ETHERNET_HH

#include "basic.h"
#include "ipv4.hh"

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
    mac_address();
    mac_address(string);

    bool operator==(mac_address const& othr) const {
        return memcmp(this->v, othr.v, 6) == 0;
    }

    friend ostream& operator<<(ostream& s, mac_address const&);
};

enum class ethertype : uint16_t {
    IP4 = 0x0800,
};

ostream& operator<<(ostream&, ethertype const&);

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
    friend ostream& operator<<(ostream& s, ethernet_frame const&);
};

AQUATIC_END_NAMESPACE

#endif // AQUATIC_ETHERNET_HH

