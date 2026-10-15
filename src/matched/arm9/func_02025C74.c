/*
 * function: CURSOR_MOVE_GetTableValue
 * address:  0x02025C74
 * packet:   pkt_02025C74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gCursorMoveTable  0x0209FB18  data
 *
 * Halfword accessor over the 0x10-entry table of 4-byte records at
 * 0x0209FB18 (u16, u8, u8; CURSOR_MOVE_GetTableKind reads the u8 at +2, CURSOR_MOVE_GetTableGroup
 * the one at +3); out of range returns 0xB.  Seeded from ov019 0x0217AE76
 * and ov021 0x021CFCD6.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u16 gCursorMoveTable[];

u32 CURSOR_MOVE_GetTableValue(u32 x)
{
    if (x >= 0x10u)
        return 0xB;
    return gCursorMoveTable[x * 2];
}
