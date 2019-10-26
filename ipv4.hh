
// vim: sts=4:ts=4:sw=4:et

#ifndef AQUATIC_IPV4_HH
#define AQUATIC_IPV4_HH

#include "basic.h"
#include "icmp.hh"
#include "endian.hh"

namespace aquatic {

class [[gnu::packed]] ipv4_address {
    char v[4];

public:
    ipv4_address(string);
};

enum class ipv4_protocol : uint8_t {
    ICMP = 1,
    TCP = 6,
    UDP = 17,
};

class [[gnu::packed]] ipv4_packet {
public:
    uint8_t _version_ihl;
    uint8_t _dscp_ecn;
    be16 _length;
    be16 _ident;
    be16 _flags_offset;
    uint8_t _ttl;
    ipv4_protocol _protocol;
    uint16_t _checksum;
    ipv4_address _source;
    ipv4_address _destination;

public:
    union {
        icmp_message icmp;
    };

    uint8_t version() {
        return _version_ihl >> 4;
    }
    uint8_t ihl() {
        return _version_ihl & 0x0F;
    }

    uint16_t length() {
        return _length.host();
    }
    uint16_t ident() {
        return _ident.host();
    }
};

} // namespace aquatic

#endif // AQUATIC_IPV4_HH

