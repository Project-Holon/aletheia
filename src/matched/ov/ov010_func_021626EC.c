/*
 * function: func_021626EC
 * address:  0x021626EC
 * packet:   pkt_ov010_021626EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (a .word run in the ov010 listing): true when either of
 * the first two halfwords is 0xFFFF.  Callee of ov021 func_0218B0CC.
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

int func_021626EC(u16 *p)
{
    if (p[0] == 0xFFFF || p[1] == 0xFFFF)
        return 1;
    return 0;
}
