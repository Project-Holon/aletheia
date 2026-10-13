/*
 * function: FIELD_3DBG_ReleaseTextureVram
 * address:  0x021A1768
 * packet:   pkt_ov021_021A1768
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_TransAllocatedTexture  0x02047204  arm
 */
#include "../include/Obj09547.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Tagged;
u32 G3D_SYSTEM_TransAllocatedTexture(struct Tagged *p);

void FIELD_3DBG_ReleaseTextureVram(u8 *p)
{
    if (p[7] != 0) {
        G3D_SYSTEM_TransAllocatedTexture((struct Tagged *)(((struct Obj09547 *)p)->f8));
        p[7] = 0;
    }
}
