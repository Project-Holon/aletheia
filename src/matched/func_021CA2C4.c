/*
 * function: func_021CA2C4
 * address:  0x021CA2C4
 * packet:   pkt_021CA2C4
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CA294  0x021CA294  thumb
 *   func_021CA2AC  0x021CA2AC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021CA294(u8 *, int);
extern void func_021CA2AC(u8 *, int);

void func_021CA2C4(u8 *p, int a, int b)
{
    func_021CA294(p, b);
    func_021CA2AC(p, a);
}
