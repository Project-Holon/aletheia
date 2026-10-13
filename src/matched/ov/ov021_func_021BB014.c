/*
 * function: FIELD_RAIL_CAMERA_ApplyPoint
 * address:  0x021BB014
 * packet:   pkt_ov021_021BB014
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_RAIL_WORK_GetStartPoint  0x021B833C  thumb  ov021
 *   FIELD_RAIL_WORK_GetLineEndOffset  0x021B82FC  thumb  ov021
 *   FIELD_RAIL_WORK_GetPosAtLineOffset  0x021B8328  thumb  ov021
 *   FIELD_RAIL_WORK_GetPointCamera  0x021B836C  thumb  ov021
 *   FIELD_RAIL_GetFieldCamera  0x021B821C  thumb  ov021
 *   FIELD_CAMERA_EnterMode  0x0218E124  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 *   FIELD_CAMERA_SetPitch  0x0218ED34  thumb  ov021
 *   FIELD_CAMERA_SetYaw  0x0218ED48  thumb  ov021
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern unsigned char *FIELD_RAIL_WORK_GetStartPoint(unsigned char *p);
typedef unsigned char  u8;
extern u32 FIELD_RAIL_WORK_GetLineEndOffset(u8 *p);
extern void FIELD_RAIL_WORK_GetPosAtLineOffset(u32, u32, u32 *);
extern u32 *FIELD_RAIL_WORK_GetPointCamera(u32, u32);
extern u32 FIELD_RAIL_GetFieldCamera(u8 *p);
extern void FIELD_CAMERA_EnterMode(u8 *a, u32 s);
extern void FIELD_CAMERA_StopTargetTrace(u8 *p);
extern void FIELD_CAMERA_SetTarget(u32, u32 *);
extern void FIELD_CAMERA_SetPitch(u8 *p, u16 v);
extern void FIELD_CAMERA_SetYaw(u8 *p, u32 v);
extern void FIELD_CAMERA_SetDistance(u8 *p, u32 v);

void FIELD_RAIL_CAMERA_ApplyPoint(u32 a, unsigned char *b, u32 c)
{
    u32 loc[3];
    u32 x;
    u32 *r;
    u32 h;
    u32 k;

    k = (u32)FIELD_RAIL_WORK_GetStartPoint(b);
    if (k == c)
        x = 0;
    else
        x = FIELD_RAIL_WORK_GetLineEndOffset((u8 *)b);
    FIELD_RAIL_WORK_GetPosAtLineOffset((u32)b, x, loc);
    r = FIELD_RAIL_WORK_GetPointCamera((u32)b, c);
    h = FIELD_RAIL_GetFieldCamera((u8 *)a);
    FIELD_CAMERA_EnterMode((u8 *)h, 0);
    FIELD_CAMERA_StopTargetTrace((u8 *)h);
    FIELD_CAMERA_SetTarget(h, loc);
    FIELD_CAMERA_SetPitch((u8 *)h, r[1]);
    FIELD_CAMERA_SetYaw((u8 *)h, (u16)r[2]);
    FIELD_CAMERA_SetDistance((u8 *)h, r[3]);
}
