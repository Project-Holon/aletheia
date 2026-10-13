/*
 * function: FLD3D_CI_DrawEffect
 * address:  0x021C1C4C
 * packet:   pkt_ov021_021C1C4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   func_020489F4  0x020489F4  arm
 *   func_02048A00  0x02048A00  arm
 *   func_02048A18  0x02048A18  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 */
#include "../include/Obj03141.h"

typedef unsigned char u8;
typedef unsigned short u16;

struct Arg;
struct Light;
void G3D_CAMERA_Reset(struct Light *l);
typedef unsigned int   u32;
u32 func_020489F4(u8 *a0, int i);
u32 func_02048A00(u8 *a0, int i);
u32 func_02048A18(u8 *a0, int i);
void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);

void FLD3D_CI_DrawEffect(char *p)
{
    int a;
    int n;
    int i;
    u8 k;

    if (((struct Obj03141 *)p)->fC == 0)
        G3D_CAMERA_Reset((struct Light *)(((struct Obj03141 *)p)->f4));
    else
        G3D_CAMERA_Reset((struct Light *)(((struct Obj03141 *)p)->f8));
    if (((struct Obj03141 *)p)->f18 != -1) {
        a = (int)func_020489F4((u8 *)(((struct Obj03141 *)p)->f14), (u16)(((struct Obj03141 *)p)->f18));
        n = (int)func_02048A00((u8 *)(((struct Obj03141 *)p)->f14), (u16)(((struct Obj03141 *)p)->f18));
        for (k = 0; k < n; k++) {
            i = (int)func_02048A18((u8 *)(((struct Obj03141 *)p)->f14), (u16)(a + k));
            G3D_SYSTEM_DrawObject((void *)i, (struct Arg *)(p + 0x1c));
        }
    }
}
