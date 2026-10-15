/*
 * function: BOX2_SEQ_StateCheckTaskMenu
 * address:  0x021E2140
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_IsTaskMenuFinished  0x021DCFC0  thumb  ov170
 *
 * 8 while busy, else the 0x28 field.
 */
#include "../include/Obj00000.h"



extern int BOX2_MAIN_IsTaskMenuFinished(char *p);
int BOX2_SEQ_StateCheckTaskMenu(int p)
{
    if (BOX2_MAIN_IsTaskMenuFinished((char *)p) == 0)
        return ((struct Obj00000 *)p)->f28;
    return 8;
}
