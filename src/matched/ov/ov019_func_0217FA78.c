/*
 * function: UNION_EFF_UpdateAnimObj
 * address: 0x0217FA78
 * packet: pkt_ov019_0217FA78
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 *   UNION_EFF_DeleteAnimObj 0x0217FA54 thumb ov019
 */
#include "../include/Obj03097.h"

typedef unsigned int u32;
typedef unsigned short u16;
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *p, int idx, int amount);
extern void UNION_EFF_DeleteAnimObj(u32 *p);
void UNION_EFF_UpdateAnimObj(u32 *p)
{
    G3D_SYSTEM_LoopObjectAnimeFrame((void *)p[3], 0, 0x1000);
    (((struct Obj03097 *)p)->f12)++;
    if (((struct Obj03097 *)p)->f12 > 90) UNION_EFF_DeleteAnimObj(p);
}
