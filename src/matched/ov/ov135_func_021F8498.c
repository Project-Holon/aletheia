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
 *   func_0204A298  0x0204A298  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0204A298(u32 archive_id, u32 member, u32 kind, u32 heap, u32 *size);

u16 *func_021F8498(u32 heap, u32 unused, u32 *count)
{
    u32 size;
    u16 *list;

    list = func_0204A298(0x62, 5, 0, (u16)heap, &size);
    *count = size / 2;
    return list;
}
