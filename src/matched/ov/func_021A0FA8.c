/*
 * function: func_021A0FA8
 * address:  0x021A0FA8
 * packet:   pkt_021A0FA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with a zero second argument.
 *
 * symbols:
 *   func_021A0FA0  0x021A0FA0  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A0FA0(int *p, int v);

void func_021A0FA8(int *p)
{
    func_021A0FA0(p, 0);
}
