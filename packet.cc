
// vim: sts=4:ts=4:sw=4:et

#include <packet.hh>
#include <header.hh>

#include <cstddef>

packet::packet(size_t len) {
    data = new char[len];
}

packet::~packet() {
    delete[] data;
}

header packet::next_header() const {
}

