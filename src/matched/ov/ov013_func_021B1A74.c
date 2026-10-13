/*
 * function: VCT_AUDIO_SetLastPacket
 * address:  0x021B1A74
 * packet:   pkt_021B1A74
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   VCT_POOL_FreeFrame  0x021B2FE4  arm  ov013
 *   VCT_AUDIO_PopReadyPacket  0x021B1944  arm  ov013
 */
#include "../include/Obj07348.h"

extern void VCT_POOL_FreeFrame(void *p);
typedef unsigned int   u32;
struct Node;
extern struct Node *VCT_AUDIO_PopReadyPacket(u32 t);

void VCT_AUDIO_SetLastPacket(char *p, int a1)
{
    if (((struct Obj07348 *)p)->f3C)
        VCT_POOL_FreeFrame(((struct Obj07348 *)p)->f3C);
    *(int *)&((struct Obj07348 *)p)->f3C = a1;
    VCT_AUDIO_PopReadyPacket((u32)(((struct Obj07348 *)p)->f34));
}
