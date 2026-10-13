/*
 * function: FIELD_RAIL_CAMERA_FixedEyeTarget
 * address:  0x021BA4FC
 * packet:   pkt_ov021_021BA4FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_RAIL_GetFocusWork  0x021B8220  thumb  ov021
 *   FIELD_RAIL_WORK_GetCamera  0x021B830C  thumb  ov021
 *   FIELD_RAIL_GetFieldCamera  0x021B821C  thumb  ov021
 *   FIELD_CAMERA_EnterMode  0x0218E124  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_SetEyeRaw  0x0218ECF4  thumb  ov021
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05053.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

u32 FIELD_RAIL_GetFocusWork(u8 *p);
u8 *FIELD_RAIL_WORK_GetCamera(void);
u32 FIELD_RAIL_GetFieldCamera(u8 *p);
void FIELD_CAMERA_EnterMode(u8 *a, u32 s);
void FIELD_CAMERA_StopTargetTrace(u8 *p);
void FIELD_CAMERA_SetEyeRaw(u32 a, V *v);
void FIELD_CAMERA_SetTarget(u32 a, V *v);

void FIELD_RAIL_CAMERA_FixedEyeTarget(u8 *p)
{
    V a;
    V b;
    u8 *q;
    u32 o;

    FIELD_RAIL_GetFocusWork(p);
    q = FIELD_RAIL_WORK_GetCamera();
    o = FIELD_RAIL_GetFieldCamera(p);
    FIELD_CAMERA_EnterMode((u8 *)o, 2);
    FIELD_CAMERA_StopTargetTrace((u8 *)FIELD_RAIL_GetFieldCamera(p));
    a.x = ((struct Obj05053 *)q)->f4;
    a.y = ((struct Obj05053 *)q)->f8;
    a.z = ((struct Obj05053 *)q)->fC;
    b.x = ((struct Obj05053 *)q)->f10;
    b.y = ((struct Obj05053 *)q)->f14;
    b.z = ((struct Obj05053 *)q)->f18;
    FIELD_CAMERA_SetEyeRaw(o, &a);
    FIELD_CAMERA_SetTarget(o, &b);
}
