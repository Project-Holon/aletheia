/*
 * function: FIELD_RAIL_CAMERA_FollowHeadingAtCentre
 * address:  0x021BAB30
 * packet:   pkt_ov021_021BAB30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_RAIL_GetFocusWork  0x021B8220  thumb  ov021
 *   FIELD_RAIL_WORK_GetCamera  0x021B830C  thumb  ov021
 *   FIELD_RAIL_GetFieldCamera  0x021B821C  thumb  ov021
 *   FIELD_CAMERA_EnterMode  0x0218E124  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_RAIL_WORK_GetStepVector  0x021B8050  thumb  ov021
 *   func_0207CFB8  0x0207CFB8  arm
 *   FIELD_CAMERA_SetPitch  0x0218ED34  thumb  ov021
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb  ov021
 *   FIELD_CAMERA_SetYaw  0x0218ED48  thumb  ov021
 *   FIELD_RAIL_WORK_GetCentrePos  0x021B8314  thumb  ov021
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;

typedef unsigned char  u8;
struct Sub;
extern u32 FIELD_RAIL_GetFocusWork(u8 *p);
extern u32 *FIELD_RAIL_WORK_GetCamera(u32);
extern u32 FIELD_RAIL_GetFieldCamera(u8 *p);
extern void FIELD_CAMERA_EnterMode(u8 *a, u32 s);
extern void FIELD_CAMERA_StopTargetTrace(u8 *p);
extern void FIELD_RAIL_WORK_GetStepVector(struct Sub *o, s16 *out);
extern int func_0207CFB8(int, int);
extern void FIELD_CAMERA_SetPitch(u8 *p, u16 v);
extern void FIELD_CAMERA_SetDistance(u8 *p, u32 v);
extern void FIELD_CAMERA_SetYaw(u8 *p, u32 v);
extern void FIELD_RAIL_WORK_GetCentrePos(u32, u32 *);
extern void FIELD_CAMERA_SetTarget(u32, u32 *);

void FIELD_RAIL_CAMERA_FollowHeadingAtCentre(u32 a)
{
    s16 v[4];
    u32 loc[3];
    u32 t, h;
    u32 *r;
    int ang;

    t = FIELD_RAIL_GetFocusWork((u8 *)a);
    r = FIELD_RAIL_WORK_GetCamera(t);
    h = FIELD_RAIL_GetFieldCamera((u8 *)a);
    FIELD_CAMERA_EnterMode((u8 *)h, 0);
    FIELD_CAMERA_StopTargetTrace((u8 *)FIELD_RAIL_GetFieldCamera((u8 *)a));
    FIELD_RAIL_WORK_GetStepVector((struct Sub *)t, v);
    ang = func_0207CFB8(-v[0], -v[2]);
    FIELD_CAMERA_SetPitch((u8 *)h, r[2]);
    FIELD_CAMERA_SetDistance((u8 *)h, r[3]);
    FIELD_CAMERA_SetYaw((u8 *)h, (u16)(ang + r[1]));
    FIELD_RAIL_WORK_GetCentrePos(t, loc);
    FIELD_CAMERA_SetTarget(FIELD_RAIL_GetFieldCamera((u8 *)a), loc);
}
