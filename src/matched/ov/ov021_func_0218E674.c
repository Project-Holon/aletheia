/*
 * function: FIELD_CAMERA_SetAnglesFromVector
 * address:  0x0218E674
 * packet:   pkt_ov021_0218E674
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_CAMERA_CalcAngles  0x0218E610  thumb
 */
#include "../include/Obj01848.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void FIELD_CAMERA_CalcAngles(void *a, u16 *b, u16 *c, int *d);

void FIELD_CAMERA_SetAnglesFromVector(u8 *a, u32 b)
{
    struct { u16 y, x; u32 z; } t;
    FIELD_CAMERA_CalcAngles((void *)b, &t.x, &t.y, (int *)(&t.z));
    ((struct Obj01848 *)a)->f78 = t.x;
    ((struct Obj01848 *)a)->f7A = t.y;
    ((struct Obj01848 *)a)->f7C = t.z;
}
