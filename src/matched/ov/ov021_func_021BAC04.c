/*
 * function: FIELD_RAIL_CAMERA_FixedAngleShift
 * address:  0x021BAC04
 * packet:   pkt_ov021_021BAC04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_RAIL_GetFieldCamera  0x021B821C  thumb  ov021
 *   FIELD_RAIL_GetFocusWork  0x021B8220  thumb  ov021
 *   FIELD_RAIL_WORK_GetCamera  0x021B830C  thumb  ov021
 *   FIELD_CAMERA_EnterMode  0x0218E124  thumb  ov021
 *   FIELD_CAMERA_ResumeTargetTrace  0x0218EC60  thumb  ov021
 *   FIELD_RAIL_GetFocusPos  0x021B79D4  thumb  ov021
 *   FIELD_CAMERA_SetYaw  0x0218ED48  thumb  ov021
 *   FIELD_CAMERA_SetPitch  0x0218ED34  thumb  ov021
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb  ov021
 *   FIELD_CAMERA_SetTargetShift  0x0218ECD4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef unsigned char  u8;
extern u32 FIELD_RAIL_GetFieldCamera(u8 *p);
extern u32 FIELD_RAIL_GetFocusWork(u8 *p);
extern u32 *FIELD_RAIL_WORK_GetCamera(u32);
extern void FIELD_CAMERA_EnterMode(u8 *a, u32 s);
extern int FIELD_CAMERA_ResumeTargetTrace(u32 a);
extern void FIELD_RAIL_GetFocusPos(void **o, void *out);
extern void FIELD_CAMERA_SetYaw(u8 *p, u32 v);
extern void FIELD_CAMERA_SetPitch(u8 *p, u16 v);
extern void FIELD_CAMERA_SetDistance(u8 *p, u32 v);
extern void FIELD_CAMERA_SetTargetShift(u32, u32 *);

void FIELD_RAIL_CAMERA_FixedAngleShift(u32 a)
{
    u32 loc[3];
    u32 s[3];
    u32 h;
    u32 *r;
    u16 x, y;
    u32 z;

    h = FIELD_RAIL_GetFieldCamera((u8 *)a);
    r = FIELD_RAIL_WORK_GetCamera(FIELD_RAIL_GetFocusWork((u8 *)a));
    FIELD_CAMERA_EnterMode((u8 *)h, 0);
    FIELD_CAMERA_ResumeTargetTrace(FIELD_RAIL_GetFieldCamera((u8 *)a));
    FIELD_RAIL_GetFocusPos((void **)a, loc);
    x = r[1];
    y = r[2];
    z = r[3];
    FIELD_CAMERA_SetYaw((u8 *)h, y);
    FIELD_CAMERA_SetPitch((u8 *)h, x);
    FIELD_CAMERA_SetDistance((u8 *)h, z);
    s[0] = r[4];
    s[1] = r[5];
    s[2] = r[6];
    FIELD_CAMERA_SetTargetShift(h, s);
}
