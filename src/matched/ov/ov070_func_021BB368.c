/*
 * function: ITEMMENU_PocketToSortFlag
 * address:  0x021BB368
 * packet:   pkt_ov070_021BB368
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (no lr push) called by ITEMMENU_UpdateSideButtonsForMode.
 */

int ITEMMENU_PocketToSortFlag(int x)
{
    switch (x) {
    case 0:
        return 10;
    case 3:
        return 13;
    case 1:
        return 11;
    case 2:
        return 12;
    case 4:
        return 14;
    }
    return x;
}
