/*
 * function: func_021CA184
 * address:  0x021CA184
 * packet:   pkt_021CA184
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CA154  0x021CA154  thumb
 *   func_021CA16C  0x021CA16C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021CA154(u8 *, int);
extern void func_021CA16C(u8 *, int);

void func_021CA184(u8 *p, int a, int b)
{
    func_021CA154(p, b);
    func_021CA16C(p, a);
}
