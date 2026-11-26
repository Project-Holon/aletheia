/*
 * function: ITEM_GetBallIdForItem
 * address:  0x0202142C
 * packet:   pkt_020213F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +0008 ABS32 ITEM_LookupBallIdPair          : 020213F8 (thumb, from name) has no witness outside 0202142C..02021438
 *
 * symbols:
 *   ITEM_LookupBallIdPair  0x020213F8  thumb
 */

extern unsigned short ITEM_LookupBallIdPair(int a0, int a1);

unsigned short ITEM_GetBallIdForItem(int a0)
{
    return ITEM_LookupBallIdPair(a0, 0);
}
