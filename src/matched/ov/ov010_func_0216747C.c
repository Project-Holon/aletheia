/*
 * function: SYMBOL_MAP_GetEntryPage20
 * address:  0x0216747C
 * packet:   pkt_ov010_0216747C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * One of the 20-entry pages from index 50.
 *
 * symbols:
 *   SYMBOL_MAP_CopyEntryRange  0x021673E0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry32 {
    u32 id : 11;
    u32 rest : 21;
} Entry32;

extern u8 SYMBOL_MAP_CopyEntryRange(Entry32 *list, Entry32 *out, u32 cap, u32 start, int count);

u16 SYMBOL_MAP_GetEntryPage20(Entry32 *list, Entry32 *out, u32 cap, u32 page, u8 *n)
{
    u16 start;

    start = page * 20 + 50;
    *n = SYMBOL_MAP_CopyEntryRange(list, out, cap, start, 20);
    return start;
}
