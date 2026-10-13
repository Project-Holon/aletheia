/*
 * function: BTL_MAIN_AddBonusMoney
 * address:  0x021B91E4
 * packet:   pkt_ov093_021B91E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in a .word run.  If bit 3 of p[0x473] is clear,
 * adds `add` to the word at p+0x434 and clamps it to 0x1869f.
 * The bit test is a lsls #0x1c / lsrs #0x1f pair, so the promoted value
 * must stay unsigned.
 */
#include "../include/Obj07745.h"

typedef unsigned char u8;
typedef unsigned int u32;

void BTL_MAIN_AddBonusMoney(void *p, int add)
{
    if (((unsigned int)((struct Obj07745 *)p)->f473 << 28 >> 31) != 0)
        return;
    ((struct Obj07745 *)p)->f434 += add;
    if (((struct Obj07745 *)p)->f434 > 0x1869f)
        ((struct Obj07745 *)p)->f434 = 0x1869f;
}
