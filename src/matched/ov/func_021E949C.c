/*
 * function: BOX2_SEQ_GotoBox2Main
 * address:  0x021E949C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_SetupWindowFrameFade  0x021DD090  thumb  ov170
 *
 * Forward, then store the third argument at 0x28.
 */
#include "../include/Obj00000.h"



extern void BOX2_MAIN_SetupWindowFrameFade(char *, int);
int BOX2_SEQ_GotoBox2Main(char *p, int a, int b)
{
    BOX2_MAIN_SetupWindowFrameFade(p, a);
    ((struct Obj00000 *)p)->f28 = b;
    return 8;
}
