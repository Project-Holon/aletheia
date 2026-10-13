/*
 * function: func_021F8498
 * address:  0x021F8498
 * packet:   pkt_021F8498
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_UTIL_LoadMemberWithSize  0x0204A298  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int ARC_UTIL_LoadMemberWithSize(int a0, int a1, int a2, int a3, u32 *out);

u16 *func_021F8498(u32 heap, u32 unused, u32 *count)
{
    u32 size;
    u16 *list;

    list = (u16 *)ARC_UTIL_LoadMemberWithSize(0x62, 5, 0, (u16)heap, &size);
    *count = size / 2;
    return list;
}
