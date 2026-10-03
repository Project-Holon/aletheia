/*
 * function: func_0215793C
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
 *   func_021578EC  0x021578EC  arm  ov009
 *   func_02157928  0x02157928  arm  ov009
 *   g_021A826C  0x021A826C  data
 */

extern char g_021A826C[];
extern unsigned long func_021578EC(unsigned long ip);
extern int func_02157928(unsigned v);

unsigned long func_0215793C(unsigned long ip)
{
    unsigned long my = *(unsigned long *)(g_021A826C + 0x50);
    int d = 1;
    int c = 1;
    int b = 1;
    int a = 1;

    if (my != 0 && ip != my)
        a = 0;
    if (!a && ip != 0x7f000001)
        b = 0;
    if (!b && func_021578EC(ip) == 0)
        c = 0;
    if (!c && func_02157928(ip) == 0)
        d = 0;
    return d;
}
