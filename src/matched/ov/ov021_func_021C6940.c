/*
 * function: FIELD_G3DOBJ_FreeResource
 * address:  0x021C6940
 * packet:   pkt_ov021_021C6940
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
 *   func_02082C60  0x02082C60  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01866.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Tagged;
extern int G3D_SYSTEM_FreeVramTexture(u32 *p);
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);
extern void func_02082C60(void *p, int v, int n);

void FIELD_G3DOBJ_FreeResource(u8 *p)
{
    int i;
    u8 f = p[0x29];

    p[0x29] = 0;
    if (f == 1) {
        if (((struct Obj01866 *)p)->f4 != 0)
            G3D_SYSTEM_FreeVramTexture((u32 *)(((struct Obj01866 *)p)->f4));
        else if (((struct Obj01866 *)p)->f0 != 0)
            G3D_SYSTEM_FreeVramTexture((u32 *)(((struct Obj01866 *)p)->f0));
    }
    if (((struct Obj01866 *)p)->f4 != 0)
        G3D_SYSTEM_DeleteResource((struct Tagged *)(((struct Obj01866 *)p)->f4));
    if (((struct Obj01866 *)p)->f0 != 0)
        G3D_SYSTEM_DeleteResource((struct Tagged *)(((struct Obj01866 *)p)->f0));
    if (p[0x28] != 0) {
        for (i = 0; i < p[0x28]; i++)
            G3D_SYSTEM_DeleteResource((struct Tagged *)(*(u32 *)(p + 8 + i * 4)));
    }
    func_02082C60(p, 0, 0x2c);
    p[0x29] = 1;
}
