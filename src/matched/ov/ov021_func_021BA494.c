/*
 * function: FIELD_RAIL_CAMERA_BlendAnglesAtFocus
 * address:  0x021BA494
 * packet:   pkt_ov021_021BA494
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_RAIL_GetFieldCamera  0x021B821C  thumb  ov021
 *   FIELD_RAIL_CAMERA_BlendAngles  0x021BA348  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_RAIL_GetFocusPos  0x021B79D4  thumb  ov021
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 */

typedef unsigned int   u32;

typedef unsigned char  u8;
extern u32 FIELD_RAIL_GetFieldCamera(u8 *p);
extern void FIELD_RAIL_CAMERA_BlendAngles(u32);
extern void FIELD_CAMERA_StopTargetTrace(u8 *p);
extern void FIELD_RAIL_GetFocusPos(void **o, void *out);
extern void FIELD_CAMERA_SetTarget(u32, u32 *);

void FIELD_RAIL_CAMERA_BlendAnglesAtFocus(u32 a)
{
    u32 h = FIELD_RAIL_GetFieldCamera((u8 *)a);
    u32 v[3];

    FIELD_RAIL_CAMERA_BlendAngles(a);
    FIELD_CAMERA_StopTargetTrace((u8 *)h);
    FIELD_RAIL_GetFocusPos((void **)a, v);
    FIELD_CAMERA_SetTarget(h, v);
}
