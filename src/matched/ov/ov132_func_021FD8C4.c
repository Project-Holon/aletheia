/*
 * function: STA_NET_SendKindA
 * address:  0x021FD8C4
 * packet:   pkt_021FD8C4
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021FCE74  0x021FCE74  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern void func_021FCE74(int unused, int kind, u32 value, u32 id);

void STA_NET_SendKindA(char *p, int a)
{
    func_021FCE74((int)p, 0xa, a, 0xff);
}
