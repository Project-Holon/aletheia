/*
 * function: BTLV_MCSS_GetSpriteAttrFlags
 * address:  0x021FFF38
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_MCSS_GetSpriteAttrFlags   0x021FFF38  thumb
 *   BTLV_MCSS_FindSpriteIndex 0x022019F4 thumb ov094

 *
 * lane O10 candidate
 */
#include "../include/Obj12224.h"

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);

int BTLV_MCSS_GetSpriteAttrFlags(char *p, int key)
{
    int i;
    char *e;

    if (key == 0xff)
        return 0;
    i = BTLV_MCSS_FindSpriteIndex(p, key);
    if (i == -1)
        return 0;
    e = p + i * 0x5c;
    if (((struct Obj12224 *)e)->f8 == 0)
        return 0;
    return ((struct Obj12224 *)e)->f48;
}

