/*
 * function: OEKAKI_OpenGroup
 * address:  0x02184560
 * packet:   pkt_02184560
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   UNION_APP_OpenLimited  0x02184148  thumb
 */
#include "../include/Obj13027.h"

typedef unsigned int u32;

void UNION_APP_OpenLimited(u32 x, int a);

void OEKAKI_OpenGroup(char *p, int a)
{
    UNION_APP_OpenLimited(*(u32 *)*(u32 * *)&((struct Obj13027 *)p)->f4, a);
}
