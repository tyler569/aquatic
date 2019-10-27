
// vim: sts=4:ts=4:sw=4:et

#ifndef AQUATIC_ARP_TABLE_HH
#define AQUATIC_ARP_TABLE_HH

#include "basic.h"
#include "mac_address.hh"
#include "ipv4_address.hh"

#include <cstdint>
#include <map>

AQUATIC_NAMESPACE

class arp_table {
    std::map<ipv4_address, mac_address> _entries;

public:
    arp_table() = default;

    mac_address lookup(ipv4_address);
    
    void insert_association(mac_address, ipv4_address);
};

AQUATIC_END_NAMESPACE

#endif // AQUATIC_ARP_TABLE_HH

