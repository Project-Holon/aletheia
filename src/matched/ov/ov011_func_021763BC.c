/*
 * function: func_021763BC
 * address:  0x021763BC
 * packet:   pkt_ov011_021763BC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021763D8  0x021763D8  thumb  ov011
 *
 * Zeroes the six bytes at +6 one at a time, and after each store lets
 * func_021763D8 fill p[key] for key 0..5.  Called from arm9 func_0200BDE4
 * (bl at 0x0200BDF2) and from ov011 at 0x0217644C.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_021763D8(u8 *p, u32 key);

void func_021763BC(u8 *p)
{
    int i;

    for (i = 0; i < 6; i++) {
        p[i + 6] = 0;
        func_021763D8(p, i);
    }
}
