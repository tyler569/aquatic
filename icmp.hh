
// vim: sts=4:ts=4:sw=4:et

#ifndef AQUATIC_ICMP_HH
#define AQUATIC_ICMP_HH

#include "basic.h"

#include <cstdint>

AQUATIC_NAMESPACE

enum class icmp_type : uint8_t {
    ECHO_REPLY = 0,
    ECHO_REQUEST = 8,
};

class [[gnu::packed]] icmp_message {
public:
    icmp_type _type;
    uint8_t _code;
    uint16_t checksum;

public:
};

AQUATIC_END_NAMESPACE

#endif // AQUATIC_ICMP_HH

