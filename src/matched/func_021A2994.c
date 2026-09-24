/*
 * function: func_021A2994
 * address:  0x021A2994
 * packet:   pkt_021A2994
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
 *   func_02049238  0x02049238  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void func_02049238(u32 v);

void func_021A2994(u8 *p)
{
    u32 v = *(u32 *)(p + 16);
    if (v != 0) {
        func_02049238(v);
        *(u32 *)(p + 16) = 0;
    }
}
