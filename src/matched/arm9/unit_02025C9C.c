/*
 * unit:     yes
 * function: CURSOR_MOVE_GetTableKind, CURSOR_MOVE_FindTableGroupIndex
 * address:  0x02025C9C
 * packet:   pkt_02025C9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gCursorMoveTable  0x0209FB18  data
 *   d_0209FB1A  0x0209FB1A  data
 *
 * Two more leaves over the 0x10-entry table of 4-byte records at 0x0209FB18
 * (see CURSOR_MOVE_GetTableValue and CURSOR_MOVE_GetTableGroup): the byte at +2 of entry x (2 when
 * out of range), and the index of the first entry whose byte at +3 equals v
 * (0 when none does).  Seeded from ov111 0x021C6216 and ov116 0x021D6AAC.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 d_0209FB1A[];
extern u8 gCursorMoveTable[];

u32 CURSOR_MOVE_GetTableKind(u32 x)
{
    if (x >= 0x10u)
        return 2;
    return d_0209FB1A[x * 4];
}

u32 CURSOR_MOVE_FindTableGroupIndex(u32 v)
{
    u32 i;

    for (i = 0; i < 0x10; i++) {
        if (v == gCursorMoveTable[i * 4 + 3])
            return i;
    }
    return 0;
}
