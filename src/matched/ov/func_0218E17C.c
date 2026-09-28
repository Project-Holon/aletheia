/*
 * function: func_0218E17C
 * address:  0x0218E17C
 * packet:   pkt_0218E17C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores the word at +0x10, then tail calls with both arguments.
 *
 * symbols:
 *   func_0218E160  0x0218E160  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0218E160(u32 *p, u32 v);

void func_0218E17C(u32 *p, u32 v)
{
    p[4] = v;
    func_0218E160(p, v);
}
