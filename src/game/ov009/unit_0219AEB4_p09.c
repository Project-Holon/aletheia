/*
 * file:     unit_0219AEB4_p09.c
 * unit:     yes
 * function: enum_local_ips
 * address:  0x0219B6CC
 * packet:   pkt_ov009_0219B6CC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      enum_local_ips (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * Closed (w4_nm): the address copy is memcpy(&local_ip_list[i], addr,
 * sizeof(struct SOCInAddr)) through string.h, which mwccarm inlines as the
 * 1-aligned ldrb/strb copy with the ip/lr roles of the object (the struct
 * assignment gave the converse roles). SOCInAddr stays { unsigned char addr[4]; }.
 *
 * symbols:
 *   getlocalhost   0x0217EFB8 arm ov009
 *   num_local_ips  0x021AE9A0 data
 *   local_ip_list  0x021AE9A4 data
 */

#include "../../matched/arm9_sdk/libc/string.h"

struct SOCInAddr {
    unsigned char addr[4];
};

struct SOCHostEnt {
    char *name;
    char **aliases;
    short addrType;
    short length;
    unsigned char **addrList;
};

extern struct SOCHostEnt *getlocalhost(void);
extern int num_local_ips;
extern struct SOCInAddr local_ip_list[5];

static void enum_local_ips(void)
{
    struct SOCHostEnt *phost;
    int i;

    phost = getlocalhost();
    if (phost == 0)
        return;
    num_local_ips = 0;
    for (i = 0; i < 5; i++) {
        if (phost->addrList[i] == 0)
            return;
        memcpy(&local_ip_list[i], phost->addrList[i], sizeof(struct SOCInAddr));
        num_local_ips = i + 1;
    }
}
