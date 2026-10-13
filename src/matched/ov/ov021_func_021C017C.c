/*
 * function: EVENT_DISAPPEAR_StartZoomIn
 * address:  0x021C017C
 * packet:   pkt_ov021_021C017C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_ANIME_Create  0x0218FE80  thumb  ov021
 *   FIELD_CAMERA_ANIME_SetData  0x0218FEA0  thumb  ov021
 *   FIELD_CAMERA_ANIME_Setup  0x0218FEA4  thumb  ov021
 *   FIELD_CAMERA_ANIME_GetCurrentParam  0x0218FE78  thumb  ov021
 *   FIELD_CAMERA_ANIME_ApplyStartParam  0x0218FEC0  thumb  ov021
 *   FIELD_CAMERA_ANIME_Start  0x0218FF00  thumb  ov021
 */
#include "../include/Obj02723.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct { u32 w[8]; } Blk32;

extern void *FIELDMAP_GetCamera(void *p);
extern void *FIELD_CAMERA_ANIME_Create(void *a);
extern void FIELD_CAMERA_ANIME_SetData(u8 *p, u32 v);
extern void FIELD_CAMERA_ANIME_Setup(u32 a);
extern void FIELD_CAMERA_ANIME_GetCurrentParam(u32 a, u8 *b);
extern void FIELD_CAMERA_ANIME_ApplyStartParam(u8 *o);
extern int FIELD_CAMERA_ANIME_Start(u32 a);

void EVENT_DISAPPEAR_StartZoomIn(u8 *p)
{
    u32 a;
    u32 b;

    a = (u32)FIELDMAP_GetCamera((void *)(((struct Obj02723 *)p)->f4));
    b = (u32)FIELD_CAMERA_ANIME_Create((void *)(((struct Obj02723 *)p)->f4));
    ((struct Obj02723 *)p)->f24 = 0x3c;
    ((struct Obj02723 *)p)->f68 = 1;
    ((struct Obj02723 *)p)->f6C = 1;
    ((struct Obj02723 *)p)->f70 = b;
    FIELD_CAMERA_ANIME_SetData((u8 *)b, (u32)(p + 0x24));
    FIELD_CAMERA_ANIME_Setup(((struct Obj02723 *)p)->f70);
    FIELD_CAMERA_ANIME_GetCurrentParam(a, p + 0x28);
    *(Blk32 *)(p + 0x48) = *(Blk32 *)(p + 0x28);
    ((struct Obj02723 *)p)->f4C -= 0x64000;
    FIELD_CAMERA_ANIME_ApplyStartParam((u8 *)(((struct Obj02723 *)p)->f70));
    FIELD_CAMERA_ANIME_Start(((struct Obj02723 *)p)->f70);
}
