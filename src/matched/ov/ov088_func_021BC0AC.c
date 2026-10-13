/*
 * function: STARTMENU_BeginSelectAnim
 * address:  0x021BC0AC
 * packet:   pkt_ov088_021BC0AC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf after STARTMENU_BeginFadeIn (function_starts seed); called by
 * STARTMENU_StateSelectRow.
 */
#include "../include/Obj00271.h"

typedef unsigned char u8;

int STARTMENU_BeginSelectAnim(char *p, int v)
{
    ((struct Obj00271 *)p)->f12E = 0;
    ((struct Obj00271 *)p)->f12D = 0;
    ((struct Obj00271 *)p)->f140 = v;
    return 3;
}
