/*
 * function: FIELD_CAMERA_ANIME_ApplyStartParam
 * address:  0x0218FEC0
 * packet:   pkt_ov021_0218FEC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_CAMERA_ANIME_GetCamera  0x021901E4  thumb  ov021
 *   FIELD_CAMERA_ANIME_GetData  0x021901E8  thumb  ov021
 *   FIELD_CAMERA_SetPitch  0x0218ED34  thumb  ov021
 *   FIELD_CAMERA_SetYaw  0x0218ED48  thumb  ov021
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb  ov021
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 *   FIELD_CAMERA_SetTargetShift  0x0218ECD4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09470.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_CAMERA_ANIME_GetCamera(u8 *p);
extern u32 FIELD_CAMERA_ANIME_GetData(u8 *p);
extern void FIELD_CAMERA_SetPitch(u8 *p, u16 v);
extern void FIELD_CAMERA_SetYaw(u8 *p, u32 v);
extern void FIELD_CAMERA_SetDistance(u8 *p, u32 v);
extern void FIELD_CAMERA_SetTarget(u8 *p, u8 *v);
extern void FIELD_CAMERA_SetTargetShift(u8 *p, u8 *v);

void FIELD_CAMERA_ANIME_ApplyStartParam(u8 *o)
{
    u8 *a = (u8 *)FIELD_CAMERA_ANIME_GetCamera(o);
    u8 *b = (u8 *)(FIELD_CAMERA_ANIME_GetData(o) + 4);
    FIELD_CAMERA_SetPitch(a, ((struct Obj09470 *)b)->f0);
    FIELD_CAMERA_SetYaw(a, ((struct Obj09470 *)b)->f2);
    FIELD_CAMERA_SetDistance(a, ((struct Obj09470 *)b)->f4);
    FIELD_CAMERA_SetTarget(a, b + 8);
    FIELD_CAMERA_SetTargetShift(a, b + 0x14);
}
