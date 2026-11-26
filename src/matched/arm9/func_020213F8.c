/*
 * function: ITEM_LookupBallIdPair
 * address:  0x020213F8
 * packet:   pkt_020213F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +0030 ABS32 sItemBallIdTable       : 0209E904 (data, from header) has no witness outside 020213F8..0202142C
 * symbols:
 *   sItemBallIdTable  0x0209E904  data
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u16 sItemBallIdTable[][2];

u16 ITEM_LookupBallIdPair(int a, int b)
{
    u32 i;

    for (i = 0; i < 0x19; i++)
        if (sItemBallIdTable[i][b] == a)
            return sItemBallIdTable[i][b ^ 1];
    return 0;
}
