/*
 * function: FIELD_RAIL_CAMERA_BlendAnglesAtCentre
 * address:  0x021BA4C4
 * packet:   pkt_ov021_021BA4C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   FIELD_RAIL_GetFocusWork  0x021B8220  thumb  ov021
 *   FIELD_RAIL_GetFieldCamera  0x021B821C  thumb  ov021
 *   FIELD_RAIL_CAMERA_BlendAngles  0x021BA348  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_RAIL_WORK_GetCentrePos  0x021B8314  thumb  ov021
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

u32 FIELD_RAIL_GetFocusWork(u8 *p);
u32 FIELD_RAIL_GetFieldCamera(u8 *p);
void FIELD_RAIL_CAMERA_BlendAngles(u32 p);
void FIELD_CAMERA_StopTargetTrace(u8 *p);
void FIELD_RAIL_WORK_GetCentrePos(u32 a, V *v);
void FIELD_CAMERA_SetTarget(u32 a, V *v);

void FIELD_RAIL_CAMERA_BlendAnglesAtCentre(u8 *p)
{
    V v;
    u32 q;
    u32 o;

    q = FIELD_RAIL_GetFocusWork(p);
    o = FIELD_RAIL_GetFieldCamera(p);
    FIELD_RAIL_CAMERA_BlendAngles((u32)p);
    FIELD_CAMERA_StopTargetTrace((u8 *)o);
    FIELD_RAIL_WORK_GetCentrePos(q, &v);
    FIELD_CAMERA_SetTarget(o, &v);
}
