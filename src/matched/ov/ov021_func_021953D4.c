/*
 * function: TALKMSGWIN_SetupCamera
 * address:  0x021953D4
 * packet:   pkt_ov021_021953D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VEC_Subtract  0x0207CA00  arm
 *   G3D_CAMERA_SetEye  0x02048AFC  arm
 *   G3D_CAMERA_SetTarget  0x02048B20  arm
 *   G3D_CAMERA_SetUp  0x02048B44  arm
 *   G3D_CAMERA_SetScale  0x02048B60  arm
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   G3i_LookAt_  0x0207D7C4  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01351.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

extern void VEC_Subtract(u8 *a, u8 *b, V *c);
extern void G3D_CAMERA_SetEye(u32 o, V *a);
extern void G3D_CAMERA_SetTarget(u32 o, V *a);
extern void G3D_CAMERA_SetUp(u32 o, V *a);
struct Light;
extern void G3D_CAMERA_SetScale(struct Light *l, const u32 *in);
struct Light;
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3i_LookAt_(V *a, V *b, V *c, int d, int e);

void TALKMSGWIN_SetupCamera(u8 *p, int m)
{
    V t;
    V a;
    V b;
    V c;
    int f;

    VEC_Subtract(p + 0xCA0, p + 0xCB8, &t);
    a.x = t.x;
    a.y = t.y;
    a.z = t.z;
    b.x = 0;
    b.y = 0x1000;
    b.z = 0;
    c.x = 0;
    c.y = 0;
    c.z = 0;
    if (m == 0) {
        f = 0x40000;
        if (((struct Obj01351 *)p)->fCC4 >= f)
            f = ((struct Obj01351 *)p)->fCC4 + 0x1000;
        G3D_CAMERA_SetEye(((struct Obj01351 *)p)->f4, &a);
        G3D_CAMERA_SetTarget(((struct Obj01351 *)p)->f4, &b);
        G3D_CAMERA_SetUp(((struct Obj01351 *)p)->f4, &c);
        G3D_CAMERA_SetScale((struct Light *)(((struct Obj01351 *)p)->f4), (const u32 *)(&f));
        G3D_CAMERA_Reset((struct Light *)(((struct Obj01351 *)p)->f4));
        return;
    }
    G3i_LookAt_(&a, &b, &c, 1, 0);
}
