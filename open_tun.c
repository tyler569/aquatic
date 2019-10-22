
// vim: ts=4:sts=4:sw=4:et

#include <stdbool.h>
#include <errno.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <net/if.h>
// #include <net/if_tun.h>
#include <linux/if.h>
#include <linux/if_tun.h>

// const char *tun_name = "tap0"

int tun_alloc(const char *tun_name) {
    int fd = open("/dev/net/tun", O_RDWR);
    if (fd < 0) {
        printf("Error: %s\n", strerror(errno));
        return -1;
    }

    struct ifreq ifr = {0};
    ifr.ifr_flags = IFF_TAP | IFF_NO_PI;
    strncpy(ifr.ifr_name, tun_name, IFNAMSIZ);

    int err = ioctl(fd, TUNSETIFF, (void *)&ifr);
    if (err < 0) {
        printf("Error: %s\n", strerror(errno));
        close(fd);
        return err;
    }

    return fd;
}

