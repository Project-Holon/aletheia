/*
 * function: func_021BC06C
 * address:  0x021BC06C
 * packet:   pkt_021BC06C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call forwarding p and the byte field at +0x32.
 *
 * symbols:
 *   func_021BC07C  0x021BC07C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

extern int func_021BC07C(void *, u8);

int func_021BC06C(char *p)
{
    return func_021BC07C(p, *(u8 *)(p + 0x32));
}
