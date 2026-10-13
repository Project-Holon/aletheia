/*
 * function: FIELD_CAMERA_LoadSetting
 * address:  0x0218E18C
 * packet:   pkt_ov021_0218E18C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_CAMERA_ReadSetting  0x0218E260  thumb ov021
 *   FIELD_CAMERA_SetG3dRoll  0x0218EC7C  thumb ov021
 *   FIELD_CAMERA_SetG3dScale  0x0218EC68  thumb ov021
 *   G3D_SYSTEM_SetSwapBuffersMode  0x02046BE0  arm
 *   G3D_CAMERA_GetMode  0x02048B78  arm
 *   G3D_CAMERA_SetNearClip  0x02048B80  arm
 *   G3D_CAMERA_SetFarClip  0x02048B94  arm
 *   FX_SinCosTable_   0x020A1B38  data
 */
#include "../include/Obj01347.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    int a;
    int b;
    int c;
    int d;
    u8 e;
    u8 mode;
    u16 ang;
    int f;
    int g;
    int has;
    Vec v;
} Info;

extern void FIELD_CAMERA_ReadSetting(void *p, void *dst);
extern void FIELD_CAMERA_SetG3dRoll(u8 *a, unsigned int first, ...);
extern void FIELD_CAMERA_SetG3dScale(u8 *a, unsigned int first, ...);
typedef unsigned int   u32;
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);
struct Light;
extern int G3D_CAMERA_GetMode(struct Light *l);
extern void G3D_CAMERA_SetNearClip(struct Light *l, u32 v);
extern void G3D_CAMERA_SetFarClip(struct Light *l, u32 v);
extern s16 FX_SinCosTable_[];

void FIELD_CAMERA_LoadSetting(char *p, Vec *src)
{
    Info info;

    FIELD_CAMERA_ReadSetting(p, &info);
    ((struct Obj01347 *)p)->f7C = info.a << 12;
    ((struct Obj01347 *)p)->f78 = info.b;
    ((struct Obj01347 *)p)->f7A = info.c;
    ((struct Obj01347 *)p)->f80 = info.ang;
    FIELD_CAMERA_SetG3dRoll((u8 *)p, info.g);
    FIELD_CAMERA_SetG3dScale((u8 *)p, info.f);
    switch (info.mode) {
    case 0:
        G3D_SYSTEM_SetSwapBuffersMode(0, 0);
        break;
    case 1:
        G3D_SYSTEM_SetSwapBuffersMode(0, 1);
        break;
    }
    if (G3D_CAMERA_GetMode((struct Light *)(((struct Obj01347 *)p)->fC)) == 0) {
        G3D_CAMERA_SetNearClip((struct Light *)(((struct Obj01347 *)p)->fC), FX_SinCosTable_[(((struct Obj01347 *)p)->f80 >> 4) * 2]);
        G3D_CAMERA_SetFarClip((struct Light *)(((struct Obj01347 *)p)->fC), FX_SinCosTable_[(((struct Obj01347 *)p)->f80 >> 4) * 2 + 1]);
    }
    if (info.has != 0) {
        *(Vec * *)&((struct Obj01347 *)p)->f18 = src;
        *(Vec * *)&((struct Obj01347 *)p)->f1C = src;
        *(Vec *)(p + 0x48) = *src;
        *(Vec *)(p + 0x60) = info.v;
    } else {
        *(Vec * *)&((struct Obj01347 *)p)->f18 = 0;
        *(Vec * *)&((struct Obj01347 *)p)->f1C = 0;
        *(Vec *)(p + 0x48) = info.v;
        ((Vec *)(p + 0x60))->x = 0;
        ((Vec *)(p + 0x60))->y = 0;
        ((Vec *)(p + 0x60))->z = 0;
    }
}
