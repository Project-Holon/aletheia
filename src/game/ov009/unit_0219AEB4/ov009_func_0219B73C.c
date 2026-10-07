/*
 * function: func_0219B73C
 * address:  0x0219B73C
 * packet:   pkt_ov009_0219B73C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      get_sockaddrin (TwlDWC/libdwcgsqr2.TWL.HYB.a(qr2.o))
 *
 * symbols:
 *   func_0217ED38  0x0217ED38  arm  ov009
 *   func_020948E0  0x020948E0  arm
 *   func_0215F650  0x0215F650  arm  ov009
 *   g_021A768C     0x021A768C  data
 *
 * Fills a SOCSockAddrIn: len 0, family 2, byte-swapped port, then the address
 * (resolved by name, or from the host entry when the resolver fails and the
 * name matches g_021A768C).  Optionally hands the host entry back.
 *
 * The six byte stores that clear the port/address half of the struct are SIX
 * INDIVIDUAL STATEMENTS through an unsigned char *, not a loop and not a
 * memset: the image keeps them as six `strb`s (offsets 2..7, in that order,
 * with the port-swap `orr` scheduled into the middle) and both a byte loop
 * (which CW leaves rolled) and memset (a call) miss.  byte 0 and the family
 * byte are written afterwards, in that order.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_0219B73C.c \
 *       --func func_0219B73C --addr 0x0219B73C --region ov009 --arm --lang c99 --cc 1.1p1 --diff
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

extern char g_021A768C[];
extern int func_0217ED38(int a);
extern int func_020948E0(const char *a, const char *b);
extern SOCHostEnt *func_0215F650(char *name);
extern void *memset(void *s, int c, unsigned long n);

int func_0219B73C(char *host, int port, SOCSockAddrIn *saddr, SOCHostEnt **savehent)
{
    SOCHostEnt *hent = 0;
    unsigned char *p = (unsigned char *)saddr;

    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    saddr->len = 0;
    saddr->family = 2;
    saddr->port = (unsigned short)((((unsigned short)port >> 8) & 0xff) | (((unsigned short)port << 8) & 0xff00));
    if (host)
        saddr->addr = func_0217ED38((int)host);
    else
        saddr->addr = 0;
    if (saddr->addr == 0xFFFFFFFF) {
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
