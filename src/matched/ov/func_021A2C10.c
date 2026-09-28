/*
 * function: func_021A2C10
 * address:  0x021A2C10
 * packet:   pkt_021A2C10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void func_0204B3B4(u32 v);

void func_021A2C10(u8 *p)
{
    u32 v = *(u32 *)(p + 4);
    if (v != 0) {
        func_0204B3B4(v);
        *(u32 *)(p + 4) = 0;
    }
}
