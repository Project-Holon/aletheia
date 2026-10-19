/*
 * file:     item_gfx.c
 * unit:     yes
 * function: ITEM_GFX_IsFlagClear, ITEM_GFX_GetItemId, ITEM_GFX_GetExtraValue, ITEM_GFX_GetRowIndex
 * address:  0x0202F114
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from time_icon.c by tools/splitfile.py.
 *
 * symbols:
 *   sItemGfxExtraTable      0x020A03C8  data
 */
#include "comm_player_support_shared_types.h"

/* Entry of the 46-row item graphics extra table. */
struct ItemGfxExtra {
    u16 itemId;
    u16 value;
};

u32 ITEM_GFX_IsFlagClear(const u8 *bits, u32 index);

u16 ITEM_GFX_GetItemId(u32 row);

u32 ITEM_GFX_GetExtraValue(u32 itemId);

u32 ITEM_GFX_GetRowIndex(u16 itemId);

extern struct ItemGfxExtra sItemGfxExtraTable[];

/*
 * Bit `index` of a byte array, inverted: 1 when the bit is clear.
 * Unlabelled leaf in the 0x0202F114..0x0202F190 gap.
 *
 * The byte index and the bit number are both `u8` locals: the original
 * truncates each with its own `lsls #0x18`/`lsrs #0x18` pair, and `i >> 3`
 * or `i & 7` folded into the shift expression loses them (the front end
 * knows both are already in range and drops the conversions).
 */
u32 ITEM_GFX_IsFlagClear(const u8 *bits, u32 index)
{
    u8 byteIndex = (u8)(index >> 3);
    u8 bitIndex = (u8)(index & 7);

    if ((bits[byteIndex] & (1 << bitIndex)) != 0)
        return 0;
    return 1;
}

/*
 * First field (item id) of row `row` of the 0x2E-row item graphics extra
 * table; the sibling lookups ITEM_GFX_GetExtraValue (second field) and ITEM_GFX_GetRowIndex
 * (row index) share it.  All three are unlabelled leaf functions in the
 * 0x0202F114..0x0202F190 gap.
 */
u16 ITEM_GFX_GetItemId(u32 row)
{
    return sItemGfxExtraTable[row].itemId;
}

/*
 * Second field of the row whose item id matches, 0 when there is none.
 */
u32 ITEM_GFX_GetExtraValue(u32 itemId)
{
    s32 i;

    for (i = 0; i < 0x2E; i++) {
        if (sItemGfxExtraTable[i].itemId == itemId)
            return sItemGfxExtraTable[i].value;
    }
    return 0;
}

/*
 * Row index of the entry whose item id matches, 0 when there is none.
 * Unsigned loop here, signed in ITEM_GFX_GetExtraValue.
 */
u32 ITEM_GFX_GetRowIndex(u16 itemId)
{
    u32 i;

    for (i = 0; i < 0x2E; i++) {
        if (sItemGfxExtraTable[i].itemId == itemId)
            return i;
    }
    return 0;
}
