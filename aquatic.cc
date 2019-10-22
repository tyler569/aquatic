
// vim: ts=4:sts=4:sw=4:et

#include "basic.h"
#include "open_tun.h"

#include <cstdio>
#include <iostream>
#include <string>

using std::cout;
using std::string;

string adapter_name = "tap0";

int main() {
    int fd = tun_alloc(adapter_name.c_str());

    cout << adapter_name << " file descriptor is " << fd << "\n";
    return 0;
}

