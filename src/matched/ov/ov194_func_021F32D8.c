/*
 * function: NAMEIN_GRAPHIC_GetGridAction
 * address:  0x021F32D8
 * packet:   pkt_021F32D8
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj10809.h"

int NAMEIN_GRAPHIC_GetGridAction(char *p, unsigned short *out)
{
    int s = ((struct Obj10809 *)p)->fE8;
    if ((s == 1 || s == 2 || s == 9) && out != 0)
    {
        *out = ((struct Obj10809 *)p)->fFC;
    }
    return ((struct Obj10809 *)p)->fE8;
}
