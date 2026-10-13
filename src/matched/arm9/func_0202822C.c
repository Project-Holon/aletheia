/*
 * function: APP_TASKMENU_WIN_SetDecide
 * address:  0x0202822C
 * packet:   pkt_0202822C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf setter: stores v at p + 8.
 *
 * symbols:
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 */
#include "../include/Obj15780.h"

void APP_TASKMENU_WIN_SetDecide(char *p, int v)
{
    ((struct Obj15780 *)p)->f8 = v;
}
