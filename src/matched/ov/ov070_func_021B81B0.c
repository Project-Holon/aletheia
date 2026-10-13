/*
 * function: ITEMMENU_GetPocketSortFlag
 * address:  0x021B81B0
 * packet:   pkt_ov070_021B81B0
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to ITEMMENU_PocketToSortFlag.
 *
 * symbols:
 *   ITEMMENU_PocketToSortFlag  0x021BB368  thumb  ov070
 */

int ITEMMENU_GetPocketSortFlag(int x)
{
    int ITEMMENU_PocketToSortFlag(int);
    return ITEMMENU_PocketToSortFlag(x);
}
