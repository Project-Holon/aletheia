/*
 * unit:     yes
 * function: PDC_GetPokedexSave, PDC_GetResult
 * address:  0x021B6154
 * packet:   pkt_ov098_021B6154
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled getters at +0x18 and +0x1c, filed as the blocker of
 * PDC_MAIN_StepIntro (lane S25). tu range is the 8 code bytes only; the
 * listing extent runs on into PDC_ProcInit.
 */
#include "../include/Obj22003.h"
#include "../include/Obj22004.h"

int PDC_GetPokedexSave(void *p)
{
    return ((struct Obj22003 *)p)->f18;
}

int PDC_GetResult(void *p)
{
    return ((struct Obj22004 *)p)->f1C;
}
