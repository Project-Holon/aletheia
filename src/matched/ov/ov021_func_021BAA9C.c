/*
 * function: FIELD_RAIL_CAMERA_FollowHeadingSlope
 * address:  0x021BAA9C
 * packet:   pkt_ov021_021BAA9C
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
 *   FIELD_CAMERA_ResumeTargetTrace  0x0218EC60  thumb  ov021
 *   FIELD_RAIL_WORK_GetStepVector  0x021B8050  thumb  ov021
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_0207CC30  0x0207CC30  arm
 *   FIELD_CAMERA_SetPitch  0x0218ED34  thumb  ov021
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb  ov021
 *   FIELD_CAMERA_SetYaw  0x0218ED48  thumb  ov021
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
extern int FIELD_CAMERA_ResumeTargetTrace(u32 a);
extern void FIELD_RAIL_WORK_GetStepVector(struct Sub *o, s16 *out);
extern int func_0207CFB8(int, int);
extern int func_0207CC30(s16 *);
extern void FIELD_CAMERA_SetPitch(u8 *p, u16 v);
extern void FIELD_CAMERA_SetDistance(u8 *p, u32 v);
extern void FIELD_CAMERA_SetYaw(u8 *p, u32 v);

void FIELD_RAIL_CAMERA_FollowHeadingSlope(u32 a)
{
    s16 b[6];
    u32 t, h;
    u32 *r;
    int x, y;

    t = FIELD_RAIL_GetFocusWork((u8 *)a);
    r = FIELD_RAIL_WORK_GetCamera(t);
    h = FIELD_RAIL_GetFieldCamera((u8 *)a);
    FIELD_CAMERA_EnterMode((u8 *)h, 0);
    FIELD_CAMERA_ResumeTargetTrace(FIELD_RAIL_GetFieldCamera((u8 *)a));
    FIELD_RAIL_WORK_GetStepVector((struct Sub *)t, &b[3]);
    x = func_0207CFB8(-b[3], -b[5]);
    b[0] = b[3];
    b[2] = b[5];
    b[1] = 0;
    y = func_0207CFB8(-b[4], func_0207CC30(b));
    FIELD_CAMERA_SetPitch((u8 *)h, y + r[2]);
    FIELD_CAMERA_SetDistance((u8 *)h, r[3]);
    FIELD_CAMERA_SetYaw((u8 *)h, (u16)(x + r[1]));
}
