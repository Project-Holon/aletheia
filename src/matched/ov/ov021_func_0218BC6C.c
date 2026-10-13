/*
 * function: FIELD_BUILDMODEL_DeleteG3dResources
 * address:  0x0218BC6C
 * packet:   pkt_ov021_0218BC6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 */
#include "../include/Obj01114.h"

typedef unsigned int   u32;
struct Tagged;
int G3D_SYSTEM_FreeVramTexture(u32 *p);
void G3D_SYSTEM_DeleteResource(struct Tagged *p);

void FIELD_BUILDMODEL_DeleteG3dResources(unsigned char *p)
{
    if (((struct Obj01114 *)p)->f1D0 != 0) {
        G3D_SYSTEM_FreeVramTexture(((struct Obj01114 *)p)->f1D0);
        G3D_SYSTEM_DeleteResource(((struct Obj01114 *)p)->f1D0);
        ((struct Obj01114 *)p)->f1D0 = 0;
    }
}
