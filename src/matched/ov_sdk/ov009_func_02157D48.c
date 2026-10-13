/*
 * function: throw_packet
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
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
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
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

void throw_packet(void)
{
    unsigned long en = OS_DisableInterrupts();

    g_021A826C.put += *(unsigned short *)(g_021A826C.buf + g_021A826C.put);
    if (g_021A826C.put >= g_021A826C.limit)
        g_021A826C.put = 0;
    OS_RestoreInterrupts(en);
}
