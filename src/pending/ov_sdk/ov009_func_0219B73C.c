/*
 * function: func_0219B73C
 * address:  0x0219B73C
 * packet:   pkt_ov009_0219B73C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (77 bytes differ: original zeroes saddr with byte stores 2..7 then 0, before the port swap; memset and a byte loop both miss)
 *
 * sdk:      get_sockaddrin (qr2.o)
 *
 * symbols:
 *   func_0217ED38  0x0217ED38  arm  ov009
 *   func_020948E0  0x020948E0  arm
 *   func_0215F650  0x0215F650  arm  ov009
 *   g_021A768C  0x021A768C  data
 */

typedef struct SOCHostEnt {
    unsigned char pad0[0xC];
    unsigned int **addrList;
} SOCHostEnt;

typedef struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
} SOCSockAddrIn;

#define SWAP16(x) ((unsigned short)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))

extern char g_021A768C[];
extern unsigned int func_0217ED38(char *name);
extern int func_020948E0(const char *a, const char *b);
extern SOCHostEnt *func_0215F650(char *name);
extern void *memset(void *s, int c, unsigned long n);

int func_0219B73C(char *host, int port, SOCSockAddrIn *saddr, SOCHostEnt **savehent)
{
    SOCHostEnt *hent = 0;
    unsigned char *z = (unsigned char *)saddr;
    int i;

    for (i = 0; i < 8; i++)
        z[i] = 0;
    saddr->family = 2;
    saddr->port = SWAP16((unsigned short)port);
    if (host)
        saddr->addr = func_0217ED38(host);
    else
        saddr->addr = 0;
    if (saddr->addr == (unsigned int)-1) {
        if (func_020948E0(host, g_021A768C) != 0) {
            hent = func_0215F650(host);
            if (!hent)
                return 0;
            saddr->addr = **hent->addrList;
        }
    }
    if (savehent)
        *savehent = hent;
    return 1;
}

