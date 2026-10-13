/*
 * function: FLDMMDL_MOVE_AddDirGrid
 * address:  0x02164240
 * packet:   pkt_ov010_02164240
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save, prints as .word data): step one of two
 * halfword coordinates by amt in the direction dir (0 z-, 1 z+, 2 x-, 3 x+).
 * Halfword sibling of the word version FLDMMDL_MOVE_AddDirVector.  Filed as the sole
 * blocker of ov021 FIELD_PLAYER_CORE_FormStepSlot8Done.
 */

typedef signed short s16;

void FLDMMDL_MOVE_AddDirGrid(int dir, s16 *x, s16 *z, s16 amt)
{
    switch (dir) {
    case 0:
        z[0] -= amt;
        break;
    case 1:
        z[0] += amt;
        break;
    case 2:
        x[0] -= amt;
        break;
    case 3:
        x[0] += amt;
        break;
    }
}
