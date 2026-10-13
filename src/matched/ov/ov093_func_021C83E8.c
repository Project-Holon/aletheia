/*
 * function: BTL_SERVER_FLOW_TryAddMainCounter
 * address: 0x021C83E8
 * packet: pkt_ov093_021C83E8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: Original loads r1 for BTL_SERVER_AddMainCounter even though its body ignores it.
 * symbols:
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_SERVER_AddMainCounter 0x021BB908 thumb ov093
 */
#include "../include/Obj13342.h"
extern void *BTL_MAIN_GetCompetitor(void ***);
extern void BTL_SERVER_AddMainCounter(int *, int);
int BTL_SERVER_FLOW_TryAddMainCounter(unsigned char *p, int i, int b)
{
    if ((unsigned int)BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj13342 *)p)->f4) <= 1) {
        BTL_SERVER_AddMainCounter(*(int * *)&((struct Obj13342 *)p)->f0, i);
        return 1;
    }
    return 0;
}
