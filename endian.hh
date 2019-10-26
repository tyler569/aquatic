
// vim: sts=4:ts=4:sw=4:et

#ifndef AQUATIC_ENDIAN_HH
#define AQUATIC_ENDIAN_HH

#include "basic.h"

#include <cstdint>
#include <byteswap.h>

AQUATIC_NAMESPACE

struct [[gnu::packed]] be16 {
    uint16_t raw;

    be16 operator=(uint16_t v) {
        raw = __bswap_16(v);
        return *this;
    }

    uint16_t host() {
        return __bswap_16(raw);
    }
};

AQUATIC_END_NAMESPACE

#endif // AQUATIC_ENDIAN_HH

