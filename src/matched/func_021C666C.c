/*
 * function: func_021C666C
 * address:  0x021C666C
 * packet:   pkt_021C666C
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0204B3B4(void *);

void func_021C666C(u8 *p, int i)
{
    if (*(u32 *)(p + 0x1f0 + i * 4)) {
        func_0204B3B4(*(void **)(p + 0x1f0 + i * 4));
        *(u32 *)(p + 0x1f0 + i * 4) = 0;
    }
}
