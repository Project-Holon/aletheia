/*
 * function: FIELD_CAMERA_Create
 * address:  0x0218E018
 * packet:   pkt_ov021_0218E018
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   gFieldCameraFileName     0x021DDA28  data  ov021  a4
 *   G3D_CAMERA_GetMode  0x02048B78  arm
 *   G3D_CAMERA_GetFovyCos  0x02048B88  arm
 *   FX_AcosIdx  0x0207D184  arm
 *   func_020490F4  0x020490F4  arm
 *   FIELD_CAMERA_LoadSetting  0x0218E18C  thumb ov021
 *   FIELD_CAMERA_CreateDelay  0x0218EEFC  thumb ov021
 */
#include "../include/Obj00519.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern void *func_02030734(u16, int, int, void *, int);
extern int gFieldCameraFileName;
struct Light;
extern int G3D_CAMERA_GetMode(struct Light *l);
extern void G3D_CAMERA_GetFovyCos(struct Light *l, unsigned int *out);
extern u16 FX_AcosIdx(int a);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void FIELD_CAMERA_LoadSetting(char *p, int a);
typedef unsigned int   u32;
extern void FIELD_CAMERA_CreateDelay(int n, u32 x, u32 flags, u32 heap, void *a);

char *FIELD_CAMERA_Create(int a0, int a1, struct Light *a2, int a3, u16 heap)
{
    int t;
    char *p = func_02030734(heap, 0x1b0, 1, &gFieldCameraFileName, 0x80);
    ((struct Obj00519 *)p)->f10 = a0;
    ((struct Obj00519 *)p)->f14 = a1;
    ((struct Obj00519 *)p)->fC = (int)a2;
    ((struct Obj00519 *)p)->f20 = 0;
    ((struct Obj00519 *)p)->f0 = heap;
    ((struct Obj00519 *)p)->f24 = 0;
    ((struct Obj00519 *)p)->f28 = 0;
    ((struct Obj00519 *)p)->f2C = 0;
    ((struct Obj00519 *)p)->f48 = 0;
    ((struct Obj00519 *)p)->f4C = 0;
    ((struct Obj00519 *)p)->f50 = 0;
    ((struct Obj00519 *)p)->f6C = 0;
    ((struct Obj00519 *)p)->f70 = 0;
    ((struct Obj00519 *)p)->f74 = 0;
    ((struct Obj00519 *)p)->f30 = 0;
    ((struct Obj00519 *)p)->f34 = 0;
    ((struct Obj00519 *)p)->f38 = 0;
    ((struct Obj00519 *)p)->f7A = 0;
    ((struct Obj00519 *)p)->f78 = 0;
    ((struct Obj00519 *)p)->f7C = 0x78;
    ((struct Obj00519 *)p)->fE9 = 1;
    if (G3D_CAMERA_GetMode((struct Light *)a2) == 0) {
        G3D_CAMERA_GetFovyCos(a2, (unsigned int *)(&t));
        ((struct Obj00519 *)p)->f80 = FX_AcosIdx(t);
    }
    ((struct Obj00519 *)p)->f4 = func_020490F4(0x3c, ((struct Obj00519 *)p)->f0);
    ((struct Obj00519 *)p)->f8 = func_020490F4(0x6c, ((struct Obj00519 *)p)->f0);
    ((struct Obj00519 *)p)->fEA = 0xffff;
    FIELD_CAMERA_LoadSetting(p, a3);
    FIELD_CAMERA_CreateDelay(7, 6, 2, heap, p);
    ((struct Obj00519 *)p)->f1AC = 0;
    return p;
}
