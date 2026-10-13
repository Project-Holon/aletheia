/*
 * function: GIMMICK41_GetFirstAnimeSlot
 * address:  0x021F3F18
 * packet:   pkt_ov041_021F3F18
 * region:   ov041
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An unlabelled leaf (no lr save) next to GIMMICK41_FacingToRingIndex: maps 0..3 to an even
 * index. Callee of GIMMICK41_EventLaunch.
 */

int GIMMICK41_GetFirstAnimeSlot(int x)
{
    switch (x) {
    case 0: return 0;
    case 1: return 2;
    case 2: return 4;
    case 3: return 6;
    }
    return 0;
}
