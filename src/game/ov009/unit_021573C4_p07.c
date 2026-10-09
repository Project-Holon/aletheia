/*
 * file:     unit_021573C4_p07.c
 * unit:     yes
 * function: func_02157D48
 * address:  0x02157D48
 * packet:   pkt_ov009_02157D48
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      throw_packet (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   g_021A826C  0x021A826C  data
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */

struct net_vars {
    char pad0[0x20];
    char *buf;
    char pad1[0x38];
    unsigned long limit;
    char pad2[4];
    volatile unsigned long put;
};

extern struct net_vars g_021A826C;
extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long state);

/*
 * sdk:      throw_packet (libcps.TWL.HYB.a(network.o))
 *
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
void func_02157D48(void)
{
    unsigned long en = func_02087988();

    g_021A826C.put += *(unsigned short *)(g_021A826C.buf + g_021A826C.put);
    if (g_021A826C.put >= g_021A826C.limit)
        g_021A826C.put = 0;
    func_0208799C(en);
}
