/*
 * function: func_021A0568
 * address:  0x021A0568
 * packet:   pkt_ov021_021A0568
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A066C  0x021A066C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void func_021A066C(u8 *p, u32 a, u32 b);

void func_021A0568(u8 *p, int force)
{
    if (*(u32 *)(p + 0x38C) != 0 || force != 0) {
        func_021A066C(p, *(u32 *)(p + 8), *(u32 *)(p + 4));
        *(u32 *)(p + 0x38C) = 0;
    }
}
