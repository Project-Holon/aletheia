/*
 * function: BTLV_MCSS_IsAnimPending
 * address:  0x02200494
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_MCSS_IsAnimPending   0x02200494  thumb
 *   BTLV_MCSS_FindSpriteIndex 0x022019F4 thumb ov094

 *
 * lane O10 candidate
 */
#include "../include/Obj12228.h"

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);

int BTLV_MCSS_IsAnimPending(char *p, int key)
{
    int i = BTLV_MCSS_FindSpriteIndex(p, key);
    char *e;

    if (i == -1)
        return 0;
    e = p + i * 0x5c;
    if (((struct Obj12228 *)e)->f8 == 0)
        return 0;
    return ((struct Obj12228 *)e)->f4C;
}

