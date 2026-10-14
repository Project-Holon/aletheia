/*
 * function: BTLV_MCSS_FindSpriteIndex
 * address:  0x022019F4
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_MCSS_FindSpriteIndex   0x022019F4  thumb
 *   BODY

 *
 * lane O10 candidate
 */
#include "../include/Obj12236.h"

int BTLV_MCSS_FindSpriteIndex(char *p, int key)
{
    int i;

    for (i = 0; i < 14; i++) {
        char *e = p + i * 0x5c;

        if (((struct Obj12236 *)e)->f8 != 0 && key == ((struct Obj12236 *)e)->f50)
            return i;
    }
    return -1;
}

