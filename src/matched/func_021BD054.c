/*
 * function: func_021BD054
 * address:  0x021BD054
 * packet:   pkt_021BD054
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
 *   func_02045C04  0x02045C04  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void func_02045C04(u32 v);

void func_021BD054(u8 *p)
{
    u32 v = *(u32 *)(p + 20);
    if (v != 0) {
        func_02045C04(v);
        *(u32 *)(p + 20) = 0;
    }
}
