/*
 * function: MYSTERY_DATA_SaveStart
 * address:  0x0200A2B8
 * packet:   pkt_0200A2B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocker:  021DFDC0 - overlay call with no branch anywhere in the image outside this range (ov228 carries a SAVE_OUTSIDE_Prepare label, so the region hint is satisfiable, but part 3 of attest_overlay_label has no site).  All 30 bytes right.
 * symbols:
 *   SAVE_OUTSIDE_Prepare    0x021DFDC0  thumb
 *   MYSTERY_DATA_IsMainSave  0x0200A350  thumb
 *   GAME_DATA_SaveStart  0x02012DAC  thumb
 */
#include "../include/Obj15586.h"

typedef unsigned char u8;

struct Obj;
extern int MYSTERY_DATA_IsMainSave(struct Obj *a0);
extern void  SAVE_OUTSIDE_Prepare(void *p);
extern int GAME_DATA_SaveStart(int a0);

void MYSTERY_DATA_SaveStart(void *a0, int a1)
{
    if (MYSTERY_DATA_IsMainSave(a0) == 0) {
        SAVE_OUTSIDE_Prepare(((struct Obj15586 *)a0)->f8);
    } else {
        GAME_DATA_SaveStart(a1);
    }
}
