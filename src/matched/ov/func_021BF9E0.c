/*
 * function: EVENT_APPEAR_EndZoomOutAlt
 * address:  0x021BF9E0
 * packet:   pkt_021BF9E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_CAMERA_ANIME_Restore  0x0218FF20  thumb  ov021
 *   FIELD_CAMERA_ANIME_Delete  0x0218FE98  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12122.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_CAMERA_ANIME_Delete(u32);
extern void FIELD_CAMERA_ANIME_Restore(u8 *a);

int EVENT_APPEAR_EndZoomOutAlt(void **a)
{
FIELD_CAMERA_ANIME_Restore((u8 *)(((struct Obj12122 *)((u8 *)(a)))->f58));
return FIELD_CAMERA_ANIME_Delete(((struct Obj12122 *)((u8 *)(a)))->f58);
}

