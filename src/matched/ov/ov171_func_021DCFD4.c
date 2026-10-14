/*
 * function: DENDOU_VIEW_StateWaitButton
 * address:  0x021DCFD4
 * packet:   pkt_021DCFD4
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DENDOU_VIEW_IsActorAnimActive  0x021DE0AC  thumb  ov171
 */
#include "../include/Obj14288.h"
typedef unsigned int u32;

extern int DENDOU_VIEW_IsActorAnimActive(int *p, int i);

u32 DENDOU_VIEW_StateWaitButton(char *p)
{
    if (DENDOU_VIEW_IsActorAnimActive((int *)p, ((struct Obj14288 *)p)->fC64) == 0)
        return ((struct Obj14288 *)p)->fC68;
    return 3;
}
