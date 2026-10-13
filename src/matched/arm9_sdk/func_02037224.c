/*
 * function: GFL_NET_SYSTEM_SetDebugByte
 * address:  0x02037224
 * packet:   pkt_02037224
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_020A7A20   0x020A7A20  data  a1
 */

typedef unsigned char u8;

extern u8 d_020A7A20;

void GFL_NET_SYSTEM_SetDebugByte(u8 v, int b)
{
    d_020A7A20 = v;
}
