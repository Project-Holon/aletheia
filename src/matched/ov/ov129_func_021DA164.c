/*
 * function: WF2DMAP_SCENE_SetCellFlags
 * address:  0x021DA164
 * packet:   pkt_021DA164
 * region:   ov129
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj10501.h"

void WF2DMAP_SCENE_SetCellFlags(void *p)
{
    unsigned char *b = (unsigned char *)p;
    int i;

    for (i = 0; i < ((struct Obj10501 *)b)->f23C; i++)
    {
        if (i >= ((struct Obj10501 *)b)->f248 && i < ((struct Obj10501 *)b)->f24C)
            *(int *)(b + i * 0x1c + 8) = 1;
        else
            *(int *)(b + i * 0x1c + 8) = 0;
    }
}
