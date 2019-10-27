
// vim: sts=4:ts=4:sw=4:et

#include "basic.h"
#include "arp_table.hh"
#include "mac_address.hh"
#include "ipv4_address.hh"

#include <map>

AQUATIC_NAMESPACE

mac_address arp_table::lookup(ipv4_address a) {
    if (_entries.count(a) > 0) {
        return _entries[a];
    }
    // TODO: send an ARP request (maybe here, maybe not?)
    return {};
}

void arp_table::insert_association(mac_address m, ipv4_address a) {
    _entries[a] = m;
}

AQUATIC_END_NAMESPACE

