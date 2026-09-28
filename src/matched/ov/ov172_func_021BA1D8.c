/*
 * function: func_021BA1D8
 * address:  0x021BA1D8
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_02072A88 with the field at +0x20.
 *
 * symbols:
 *   func_02072A88  0x02072A88  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02072A88(u32 v);

void func_021BA1D8(void *p)
{
    func_02072A88(*(u32 *)((char *)p + 0x20));
}
