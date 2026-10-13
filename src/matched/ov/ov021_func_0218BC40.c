/*
 * function: FIELD_BUILDMODEL_CreateG3dResources
 * address:  0x0218BC40
 * packet:   pkt_ov021_0218BC40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_CreateResourceArc  0x02046DB8  arm
 *   FIELD_G3D_MAPPER_TintTexture  0x0218D0D8  thumb  ov021
 *   G3D_SYSTEM_TransVramTextureAndCut  0x020470A8  arm
 */
#include "../include/Obj00572.h"

typedef unsigned int   u32;
void *G3D_SYSTEM_CreateResourceArc(u32 a0, u32 a1);
int FIELD_G3D_MAPPER_TintTexture(void *a, void *b);
u32 G3D_SYSTEM_TransVramTextureAndCut(void *p);

/* The trailing guard is the function exit: only its cmp survives. */
void FIELD_BUILDMODEL_CreateG3dResources(unsigned char *p, int a, int b, int c)
{
    ((struct Obj00572 *)p)->f1D0 = (int)G3D_SYSTEM_CreateResourceArc(a, b);
    if (c != 0)
        FIELD_G3D_MAPPER_TintTexture((void *)(((struct Obj00572 *)p)->f1D0), (void *)c);
    if (G3D_SYSTEM_TransVramTextureAndCut((void *)(((struct Obj00572 *)p)->f1D0)) == 0)
        return;
}
