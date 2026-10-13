/*
 * function: func_021C8174
 * address:  0x021C8174
 * packet:   pkt_021C8174
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetFieldSituation  0x021B8714  thumb  ov093
 */
#include "../include/Obj18335.h"
#include "../include/Obj18336.h"

char *BTL_MAIN_GetFieldSituation(char **p);

int func_021C8174(int *p)
{
    return ((struct Obj18336 *)((char *)BTL_MAIN_GetFieldSituation((char **)(((struct Obj18335 *)p)->f4))))->f4;
}
