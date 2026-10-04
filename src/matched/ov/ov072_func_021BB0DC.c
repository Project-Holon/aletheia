/*
 * unit:     yes
 * function: func_021BB0DC, func_021BB0E0
 * address:  0x021BB0DC
 * packet:   pkt_021BB0DC
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * two int getters at +c, +10.
 */
#include "../include/Obj20782.h"
#include "../include/Obj20783.h"

int func_021BB0DC(void *p)
{
    return ((struct Obj20782 *)p)->fC;
}

int func_021BB0E0(void *p)
{
    return ((struct Obj20783 *)p)->f10;
}
