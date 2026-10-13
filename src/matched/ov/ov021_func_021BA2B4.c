/*
 * function: FIELD_RAIL_CAMERA_FixedAngle
 * address:  0x021BA2B4
 * packet:   pkt_ov021_021BA2B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   FIELD_RAIL_GetFocusWork  0x021B8220  thumb  ov021
 *   FIELD_RAIL_WORK_GetCamera  0x021B830C  thumb  ov021
 *   FIELD_RAIL_GetFocusPos  0x021B79D4  thumb  ov021
 *   FIELD_RAIL_GetFieldCamera  0x021B821C  thumb  ov021
 *   FIELD_CAMERA_EnterMode  0x0218E124  thumb  ov021
 *   FIELD_CAMERA_ResumeTargetTrace  0x0218EC60  thumb  ov021
 *   FIELD_CAMERA_SetYaw  0x0218ED48  thumb  ov021
 *   FIELD_CAMERA_SetPitch  0x0218ED34  thumb  ov021
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09635.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

u32 FIELD_RAIL_GetFocusWork(u8 *p);
u8 *FIELD_RAIL_WORK_GetCamera(void);
void FIELD_RAIL_GetFocusPos(void **o, void *out);
u32 FIELD_RAIL_GetFieldCamera(u8 *p);
void FIELD_CAMERA_EnterMode(u8 *a, u32 s);
int FIELD_CAMERA_ResumeTargetTrace(u32 a);
void FIELD_CAMERA_SetYaw(u8 *p, u32 v);
void FIELD_CAMERA_SetPitch(u8 *p, u16 v);
void FIELD_CAMERA_SetDistance(u8 *p, u32 v);

void FIELD_RAIL_CAMERA_FixedAngle(u8 *p)
{
    V v;
    u8 *q;
    u32 o;
    u16 x, y;
    u32 z;

    o = FIELD_RAIL_GetFieldCamera(p);
    FIELD_RAIL_GetFocusWork(p);
    q = FIELD_RAIL_WORK_GetCamera();
    FIELD_CAMERA_EnterMode((u8 *)o, 0);
    FIELD_CAMERA_ResumeTargetTrace(FIELD_RAIL_GetFieldCamera(p));
    FIELD_RAIL_GetFocusPos((void **)p, &v);
    x = ((struct Obj09635 *)q)->f4;
    y = ((struct Obj09635 *)q)->f8;
    z = ((struct Obj09635 *)q)->fC;
    FIELD_CAMERA_SetYaw((u8 *)o, y);
    FIELD_CAMERA_SetPitch((u8 *)o, x);
    FIELD_CAMERA_SetDistance((u8 *)o, z);
}
