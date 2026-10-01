/*
 * function: func_021A0170
 * address:  0x021A0170
 * packet:   pkt_ov021_021A0170
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207DC44  0x0207DC44  arm
 *   func_0207DD10  0x0207DD10  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void func_0207DC44(u32, u32, u32, u32);
extern void func_0207DD10(u8 *);

static inline void SetFogColor(u16 color, int alpha)
{
    *(volatile u32 *)0x04000358 = (u32)(color | (alpha << 16));
}

void func_021A0170(u8 *p)
{
    if (*(u32 *)(p + 0x40)) {
        func_0207DC44(p[0], p[1], p[2], *(u32 *)(p + 4));
        SetFogColor(*(u16 *)(p + 8), p[3]);
        func_0207DD10(p + 0xc);
        *(u32 *)(p + 0x40) = 0;
    }
}
