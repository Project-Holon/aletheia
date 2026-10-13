/*
 * function: FIELD_G3D_MAP_SetPlacedModels
 * address:  0x021693C4
 * packet:   pkt_ov010_021693C4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov021 FIELD_G3D_MAPPER_Setup.
 */
#include "../include/Obj19039.h"

void FIELD_G3D_MAP_SetPlacedModels(char *p, int v)
{
    ((struct Obj19039 *)p)->f98 = v;
}
