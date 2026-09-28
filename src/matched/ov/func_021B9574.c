/*
 * function: func_021B9574
 * address:  0x021B9574
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call passing the field at +0x10.
 *
 * symbols:
 *   func_021BA094  0x021BA094  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021BA094(u32 v);

void func_021B9574(int unused, char *p)
{
    func_021BA094(*(u32 *)(p + 0x10));
}
