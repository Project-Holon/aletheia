/*
 * function: FLDEFF_GYOE_InitResource
 * address:  0x021BB4BC
 * packet:   pkt_ov021_021BB4BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   sGyoeResIds     0x021D9A6C  data  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02715.h"

typedef unsigned int u32;
typedef unsigned short u16;

typedef unsigned char  u8;
extern u32 FIELD_EFFECT_GetArcHandle(u8 *p);
extern void *G3D_SYSTEM_CreateResourceArcHandle(u32 a0, u32 a1);
extern int G3D_SYSTEM_TransVramTexture(int *self);
extern void *G3D_SYSTEM_CreateRender(void *a0, u32 n, void *a2);
extern void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2);
extern u32 sGyoeResIds[];

void FLDEFF_GYOE_InitResource(u32 *p)
{
    u32 h = FIELD_EFFECT_GetArcHandle((u8 *)p[0]);
    int i;

    for (i = 0; i < 4; i++) {
        p[1 + i] = (u32)G3D_SYSTEM_CreateResourceArcHandle(h, sGyoeResIds[i]);
        G3D_SYSTEM_TransVramTexture((int *)p[1 + i]);
        p[5 + i] = (u32)G3D_SYSTEM_CreateRender((void *)p[1 + i], 0, (void *)p[1 + i]);
        p[9 + i] = (u32)G3D_SYSTEM_CreateObject(p[5 + i], 0, 0);
    }
    ((struct Obj02715 *)p)->f34 = 4;
}
