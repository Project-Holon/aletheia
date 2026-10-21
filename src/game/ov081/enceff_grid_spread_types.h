#ifndef OV081_ENCEFF_GRID_SPREAD_TYPES_H
#define OV081_ENCEFF_GRID_SPREAD_TYPES_H

#include "../types.h"

/* The includer must include ../ov077/enceff_base_types.h and ../ov077/enceff_grid_types.h first. */

/*
 * Encounter effect of overlay 0x51: cells start in waves that spread from three
 * seed cells to their four neighbours (a flood fill over the cell grid), each
 * started cell slides sideways while it turns. In the step state of the grid
 * library, nextCell counts the cells started so far.
 *
 * The flood state is laid over the library's reserved area at 0x300C. It is
 * longer than that area: it covers the library fields at 0x3070..0x3078 and
 * ends beyond the 0x307C bytes that the library allocates, so the code relies
 * on the waves staying small.
 */
typedef struct EncEffSpreadState {
    u16 wave[0x60];                     /* 0x00 cells of the current wave */
    u16 next[0x60];                     /* 0xC0 cells queued for the next wave */
    u16 waveCount;                      /* 0x180 */
    u16 nextCount;                      /* 0x182 */
} EncEffSpreadState;

#define ENCEFF_SPREAD_STATE(work) ((EncEffSpreadState *)(work)->reserved300C)

#endif
