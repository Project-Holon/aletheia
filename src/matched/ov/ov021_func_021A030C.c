/*
 * function: func_021A030C
 * address:  0x021A030C
 * packet:   pkt_ov021_021A030C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A380  0x0204A380  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed char    s8;
typedef signed short   s16;
typedef unsigned int   u32;

extern u32 func_0204A380(u32, u16, u32, u32);

void func_021A030C(u8 *p, u32 a)
{
    if (p[0] == 1) {
        ((s8 *)p)[1]--;
        if (((s8 *)p)[1] <= 0) {
            *(u32 *)(p + 4) = func_0204A380(*(u32 *)(p + 0xc), *(u16 *)(p + 2), 0, a);
            p[0] = 0;
        }
    }
}
