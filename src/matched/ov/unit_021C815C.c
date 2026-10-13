/*
 * unit:     yes
 * function: func_021C815C, func_021C8168
 * address:  0x021C815C
 * packet:   pkt_021C815C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two tail thunks forwarding p->field4 to distinct callees.
 *
 * symbols:
 *   BTL_MAIN_GetRule  0x021B8588  thumb  ov093
 *   BTL_MAIN_GetCompetitor  0x021B86B8  thumb  ov093
 */
#include "../include/Obj26329.h"
#include "../include/Obj26330.h"

typedef unsigned int   u32;
extern u32 BTL_MAIN_GetRule(void **p);
extern void *BTL_MAIN_GetCompetitor(void ***p);

int func_021C815C(int *p)
{
    return BTL_MAIN_GetRule((void **)(((struct Obj26329 *)p)->f4));
}

void func_021C8168(int *p)
{
    BTL_MAIN_GetCompetitor((void ***)(((struct Obj26330 *)p)->f4));
}
