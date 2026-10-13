/*
 * function: FLDMMDL_MOVE_GetDirFromPoints
 * address:  0x021642B4
 * packet:   pkt_ov010_021642B4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (word run in the listing), blocker of FLDMMDL_MOVECODE_GetSightDirToPlayer and
 * FLDMMDL_MOVE_TurnToPlayer (ov021).  Direction code 0..3 from a point pair.
 */

typedef unsigned short u16;

u16 FLDMMDL_MOVE_GetDirFromPoints(int x0, int y0, int x1, int y1)
{
    int r;

    if (x0 > x1) {
        return 2;
    }
    if (x0 < x1) {
        return 3;
    }
    r = 1;
    if (y0 > y1) {
        r = 0;
    }
    return r;
}
