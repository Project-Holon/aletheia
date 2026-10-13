/*
 * function: FLD_SCENEAREA_LOADER_ApplyStripTarget
 * address:  0x021ABC5C
 * packet:   pkt_ov021_021ABC5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLD_SCENEAREA_GetCamera  0x021AB760  thumb ov021
 *   FLD_SCENEAREA_LOADER_GetStripProgress  0x021ABBA0  thumb ov021
 *   FX_Div   0x0207C768  arm
 *   _ll_mul        0x0209C054  arm
 *   FIELD_CAMERA_SetTargetShift  0x0218ECD4  thumb ov021
 */
#include "../include/Obj00757.h"

typedef struct { int x; int y; int z; } V;

typedef unsigned char  u8;
extern unsigned int FLD_SCENEAREA_GetCamera(u8 *p);
extern void FLD_SCENEAREA_LOADER_GetStripProgress(char *p, void *q, int *o1, int *o2);
typedef unsigned int   u32;
extern u32 FX_Div(u32 a, u32 b);
extern void FIELD_CAMERA_SetTargetShift(int a, V *v);

void FLD_SCENEAREA_LOADER_ApplyStripTarget(u8 *a0, char *p, void *q)
{
    int a;
    int s;
    int d;
    V v;
    int dx;
    int dy;
    int dz;

    a = FLD_SCENEAREA_GetCamera(a0);
    FLD_SCENEAREA_LOADER_GetStripProgress(p, q, &s, &d);
    dx = ((struct Obj00757 *)p)->f30 - ((struct Obj00757 *)p)->f24;
    dy = ((struct Obj00757 *)p)->f34 - ((struct Obj00757 *)p)->f28;
    dz = ((struct Obj00757 *)p)->f2C - ((struct Obj00757 *)p)->f20;
    v.x = ((struct Obj00757 *)p)->f20 +
          FX_Div((int)(((long long)dz * d + 0x800) >> 12), s);
    v.y = ((struct Obj00757 *)p)->f24 + FX_Div((int)(((long long)dx * d + 0x800) >> 12), s);
    v.z = ((struct Obj00757 *)p)->f28 + FX_Div((int)(((long long)dy * d + 0x800) >> 12), s);
    FIELD_CAMERA_SetTargetShift(a, &v);
}
