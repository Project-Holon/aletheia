/*
 * function: FIELD_RAIL_CAMERA_FixedAngleAtCentre
 * address:  0x021BA310
 * packet:   pkt_ov021_021BA310
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_RAIL_GetFocusWork  0x021B8220  thumb  ov021
 *   FIELD_RAIL_GetFieldCamera  0x021B821C  thumb  ov021
 *   FIELD_RAIL_CAMERA_FixedAngle  0x021BA2B4  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_RAIL_WORK_GetCentrePos  0x021B8314  thumb  ov021
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 */

typedef unsigned int   u32;
extern u32 FIELD_RAIL_GetFocusWork(unsigned char *p);
extern u32 FIELD_RAIL_GetFieldCamera(unsigned char *p);
typedef unsigned char  u8;
extern void FIELD_RAIL_CAMERA_FixedAngle(u8 *p);
extern void FIELD_CAMERA_StopTargetTrace(u8 *p);
extern void FIELD_RAIL_WORK_GetCentrePos(void *p, void *buf);
extern void FIELD_CAMERA_SetTarget(void *p, void *buf);

void FIELD_RAIL_CAMERA_FixedAngleAtCentre(void *p)
{
    void *a;
    void *b;
    int buf[3];

    a = (void *)FIELD_RAIL_GetFocusWork(p);
    b = (void *)FIELD_RAIL_GetFieldCamera(p);
    FIELD_RAIL_CAMERA_FixedAngle(p);
    FIELD_CAMERA_StopTargetTrace(b);
    FIELD_RAIL_WORK_GetCentrePos(a, buf);
    FIELD_CAMERA_SetTarget(b, buf);
}
