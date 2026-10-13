/*
 * function: UNION_EFF_ExitIconGroup
 * address: 0x0217FBD0
 * packet: pkt_ov019_0217FBD0
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_SYSTEM_FreeVramTexture 0x020470D0 arm
 *   G3D_SYSTEM_DeleteResource 0x02046EFC arm
 */
#include "../include/Obj04971.h"

typedef unsigned int u32;
struct Tagged;
extern int G3D_SYSTEM_FreeVramTexture(u32 *p);
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);
void UNION_EFF_ExitIconGroup(char *p)
{
    G3D_SYSTEM_FreeVramTexture(*(u32 * *)&((struct Obj04971 *)p)->fC8);
    G3D_SYSTEM_FreeVramTexture(*(u32 * *)&((struct Obj04971 *)p)->fCC);
    G3D_SYSTEM_DeleteResource(*(struct Tagged * *)&((struct Obj04971 *)p)->fC8);
    G3D_SYSTEM_DeleteResource(*(struct Tagged * *)&((struct Obj04971 *)p)->fCC);
    *(u32 *)&((struct Obj04971 *)p)->fC8=0;
    *(u32 *)&((struct Obj04971 *)p)->fCC=0;
}
