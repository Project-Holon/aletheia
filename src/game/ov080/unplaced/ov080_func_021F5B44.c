/*
 * function: ENCEFF_UpdateGridColumnFlipCell
 * address:  0x021F5B44
 * packet:   pkt_ov080_021F5B44
 * region:   ov080
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

int ENCEFF_UpdateGridColumnFlipCell(EncEffGridCell *cell)
{
    if (cell->phase < 0x40) {
        cell->angleY += 0x200;
        cell->phase++;
    } else {
        cell->finished = 1;
    }
    return cell->finished;
}
