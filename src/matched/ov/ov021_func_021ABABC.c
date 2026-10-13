/*
 * function: FLD_SCENEAREA_LOADER_ApplyStripCamera
 * address:  0x021ABABC
 * packet:   pkt_ov021_021ABABC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLD_SCENEAREA_GetCamera  0x021AB760  thumb
 *   FIELD_CAMERA_EnterMode  0x0218E124  thumb
 *   FLD_SCENEAREA_LOADER_GetStripProgress  0x021ABBA0  thumb
 *   FX_Div         0x0207C768  arm
 *   _ll_mul        0x0209C054  arm
 *   FIELD_CAMERA_SetPitch  0x0218ED34  thumb
 *   FIELD_CAMERA_SetYaw  0x0218ED48  thumb
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb
 */
#include "../include/Obj00757.h"

typedef unsigned short u16;
typedef long long s64;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 FLD_SCENEAREA_GetCamera(u8 *p);
extern void FIELD_CAMERA_EnterMode(u8 *a, u32 s);
extern void FLD_SCENEAREA_LOADER_GetStripProgress(const u16 *r, void *v, int *o1, int *o2);
extern int FX_Div(int a, int b);
extern void FIELD_CAMERA_SetPitch(u8 *p, u16 v);
extern void FIELD_CAMERA_SetYaw(u8 *p, u32 v);
extern void FIELD_CAMERA_SetDistance(u8 *p, u32 v);

/*
 * const on p lets the three loads from p schedule above the store of t to the
 * address-taken d (docs/idioms/a-const-parameter-hoists-field-loads-above-a-
 * call-result-store-into-an-address-taken-local.md). One reused temporary v
 * keeps the quotient on the left of each add and stops x and y being
 * forward-substituted into their calls; z, the last, is.
 */
void FLD_SCENEAREA_LOADER_ApplyStripCamera(int a0, const u16 *p, void *q)
{
    int h = FLD_SCENEAREA_GetCamera((u8 *)a0);
    int s;
    int d;
    int t;
    int x, y, z;
    int v;

    FIELD_CAMERA_EnterMode((u8 *)h, 0);
    FLD_SCENEAREA_LOADER_GetStripProgress(p, q, &s, &d);
    d = t = FX_Div(d, s);
    v = p[10] - p[6];
    v = v * t / 4096;
    x = v + p[6];
    v = p[11] - p[7];
    v = v * t / 4096;
    y = v + p[7];
    v = *(const int *)&((struct Obj00757 *)p)->f18 - *(const int *)&((struct Obj00757 *)p)->f10;
    v = (int)(((s64)v * t + 0x800) >> 12);
    z = v + *(const int *)&((struct Obj00757 *)p)->f10;
    FIELD_CAMERA_SetPitch((u8 *)h, x);
    FIELD_CAMERA_SetYaw((u8 *)h, (u16)y);
    FIELD_CAMERA_SetDistance((u8 *)h, z);
}
