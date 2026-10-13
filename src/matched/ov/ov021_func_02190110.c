/*
 * function: FIELD_CAMERA_ANIME_ApplyEndParam
 * address:  0x02190110
 * packet:   pkt_ov021_02190110
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_CAMERA_ANIME_GetData  0x021901E8  thumb
 *   FIELD_CAMERA_SetPitch  0x0218ED34  thumb
 *   FIELD_CAMERA_SetYaw  0x0218ED48  thumb
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb
 *   FIELD_CAMERA_SetTargetShift  0x0218ECD4  thumb
 */
#include "../include/Obj19579.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { u32 a, b, c; } Vec3;

typedef struct {
    u16 h0;
    u16 h2;
    u32 w4;
    Vec3 v8;
    Vec3 v14;
} Params;

extern u32 FIELD_CAMERA_ANIME_GetData(u8 *p);
extern void FIELD_CAMERA_SetPitch(u8 *p, u16 v);
extern void FIELD_CAMERA_SetYaw(u8 *p, u32 v);
extern void FIELD_CAMERA_SetDistance(u8 *p, u32 v);
extern void FIELD_CAMERA_SetTarget(void *a, const Vec3 *p);
extern void FIELD_CAMERA_SetTargetShift(void *a, const Vec3 *p);

void FIELD_CAMERA_ANIME_ApplyEndParam(u8 *a)
{
    void *x = ((struct Obj19579 *)a)->f4;
    Params *p = (Params *)(FIELD_CAMERA_ANIME_GetData(a) + 0x24);
    FIELD_CAMERA_SetPitch(x, p->h0);
    FIELD_CAMERA_SetYaw(x, p->h2);
    FIELD_CAMERA_SetDistance(x, p->w4);
    FIELD_CAMERA_SetTarget(x, &p->v8);
    FIELD_CAMERA_SetTargetShift(x, &p->v14);
}
