/*
 * function: FIELD_CAMERA_SetMoveGoal
 * address:  0x0218F89C
 * packet:   pkt_ov021_0218F89C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   FIELD_CAMERA_UpdateMove  0x0218FB1C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02371.h"
#include "../include/Obj07423.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 w[12]; } B48;
typedef struct { u32 w[6]; } B24;

extern void FIELD_CAMERA_SetMode(u8 *p, u32 v);
extern void FIELD_CAMERA_UpdateMove(u8 *p);

void FIELD_CAMERA_SetMoveGoal(u8 *p, u8 *src, u16 v)
{
    u8 *q;
    if (p) {
        q = p + 0xf0;
        FIELD_CAMERA_SetMode(p, 0);
        *(B48 *)(q + 0x64) = *(B48 *)src;
        ((struct Obj07423 *)q)->f96 = 0;
        ((struct Obj07423 *)q)->f94 = v;
        *(B24 *)(q + 0xa0) = *(B24 *)(src + 0x30);
        ((struct Obj02371 *)p)->f1AC = (void *)FIELD_CAMERA_UpdateMove;
        ((struct Obj07423 *)q)->fB8 = 0;
        ((struct Obj07423 *)q)->f9C = 1;
    }
}
