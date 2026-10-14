/*
 * function: GRAPHTABLE_FindEntry
 * address:  0x021C26AC
 * packet:   pkt_ov217_021C26AC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Const base pointer, i declared before e, e assigned in its own statement.
 *
 * symbols:
 *   GRAPHTABLE_FindGroup  0x021C2684  thumb  ov217
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 GRAPHTABLE_FindGroup(void *p, u32 v);

u32 GRAPHTABLE_FindEntry(const u8 *p, u8 unused, u8 key)
{
    s32 i;
    const u8 *e;
    e = p + 4 + GRAPHTABLE_FindGroup((void *)p, unused) * 0xd4;
    for (i = 0; i < e[1]; i++) {
        if (key == *(u16 *)(e + 8 + i * 0xc))
            return (u8)i;
    }
    return 0;
}
