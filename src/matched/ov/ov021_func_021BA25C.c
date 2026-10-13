/*
 * function: FIELD_RAIL_CAMERA_EyeOffsetFromFocus
 * address:  0x021BA25C
 * packet:   pkt_ov021_021BA25C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_RAIL_GetFocusWork  0x021B8220  thumb  ov021
 *   FIELD_RAIL_WORK_GetCamera  0x021B830C  thumb  ov021
 *   FIELD_RAIL_GetFocusPos  0x021B79D4  thumb  ov021
 *   FIELD_RAIL_GetFieldCamera  0x021B821C  thumb  ov021
 *   FIELD_CAMERA_EnterMode  0x0218E124  thumb  ov021
 *   FIELD_CAMERA_SetEyeRaw  0x0218ECF4  thumb  ov021
 *   FIELD_CAMERA_ResumeTargetTrace  0x0218EC60  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09634.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

u32 FIELD_RAIL_GetFocusWork(u8 *p);
u8 *FIELD_RAIL_WORK_GetCamera(void);
void FIELD_RAIL_GetFocusPos(void **o, void *out);
u32 FIELD_RAIL_GetFieldCamera(u8 *p);
void FIELD_CAMERA_EnterMode(u8 *a, u32 s);
void FIELD_CAMERA_SetEyeRaw(u32 a, V *v);
int FIELD_CAMERA_ResumeTargetTrace(u32 a);

void FIELD_RAIL_CAMERA_EyeOffsetFromFocus(u8 *p)
{
    V v;
    u8 *q;

    FIELD_RAIL_GetFocusWork(p);
    q = FIELD_RAIL_WORK_GetCamera();
    FIELD_RAIL_GetFocusPos((void **)p, &v);
    FIELD_CAMERA_EnterMode((u8 *)FIELD_RAIL_GetFieldCamera(p), 2);
    v.x += ((struct Obj09634 *)q)->f4;
    v.y += ((struct Obj09634 *)q)->f8;
    v.z += ((struct Obj09634 *)q)->fC;
    FIELD_CAMERA_SetEyeRaw(FIELD_RAIL_GetFieldCamera(p), &v);
    FIELD_CAMERA_ResumeTargetTrace(FIELD_RAIL_GetFieldCamera(p));
}
