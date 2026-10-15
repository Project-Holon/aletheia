/*
 * function: ip_isme
 * address:  0x0215793C
 * packet:   pkt_ov009_0215793C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ip_isme (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   is_broadcast  0x021578EC  arm  ov009
 *   is_multicast  0x02157928  arm  ov009
 *   gCpsNetVars  0x021A826C  data
 */

extern char gCpsNetVars[];
extern unsigned long is_broadcast(unsigned long ip);
extern int is_multicast(unsigned v);

unsigned long ip_isme(unsigned long ip)
{
    unsigned long my = *(unsigned long *)(gCpsNetVars + 0x50);
    int d = 1;
    int c = 1;
    int b = 1;
    int a = 1;

    if (my != 0 && ip != my)
        a = 0;
    if (!a && ip != 0x7f000001)
        b = 0;
    if (!b && is_broadcast(ip) == 0)
        c = 0;
    if (!c && is_multicast(ip) == 0)
        d = 0;
    return d;
}
