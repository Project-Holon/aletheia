/*
 * function: func_021F5B24
 * address:  0x021F5B24
 * packet:   pkt_ov079_021F5B24
 * region:   ov079
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

#include "../../ov077/enceff_base_types.h"
#include "../../ov077/enceff_grid_types.h"

/*
 * Cell callback of the block flip: the cell turns one full turn about its Y
 * axis (phase 0), then half a turn more (phase 1) to show its back, then is
 * done. Angles are 16 bit angles << 4.
 */
int func_021F5B24(EncEffGridCell *cell)
{
    int phase = cell->phase;

    if (phase < 1) {
        s32 *angle = &cell->angleY;  /* the pointer changes the code (kept as the original) */
        int next = cell->angleY + 0x1000;

        cell->angleY = next;
        if (next >= 0x10000) {
            *angle = next - 0x10000;
            cell->phase = phase + 1;
        }
    } else if (phase == 1) {
        int next = cell->angleY + 0x1000;

        cell->angleY = next;
        if (next >= 0x8000) {
            cell->angleY = 0x8000;
            cell->phase = phase + 1;
        }
    } else {
        cell->finished = 1;
    }
    return cell->finished;
}
