/*
 * function: FIELD_PLAYER_CORE_GetHorzDirFromKeys
 * address:  0x021A3C3C
 * packet:   pkt_ov021_021A3C3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save): maps a key mask to a direction, 9 for none.
 * Filed as a blocker of ov021 FIELD_PLAYER_CORE_SelectMoveDir.
 */

typedef unsigned int u32;

int FIELD_PLAYER_CORE_GetHorzDirFromKeys(u32 keys)
{
    if (keys & 0x20) {
        return 2;
    }
    if (keys & 0x10) {
        return 3;
    }
    return 9;
}
