/*
 * function: FIELD_CAMERA_StartFreeMove
 * address:  0x0218F930
 * packet:   pkt_ov021_0218F930
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   FIELD_CAMERA_TakeView  0x0218F780  thumb  ov021
 *   FIELD_CAMERA_UpdateFreeMove  0x0218FC80  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07424.h"
#include "../include/Obj19572.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 w[3]; } B12;
typedef struct { u32 w[6]; } B24;

extern void FIELD_CAMERA_SetMode(u8 *p, u32 v);
extern void FIELD_CAMERA_TakeView(u8 *p, u8 *q);
extern void FIELD_CAMERA_UpdateFreeMove(u8 *p);

void FIELD_CAMERA_StartFreeMove(u8 *p, u8 *a, u8 *b, u32 *c, u16 v)
{
    u8 *q;
    B24 loc;
    if (p) {
        q = p + 0xf0;
        FIELD_CAMERA_SetMode(p, 2);
        FIELD_CAMERA_TakeView(p, q + 0x34);
        *(B12 *)(q + 0x64) = *(B12 *)a;
        *(B12 *)(q + 0x70) = *(B12 *)b;
        ((struct Obj07424 *)q)->f96 = 0;
        ((struct Obj07424 *)q)->f94 = v;
        loc.w[5] = c[5];
        loc.w[1] = 0;
        loc.w[4] = c[4];
        loc.w[2] = 0;
        loc.w[3] = 0;
        loc.w[0] = c[0];
        *(B24 *)(q + 0xa0) = loc;
        ((struct Obj19572 *)p)->f1AC = (void *)FIELD_CAMERA_UpdateFreeMove;
        ((struct Obj07424 *)q)->fB8 = 0;
        ((struct Obj07424 *)q)->f9C = 1;
    }
}
