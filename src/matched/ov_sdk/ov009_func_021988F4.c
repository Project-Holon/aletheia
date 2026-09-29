/*
 * function: func_021988F4
 * address:  0x021988F4
 * packet:   pkt_ov009_021988F4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GetLocalIP (natify.o)
 *
 * symbols:
 *   func_0217EFB8  0x0217EFB8  arm  ov009
 *   func_0217F038  0x0217F038  arm  ov009
 */

typedef struct SOCInAddr {
    unsigned int addr;
} SOCInAddr;

typedef struct SOCHostEnt {
    unsigned char pad0[0xC];
    SOCInAddr **addrList;
} SOCHostEnt;

extern SOCHostEnt *func_0217EFB8(void);
extern int func_0217F038(SOCInAddr *addr);

unsigned int func_021988F4(void)
{
    int num_local_ips;
    SOCHostEnt *phost;
    SOCInAddr *addr;
    unsigned int localip;

    localip = 0;
    phost = func_0217EFB8();
    if (!phost)
        return 0;
    for (num_local_ips = 0;; num_local_ips++) {
        addr = phost->addrList[num_local_ips];
        if (!addr)
            break;
        if (addr->addr != 16777343) {
            localip = *(unsigned int *)addr;
            if (func_0217F038((SOCInAddr *)addr))
                return localip;
        }
    }
    return localip;
}
