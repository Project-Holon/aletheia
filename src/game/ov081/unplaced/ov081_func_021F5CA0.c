/*
 * function: func_021F5CA0
 * address:  0x021F5CA0
 * packet:   pkt_ov081_021F5CA0
 * region:   ov081
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
#include "../unit_021F5A80_types.h"

void func_021F5CA0(EncEffGridWork *work)
{
    int i;
    EncEffGridStepState *step = &work->step;
    EncEffSpreadState *spread = ENCEFF_SPREAD_STATE(work);

    for (i = 0; i < spread->nextCount; i++) {
        EncEffGridCell *cell = &work->cell[spread->next[i]];

        if (cell->active == 0) {
            cell->active = 1;
            step->nextCell++;
            cell->velocityX = 0x1000;
            spread->wave[i] = spread->next[i];
        }
    }
    spread->waveCount = spread->nextCount;
    spread->nextCount = 0;
}
