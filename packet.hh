
// vim: sts=4:ts=4:sw=4:et

#ifndef AQUATIC_PACKET_HH
#define AQUATIC_PACKET_HH

#include <header.hh>

#include <cstddef>

class packet {
public:
    char *data;
    size_t len;

    packet(size_t len=2048);
    ~packet();

    header next_header() const;
};

#endif // AQUATIC_PACKET_HH

