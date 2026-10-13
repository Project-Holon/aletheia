/*
 * function: FLDMMDL_AddGridNowY
 * address:  0x0216D860
 * packet:   pkt_ov010_0216D860
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as a blocker of ov021 FLDMMDL_ACMD_StepInit.
 */
#include "../include/Obj19130.h"

void FLDMMDL_AddGridNowY(char *p, short v)
{
    ((struct Obj19130 *)p)->f3E += v;
}
