
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

class [[gnu::packed]] ethernet {
public:
    int a, b;

    ethernet() {
        a = 0xaaaaaaaa;
        b = 0xbbbbbbbb;
    }
};

template <typename Encap>
class [[gnu::packed]] ipv4 : public Encap {
public:
    int c, d;

    ipv4() {
        c = 0xcccccccc;
        d = 0xdddddddd;
    }
};

template <typename Encap>
class [[gnu::packed]] ipv6 : public Encap {
public:
    int c[4], d[4];

    ipv6() {
        for (int i=0; i<4; i++) {
            c[i] = 0x0c;
            d[i] = 0x0d;
        }
    }
};

template <typename Encap>
class [[gnu::packed]] udp : public Encap {
public:
    int e, f;
    char data[];

    udp() {
        e = 0xeeeeeeee;
        f = 0xffffffff;
    }
};


int dump(const char *ptr, int len) {
    for (int i=0; i<len; i++) {
        printf("%02hhx ", ptr[i]);
        if (i % 16 == 7)  printf(" ");
        if (i % 16 == 15)  printf("\n");
    }
    printf("\n");
    return 0;
}

using udpip = udp<ipv4<ethernet>>;

int main() {
    udp<ipv4<ethernet>> i1{};
    udp<ipv6<ethernet>> i6{};

    dump(reinterpret_cast<const char *>(&i1), sizeof(i1));
    dump(reinterpret_cast<const char *>(&i6), sizeof(i6));

    /*
     * This is promising!
     */
    auto packet = std::make_unique<char[]>(sizeof(udpip) + 128);
    auto udp_pkt = new(packet.get()) udpip();
    for (int i=0; i<128; i++) {
        udp_pkt->data[i] = i;
    }
    dump(packet.get(), sizeof(udpip) + 128);
}

