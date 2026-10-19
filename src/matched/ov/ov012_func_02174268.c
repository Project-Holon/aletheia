/*
 * function: UNION_SCENE_IsScenePending
 * address: 0x02174268
 * packet: pkt_ov012_02174268
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj00610.h"
typedef unsigned char u8;
int UNION_SCENE_IsScenePending(u8 *p)
{
    if (((struct Obj00610 *)p)->f354C == 0 && ((struct Obj00610 *)p)->f3548 == 0)
        return 0;
    return 1;
}
