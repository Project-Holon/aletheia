/*
 * function: FIELD_RAIL_CAMERA_FollowHeading
 * address:  0x021BAA30
 * packet:   pkt_ov021_021BAA30
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
 *   FIELD_CAMERA_ResumeTargetTrace  0x0218EC60  thumb  ov021
 *   FIELD_RAIL_WORK_GetStepVector  0x021B8050  thumb  ov021
 *   func_0207CFB8  0x0207CFB8  arm
 *   FIELD_CAMERA_SetPitch  0x0218ED34  thumb  ov021
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb  ov021
 *   FIELD_CAMERA_SetYaw  0x0218ED48  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09638.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

u32 FIELD_RAIL_GetFocusWork(u8 *p);
u8 *FIELD_RAIL_WORK_GetCamera(void);
u32 FIELD_RAIL_GetFieldCamera(u8 *p);
struct Sub;
void FIELD_CAMERA_EnterMode(u8 *a, u32 s);
int FIELD_CAMERA_ResumeTargetTrace(u32 a);
void FIELD_RAIL_WORK_GetStepVector(struct Sub *o, s16 *out);
int func_0207CFB8(int a, int b);
void FIELD_CAMERA_SetPitch(u8 *p, u16 v);
void FIELD_CAMERA_SetDistance(u8 *p, u32 v);
void FIELD_CAMERA_SetYaw(u8 *p, u32 v);

void FIELD_RAIL_CAMERA_FollowHeading(u8 *p)
{
    s16 v[4];
    u8 *q;
    u32 a;
    u32 o;
    int h;

    a = FIELD_RAIL_GetFocusWork(p);
    q = FIELD_RAIL_WORK_GetCamera();
    o = FIELD_RAIL_GetFieldCamera(p);
    FIELD_CAMERA_EnterMode((u8 *)o, 0);
    FIELD_CAMERA_ResumeTargetTrace(FIELD_RAIL_GetFieldCamera(p));
    FIELD_RAIL_WORK_GetStepVector((struct Sub *)a, v);
    h = func_0207CFB8(-v[0], -v[2]);
    FIELD_CAMERA_SetPitch((u8 *)o, ((struct Obj09638 *)q)->f8);
    FIELD_CAMERA_SetDistance((u8 *)o, ((struct Obj09638 *)q)->fC);
    FIELD_CAMERA_SetYaw((u8 *)o, (u16)(h + ((struct Obj09638 *)q)->f4));
}
