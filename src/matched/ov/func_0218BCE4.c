/*
 * function: func_0218BCE4
 * address:  0x0218BCE4
 * packet:   pkt_0218BCE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores a tag and a byte, then tail calls with the same operands.
 *
 * symbols:
 *   func_0218BCF4  0x0218BCF4  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0218BCF4(u32 *p, u32 v, u32 tag);

void func_0218BCE4(u32 *p, u32 v)
{
    p[0] = 5;
    *((u8 *)p + 0xd) = v;
    func_0218BCF4(p, v, 5);
}
