/*
 * function: ITEM_IsBerry
 * address:  0x020213C0
 * packet:   pkt_020213C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +001C ABS32 sItemBerryTable       : 0209E968 (data, from header) has no witness outside 020213C0..020213E0
 * symbols:
 *   sItemBerryTable  0x0209E968  data
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u16 sItemBerryTable[];

int ITEM_IsBerry(u32 a)
{
    u32 i;

    for (i = 0; i < 0x40; i++)
        if (sItemBerryTable[i] == a)
            return 1;
    return 0;
}
