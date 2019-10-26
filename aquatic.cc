
// vim: ts=4:sts=4:sw=4:et

#include "basic.h"
#include "open_tun.h"
#include "endian.hh"

#include <cstdio>
#include <iostream>
#include <string>

using std::cout;
using std::string;

using namespace aquatic;

string adapter_name = "tap0";

int main() {
    int fd = tun_alloc(adapter_name.c_str());

    cout << adapter_name << " file descriptor is " << fd << "\n";

    be16 foo{0x100};
    cout << foo.raw << "\n";
    cout << foo.host() << "\n";

    return 0;
}

