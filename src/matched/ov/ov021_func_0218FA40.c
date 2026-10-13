/*
 * function: FIELD_CAMERA_StartMoveToSetting
 * address:  0x0218FA40
 * packet:   pkt_ov021_0218FA40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sibling of FIELD_CAMERA_StartMoveToSaved/FIELD_CAMERA_StartFreeMove: arms the +0xf0 motion block with
 * FIELD_CAMERA_UpdateMove as the per-frame callback, seeded from FIELD_CAMERA_ReadSetting's record.
 * The two +0x70 copies are tail-merged by the compiler (a shared source
 * pointer variable compiles the same).
 *
 * symbols:
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   FIELD_CAMERA_TakeView  0x0218F780  thumb  ov021
 *   FIELD_CAMERA_ReadSetting  0x0218E260  thumb  ov021
 *   FIELD_CAMERA_UpdateMove  0x0218FB1C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01117.h"
#include "../include/Obj12597.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef struct { u32 w[3]; } B12;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
    u16 pad0c[3];
    u16 h12;
    u32 pad14[2];
    u32 flag;
    B12 v;
} Rec;

extern void FIELD_CAMERA_SetMode(u8 *p, u32 v);
extern void FIELD_CAMERA_TakeView(u8 *p, u8 *q);
extern void FIELD_CAMERA_ReadSetting(void *p, void *r);
extern void FIELD_CAMERA_UpdateMove(u8 *p);

void FIELD_CAMERA_StartMoveToSetting(u8 *p, u16 v)
{
    u8 *q;
    Rec loc;

    if (p) {
        q = p + 0xf0;
        if (((struct Obj01117 *)q)->f98 != 0 && v != 0) {
            FIELD_CAMERA_SetMode(p, 0);
            FIELD_CAMERA_TakeView(p, q + 0x34);
            FIELD_CAMERA_ReadSetting(p, &loc);
            ((struct Obj01117 *)q)->f88 = loc.b;
            ((struct Obj01117 *)q)->f8A = loc.c;
            ((struct Obj01117 *)q)->f8C = loc.a << 12;
            ((struct Obj01117 *)q)->f90 = loc.h12;
            if (loc.flag != 0) {
                *(B12 *)(q + 0x7c) = loc.v;
                *(B12 *)(q + 0x70) = **(B12 * *)&((struct Obj12597 *)p)->f18;
            } else {
                ((struct Obj01117 *)q)->f7C = 0;
                ((struct Obj01117 *)q)->f80 = 0;
                ((struct Obj01117 *)q)->f84 = 0;
                *(B12 *)(q + 0x70) = loc.v;
            }
            ((struct Obj01117 *)q)->f96 = 0;
            ((struct Obj01117 *)q)->f94 = v;
            ((struct Obj01117 *)q)->fA0 = 1;
            ((struct Obj01117 *)q)->fA4 = 1;
            ((struct Obj01117 *)q)->fA8 = 1;
            ((struct Obj01117 *)q)->fAC = 1;
            ((struct Obj01117 *)q)->fB0 = 1;
            ((struct Obj01117 *)q)->fB4 = 1;
            ((struct Obj12597 *)p)->f1AC = (void *)FIELD_CAMERA_UpdateMove;
            ((struct Obj01117 *)q)->fB8 = 0;
            ((struct Obj01117 *)q)->f9C = 1;
        }
    }
}
